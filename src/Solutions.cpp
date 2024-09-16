#include "Solutions.hpp"
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <numeric>
#include <optional>
#include <ostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

template<typename T>
auto creatLinkedList(const T& container) -> ListNode* {
    auto dummy = new ListNode();
    auto tail = dummy;

    for (const auto& val : container) {
        auto node = new ListNode(val);
        tail->next = node;
        tail = tail->next;
    }
    return dummy->next;
}


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

auto solution::clearDigits(std::string& s) -> std::string {
    std::vector<int> deleteIdx;
    auto n = s.size();
    std::vector<char> digit = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < n; ++i) {
        if (digit.end() != std::find(digit.begin(), digit.end(), s[i])) {
            auto temp = i - 1;
            while (deleteIdx.end() != std::find(deleteIdx.begin(), deleteIdx.end(), temp)) {
                --temp;
            }
            deleteIdx.push_back(temp);
            deleteIdx.push_back(i);
        }
    }
    std::string res;
    for (int i = 0; i < n; ++i) {
        if (deleteIdx.end() == std::find(deleteIdx.begin(), deleteIdx.end(), i)) {
            res += s[i];
        }
    }
    return res;
}

auto solution::clearDigits2(std::string& s) -> std::string {
    std::string res;
    for (const auto& c : s) {
        if (c >= '0' and c <= '9') {
            res.pop_back();
        }
        else {
            res.push_back(c);
        }
    }
    return res;
}

auto solution::maximumLength(std::vector<int>& nums, int k) -> int {
    auto n = nums.size();
    std::vector<std::vector<int>> dp;
    int res = 0;
    dp.resize(n, std::vector<int>(2 * k + 1, -1));

    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l < i; ++l) {
                auto ad = static_cast<int>(nums[i] != nums[l]);
                if (j - ad >= 0 and dp[l][j - ad] != -1) {
                    dp[i][j] = std::max(dp[i][j], dp[l][j - ad] + 1);
                }
            }
            res = std::max(res, dp[i][j]);
        }
    }
    return res;
}

auto solution::maximumLength2(std::vector<int>& nums, int k) -> int {
    auto n = nums.size();
    // std::vector<std::vector<int>> dp;
    std::unordered_map<int, std::vector<int>> dp;
    std::vector<int> sup(k + 1, 0);

    for (int i = 0; i < n; ++i) {
        int tmp = nums[i];
        if (not dp.count(tmp)) {
            dp[tmp] = std::vector<int>(k + 1, 0);
        }
        auto& temp = dp[tmp];
        for (int j = 0; j <= k; ++j) {
            temp[j] = temp[j] + 1;
            if (j > 0) {
                temp[j] = std::max(temp[j], sup[j - 1] + 1);
            }
        }
        for (int l = 0; l <= k; ++l) {
            sup[l] = std::max(sup[l], temp[l]);
        }
    }
    return sup[k];
}

auto solution::maximumLength3(std::vector<int>& nums, int k) -> int {
    auto n = nums.size();
    std::unordered_map<int, std::vector<int>> dp;
    std::vector<int> sup(k + 1, 0);

    for(int i = 0; i < n; ++i) {
        auto tmp = nums[i];
        if (not dp.count(tmp)) {
            dp[tmp] = std::vector<int>(k + 1, 0);
        }
        auto& temp = dp[tmp];
        for (int j = 0; j <= k; ++j) {
            temp[j] = temp[j] + 1;
            if (j > 0) {
                temp[j] = std::max(temp[j], sup[j - 1] + 1);
            }
        }
        for (int l = 0; l <= k; ++l) {
            sup[l] = std::max(sup[l], temp[l]);
        }
    }
    return sup[k];
}

auto solution::sortedSquares(std::vector<int>& nums) -> std::vector<int> {
    std::transform(nums.begin(), nums.end(), nums.begin(), [](int x) { return x * x; });
    std::sort(nums.begin(), nums.end());
    return nums;
}

auto solution::sortedSquaresPointers(std::vector<int>& nums) ->std::vector<int> {
    auto n  = nums.size();
    std::vector<int> res(n, 0);
    auto left = nums.begin();
    auto right = nums.end() - 1;
    auto i = n - 1;
    while (left <= right) {
        if (std::abs(*left) > std::abs(*right)) {
            res[i] = *left * *left;
            ++left;
        } else {
            res[i] = *right * *right;
            --right;
        }
        --i;
    }
    return res;
}

auto solution::mergeNodes(ListNode *head) -> ListNode* {
    auto dummy = new ListNode();
    auto tail = dummy;
    int ttl = 0;
    auto curr = head->next;

    while(curr) {
        if (curr->val == 0) {
            if (ttl != 0){
                auto node = new ListNode(ttl);
                tail->next = node;
                tail = tail->next;
                ttl = 0;
            }
        }
        else {
            ttl += curr->val;
        }
        curr = curr->next;
    }
    auto res = dummy->next;
    delete dummy;
    return res;
}

