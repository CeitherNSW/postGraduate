#include <string>
#include <vector>

class solution  {
 public:
    auto canPartitionKSubsets(std::vector<int>& nums, int k) -> bool;
    auto canPartitionKSubsetsDFS(std::vector<int>& nums, int k) -> bool;
    auto maxConsecutiveAnswers(std::string& answerKey, int k) -> int;
};