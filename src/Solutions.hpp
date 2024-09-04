#include <string>
#include <vector>

class solution  {
 public:
    auto canPartitionKSubsets(std::vector<int>& nums, int k) -> bool;
    auto canPartitionKSubsetsDFS(std::vector<int>& nums, int k) -> bool;
    auto maxConsecutiveAnswers(std::string& answerKey, int k) -> int;
    auto maxStrength(std::vector<int>& nums) -> long long;
    auto maxStrengthGreedy(std::vector<int>& nums) -> long long;
    auto minAdd(std::string word) -> int;
    auto countWays(std::vector<int>& nums) -> int;
};