auto solution::climbStairs(int n) -> int {
    auto sqrt5 = std::sqrt(5);
    auto fib = std::pow((1 + sqrt5) / 2, n + 1) - std::pow((1 - sqrt5) / 2, n + 1);
    auto res = static_cast<int>(std::round(fib/sqrt5));
    return res;
}

auto solution::climbStairsDP(int n) -> int {
    if (n <= 1) {
        return 1;
    }
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (std::size_t i = 3; i < dp.size(); ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

auto solution::fib(int n) -> int {
    std::vector<int> dp(n + 2, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (std::size_t i = 3; i < dp.size(); ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];    
    }
    return dp[n];
}

auto solution::trib(int n) -> int {
    std::vector<int> dp(n + 3, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (std::size_t i = 3; i < dp.size(); ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

auto costs(std::vector<int> time, std::vector<int> cost, int k) -> long long {
    auto res = std::max(time.begin(),time.end()) + k * std::accumulate(cost.begin(), cost.end(), 0);
    return *res;
}

// WA
// auto solution::maximumRobots(std::vector<int> &chargeTimes, std::vector<int> &runningCosts, long long budget) -> std::vector<int> {
// // slide window
//     std::vector<int> rst;
//     for (int i = 0; i < chargeTimes.size(); ++i) {
//         for (int j = i; j < chargeTimes.size(); ++j) {
//             auto time = std::vector<int>(chargeTimes.begin() + i, chargeTimes.begin() + j + 1);
//             auto cost = std::vector<int>(runningCosts.begin() + i, runningCosts.begin() + j + 1);
//             auto res = costs(time, cost, j - i + 1);
//             if (res > budget) {
//                 rst.push_back(j - i);
//             }
//         }
//         // return rst;
//     }
//     return rst;
// }
auto solution::maximumRobots(std::vector<int> &chargeTimes, std::vector<int> &runningCosts, long long budget) -> int {
    int res = 0;
    auto n = chargeTimes.size();
    long long sum = 0;
    std::deque<int> q;

    for (int i = 0, j = 0; i < n; ++i) {
        sum += runningCosts[i];
        while (not q.empty() and chargeTimes[q.back()] <= chargeTimes[i]) {
            q.pop_back();
        }
        q.push_back(i);
        while (j <= i and (i - j + 1) * sum + chargeTimes[q.front()] > budget) {
            if (not q.empty() and q.front() == j)  {
                q.pop_front();
            }
            sum -= runningCosts[j];
            ++j;
        }
        res = std::max(res, i - j + 1);
    }
    return res;
}

auto solution::minCostClimbingStairs(std::vector<int> &cost) -> int {
    auto n = cost.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    int cst = 0;
    for (int i = 2; i < n; ++i) {
        cst = cost[i];
        dp[i] = std::min(dp[i - 1], dp[i - 2]) + cst;
    }
    return std::min(dp[n - 1], dp[n - 2]);
}

auto solution::rob(std::vector<int> &nums) -> int {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return std::max(nums[0], nums[1]);
    auto n = nums.size();
    std::vector<int> dp(n, 0);
    int res = 0;
    dp[0] = nums[0];
    dp[1] = nums[1];
    for (int i = 2; i < n; ++i) {
        dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);

    }
    return dp[n - 1];
}

auto solution::deleteAndEarn(std::vector<int> &nums) -> int {
    // auto n = nums.size();
    // if (n == 1) return nums[0];
    // if (n == 2 and std::abs(nums[0] - nums[1]) == 1) {
    //     return std::max(nums[0], nums[1]);
    // } 
    // else {
    //     return nums[0] + nums[1];
    // }

    // std::sort(nums.begin(), nums.end());
    // std::unordered_map<int, int> mp;
    // std::vector<int> dp(0, nums[0]);
    // mp[nums[0]] = 1;
    // for (int i = 0; i < dp.size(); ++i) {
    //     ++mp[nums[i]];
    //     if (nums[i] != dp.back()) {
    //         dp.push_back(nums[i]);
    //     }
    // }
    // int last = dp[1];
    //     dp[1] = dp[1] * mp[dp[1]];
    // for (int i = 2; i < dp.size(); ++i) {
    //     if (dp[i] - last == 1) {
    //         dp[i] = std::max(dp[i - 1], dp[i - 2] + dp[i] * mp[dp[i]]);
    //     }
    //     else {
    //         last = dp[i];
    //         dp[i] = dp[i - 1] + dp[i] * mp[dp[i]];
    //     }
    // }
    // return  dp[dp.size() - 1];
    std::unordered_map<int, int> mp;
    sort(nums.begin(), nums.end());
    std::vector<int> dp = {0, nums[0]};
    mp[nums[0]] = 1;
    for(int i = 1; i < nums.size(); ++i)
    {
        ++mp[nums[i]];
        if(nums[i] != dp.back())
            dp.push_back(nums[i]);
    }

    int last = dp[1];
    dp[1] = dp[1] * mp[dp[1]];
    for(int i = 2; i < dp.size(); ++i)
    {
        if(dp[i] - last == 1)
        {
            last = dp[i];
            dp[i] = std::max(dp[i-1], dp[i-2] + dp[i] * mp[dp[i]]);
        }
        else
        {
            last = dp[i];
            dp[i] = dp[i-1] + dp[i] * mp[dp[i]];
        }
    }

    return dp[dp.size() - 1];
}

auto solution::removeStars(std::string s) -> std::string {
    // std::string res;
    // for (const auto& c : s) {
    //     if (c != '*') {
    //         res.push_back(c);
    //     }
    //     else {
    //         res.pop_back();
    //     }
    // }
    // return res;
    std::vector<char> res;
    for (const auto& c : s) {
        if (c != '*') {
            res.push_back(c);
        }
        else {
            res.pop_back();
        }
    }
    return std::string(res.begin(), res.end());
}

auto solution::removeDuplicates(std::string s) -> std::string {
    std::vector<char> res;
    for (const auto& c : s) {
        if (res.empty() or res.back() != c) {
            res.push_back(c);
        }
        else {
            res.pop_back();
        }
    }
    return std::string(res.begin(), res.end());
}

auto solution::removeDuplicates2(std::string s, int k) -> std::string {
    // std::unordered_map<char, int> mp;
    // for (const auto& c : s) {
    //     ++mp[c];
        
    //     if (mp[c] == k) {
    //         mp[c] -= k;
    //     }
    // }

    // for (const auto& [key, value] : mp) {
    //     std::cout << key << " " << value << std::endl;
    // }

    // std::deque<char> res;
    // for (const auto& [key, value] : mp) {
    //     if (value != 0) {
    //         res.push_back(key * value);
    //     }
    // }
    // auto tmp = res.front();
    // res.pop_front();
    // res.push_back(tmp);
    // return std::string(res.begin(), res.end());
    std::stack<std::pair<char, int>> st;
    for (const auto& c : s) {
        if (st.empty() or st.top().first != c) {
            st.push(std::make_pair(c, 1));
        }
        else {
            ++st.top().second;
            if (st.top().second == k) {
                st.pop();
            }
        }
    }
    std::deque<char> res;
    while (not st.empty()) {
        auto [c, cnt] = st.top();
        st.pop();
        while (cnt--) {
            res.push_front(c);
        }
    }
    return std::string(res.begin(), res.end());
}

auto solution::replaceNonCoprimes(std::vector<int> &nums) -> std::vector<int> {
    // std::vector<int> res;
    // auto n = nums.size();
    // for (int i = 0; i < n; ++i) {
    //     if (std::gcd(nums[i], nums[i + 1]) != 1) {
    //         auto temp = std::lcm(nums[i], nums[i + 1]);
    //         res.push_back(temp);
    //         --i;    
    //     }
    //     else {
    //         res.push_back(nums[i]);
    //     }
    // }
    // return res;
    std::vector<int> res;
    for (const auto& num : nums) {
        res.push_back(num);
        while (res.size() > 1 and std::gcd(res.back(), res[res.size() - 2]) > 1) {
            int a = res.back();
            res.pop_back();
            int b = res.back();
            res.pop_back();
            res.push_back(std::lcm(a, b));
        }
    }
    return res;
}

auto solution::numberOfPoints(std::vector<std::vector<int>> &nums) -> int {
    auto n = nums.size();
    std::set<int> res;
    for (int i = 0; i < n; ++i) {
        for (int j = nums[i][0]; j < nums[i].back(); ++j) {
            res.insert(j);
        }
    }
    for (const auto& n : res) {
        std::cout << n << std::endl;
    }
    return res.size();
}
// 超过long long范围
auto solution::findValidSplit(std::vector<int> &nums) -> int {
    auto n = nums.size();
    for (int i = 0; i < n-2; ++i) {
        long long prefix_product = std::accumulate(nums.begin(), nums.begin() + i + 1, 1, std::multiplies<int>());
        long long suffix_product = std::accumulate(nums.begin() + i + 1, nums.end(), 1, std::multiplies<int>());
        if (std::gcd(prefix_product, suffix_product) == 1) {
            return i;
        }
    }
    return -1;
}