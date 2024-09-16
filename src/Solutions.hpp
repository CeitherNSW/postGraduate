#include <string>
#include <variant>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

template<typename T>
auto creatLinkedList(T) -> ListNode*;

class solution  {
 public:
    auto canPartitionKSubsets(std::vector<int>& nums, int k) -> bool;
    auto canPartitionKSubsetsDFS(std::vector<int>& nums, int k) -> bool;
    auto maxConsecutiveAnswers(std::string& answerKey, int k) -> int;
    auto maxStrength(std::vector<int>& nums) -> long long;
    auto maxStrengthGreedy(std::vector<int>& nums) -> long long;
    auto minAdd(std::string word) -> int;
    auto countWays(std::vector<int>& nums) -> int;
    auto clearDigits(std::string& s) -> std::string;
    auto clearDigits2(std::string& s) -> std::string;
    auto maximumLength(std::vector<int>& nums, int k) -> int;
    auto maximumLength2(std::vector<int>& nums, int k) -> int;
    auto maximumLength3(std::vector<int>& nums, int k) -> int;
    auto sortedSquares(std::vector<int>& nums) -> std::vector<int>;
    auto sortedSquaresPointers(std::vector<int>& nums) -> std::vector<int>;
    auto mergeNodes(ListNode* head) -> ListNode*;
    auto climbStairs(int n) -> int;
    auto climbStairsDP(int n) -> int;
    auto fib(int n) -> int;
    auto trib(int n) -> int;
    auto maximumRobots(std::vector<int>& chargeTimes, std::vector<int>& runningCosts, long long budget) -> int;
    auto minCostClimbingStairs(std::vector<int>& cost) -> int;
    auto rob(std::vector<int>& nums) -> int;
    auto deleteAndEarn(std::vector<int>& nums) -> int;
    auto removeStars(std::string s) -> std::string;
    auto removeDuplicates(std::string s) -> std::string;
    auto removeDuplicates2(std::string s, int k) -> std::string;
    auto replaceNonCoprimes(std::vector<int> &nums) -> std::vector<int>;
    auto numberOfPoints(std::vector<std::vector<int>>& nums) -> int;
    auto findValidSplit(std::vector<int>& nums) -> int;
};