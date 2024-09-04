#include "Solutions.hpp"
#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

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

TEST_CASE("maxStrength") {
    solution s;
    std::vector<int> nums = {3,-1,-5,2,5,-9};
    auto res = s.maxStrength(nums);
    REQUIRE(res == 1350);
    std::vector<int> nums1 = {-4,-5,-4};
    auto res1 = s.maxStrength(nums1);
    REQUIRE(res1 == 20);
    std::vector<int> nums2 = {8,6,0,5,-4,-8,-4,9,-1,6,-4,8,-5};
    auto res2 = s.maxStrength(nums2);

    REQUIRE(res2 == 265420800);
}

TEST_CASE("maxStrengthGreedy") {
    solution s;
    std::vector<int> nums = {3,-1,-5,2,5,-9};
    auto res = s.maxStrength(nums);
    REQUIRE(res == 1350);
    std::vector<int> nums2 = {8,6,0,5,-4,-8,-4,9,-1,6,-4,8,-5};
    auto res2 = s.maxStrength(nums2);
    REQUIRE(res2 == 265420800);
}

TEST_CASE("minAdd") {
    solution s;
    std::string word = "abbbcaa";
    REQUIRE(s.minAdd(word) == 8);
}

TEST_CASE("countWays") {
    solution s;
    std::vector<int> nums = {6,0,3,3,6,7,2,7};
    REQUIRE(s.countWays(nums) == 3);
}
