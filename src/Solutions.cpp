#include "Solutions.hpp"
#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>
#include <iostream>

auto solution::canPartitionKSubsets(std::vector<int>& nums, int k) -> bool {
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    auto target = sum / k;
    std::sort(nums.begin(), nums.end());
    if (nums.back() > target) return false;

    auto n = nums.size();
    std::vector<int> visited(1 << n, 0);
    visited[0] = 1;
    std::vector<int> curr_sum(1 << n, 0);

    for (int mask = 0; mask < (1 << n); ++mask) {
        if (not visited[mask]) continue;
        for (int i = 0; i < n; ++i) {
            if (curr_sum[mask] + nums[i] > target) break;
            if ((mask >> i & 1) == 0) {
                auto next = mask | (1 << i);
                if (not visited[next]) {
                    curr_sum[next] = (curr_sum[mask] + nums[i]) % target;
                    visited[next] = 1;
                }
            } 
        }
    }
    return visited[(1 << n) - 1];
}

auto dfs(std::vector<int>& nums, std::vector<int> map, int i, int target) -> bool {
    auto n = nums.size();
    if (i == n) return true;
    for (int j = 0; j < n; ++j) {
        if ( j and map[j] == map[j - 1]) continue;
        map[j] += nums[i];
        if (map[j] <= target and dfs(nums, map, i + 1, target)) return true;
        map[j] -= nums[i];
    }
    return false;
}

auto solution::canPartitionKSubsetsDFS(std::vector<int>& nums, int k) -> bool {
    auto target = std::accumulate(nums.begin(), nums.end(), 0);
    if (target % k != 0) return false;
    target /= k;
    std::sort(nums.begin(), nums.end());
    if (nums.back() > target) return false;
    std::vector<int> map(k, 0);
    return dfs(nums, map, 0, target);
}

auto maxConsecutice(char c, int k, std::string& answerKey) -> int {
    auto res = 0;
    auto left = 0;
    auto cnt = 0;

    for (auto right = 0; right < answerKey.size(); ++right) {
        cnt += answerKey[right] != c;
        while (cnt > k) {
            cnt -= answerKey[left] != c;
            ++left;
        }
        res = std::max(res, right - left + 1);
    }
    return res;
}

auto solution::maxConsecutiveAnswers(std::string& answerKey, int k) -> int {
    return std::max(maxConsecutice('T', k, answerKey), maxConsecutice('F', k, answerKey));
}

auto subsets(std::vector<int>& nums) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> res = {{}};
    if (nums.empty()) return res;
    std::vector<int> subset;
    auto first = nums[0];
    auto rest = std::vector<int>(nums.begin() + 1, nums.end());
    auto without_first = subsets(rest);
    std::vector<std::vector<int>> with_first;
    for (auto& s : without_first) {
        auto t = s;
        t.push_back(first);
        with_first.push_back(t);
    }
    res.insert(res.end(), with_first.begin(), with_first.end());
    res.insert(res.end(), without_first.begin(), without_first.end());
    return res;
}

auto solution::maxStrength(std::vector<int> &nums) -> long long {
    auto n = nums.size();
    auto temp = subsets(nums);
    std::vector<long long> res;
    long long max = LLONG_MIN;
    
    for (auto& t : temp) {
        if (t.empty()) continue;
        auto sum = std::accumulate(t.begin(), t.end(), 1LL, std::multiplies<long long>());
        res.push_back(sum);
    }

    std::sort(res.begin(), res.end());
    max = res.back();
    return max;    
}

auto solution::maxStrengthGreedy(std::vector<int> &nums) -> long long {
    std::sort(nums.begin(), nums.end());
    auto n = nums.size();
    long long res = 1;
    if (n == 1) return nums[0];
    if (nums[1] == nums.back() == 0) return 0;
    auto i = 0;
    while (i < n) {
        if (nums[i] < 0 and i + 1< n and nums[i + 1] < 0) {
            res *= nums[i] * nums[i + 1];
            i += 2;
        } else if (nums[i] < 0) {
            res *= nums[i];
            ++i;
        } else {
            res *= nums[i];
            ++i;
        }
    }
    return res;
}

auto solution::minAdd(std::string word) -> int {
    auto n = word.size();
    std::vector<int> dp(n + 1, 0);
    for (int i = 1; i < n+1; ++i) {
        dp[i] = dp[i-1] +2;
        if (i > 1 and word[i -1] > word [ i - 2]) {
            dp[i] = dp[i - 1] - 1;
        }
    }
    return dp[n];
}

auto solution::countWays(std::vector<int> &nums) -> int {
    auto n = nums.size();
    int ans = 0;
    std::sort(nums.begin(), nums.end());

    for (auto i = 0; i < n + 1; ++i){
        if (i > 0 and nums[i - 1] >= i) {
            continue;
        }
        if (i < n and nums[i] <= i) {
            continue;
        }
        ++ans;
    }
    return ans;
}