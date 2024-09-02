#include "Solutions.hpp"
#include <algorithm>
#include <numeric>
#include <vector>

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