#include "Solutions.hpp"
#include <catch2/catch.hpp>

TEST_CASE("canPartitionKSubsets") {
    solution s;
    std::vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    REQUIRE(s.canPartitionKSubsets(nums, 4) == true);
    REQUIRE(s.canPartitionKSubsets(nums, 3) == false);
}

TEST_CASE("canPartitionKSubsetsDFS") {
    solution s;
    std::vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    REQUIRE(s.canPartitionKSubsetsDFS(nums, 4) == true);
    REQUIRE(s.canPartitionKSubsetsDFS(nums, 3) == false);
}

TEST_CASE("maxConsecutiveAnswers") {
    solution s;
    std::string answerKey0 = "TTFF";
    REQUIRE(s.maxConsecutiveAnswers(answerKey0, 2) == 4);
    REQUIRE(s.maxConsecutiveAnswers(answerKey0, 1) == 3);

    std::string answerKey1 = "TFFT";
    REQUIRE(s.maxConsecutiveAnswers(answerKey1, 1) == 3);
    REQUIRE(s.maxConsecutiveAnswers(answerKey1, 2) == 4);

    std::string answerKey2 = "TTFTTFTT";
    REQUIRE(s.maxConsecutiveAnswers(answerKey2, 1) == 5);
    REQUIRE(s.maxConsecutiveAnswers(answerKey2, 2) == 8);
}