#include "Solutions.hpp"
#include <catch2/catch.hpp>
#include <vector>
#include <iostream>

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

TEST_CASE("clearDigits") {
    solution s;
    std::string s1 = "cd34";
    REQUIRE(s.clearDigits(s1) == "");
}

TEST_CASE("clearDigits2") {
    solution s;
    std::string s1 = "cd34";
    REQUIRE(s.clearDigits2(s1) == "");
}

TEST_CASE("maximumLength") {
    solution s;
    std::vector<int> nums = {1,2,1,1,3};
    std::vector<int> nums1 = {1,2,3,4,5,1};
    REQUIRE(s.maximumLength(nums, 2) == 4);
    // std::cout << s.maximumLength(nums1, 0) << std::endl;
}

TEST_CASE("maximumLength2") {
    solution s;
    std::vector<int> nums = {1,2,1,1,3};
    std::vector<int> nums1 = {1,2,3,4,5,1};
    REQUIRE(s.maximumLength2(nums, 2) == 4);
    // std::cout << s.maximumLength2(nums1, 0) << std::endl;
}

TEST_CASE("maximunLength3") {
    solution s;
    std::vector<int> nums = {1,2,1,1,3};
    REQUIRE(s.maximumLength3(nums, 2) == 4);
}

TEST_CASE("sortedSquares") {
    solution s;
    std::vector<int> nums = {-4,-1,0,3,10};
    REQUIRE(s.sortedSquares(nums) == std::vector<int>({0,1,9,16,100}));
}

// [0,3,1,0,4,5,2,0]
TEST_CASE("mergeNodes") {
    solution s;
    ListNode* head = new ListNode();
    ListNode* n1 = new ListNode(3);
    head->next = n1;
    ListNode* n2 = new ListNode(1);
    n1->next = n2;
    ListNode* n3 = new ListNode(0);
    n2->next = n3;
    ListNode* n4 = new ListNode(4);
    n3->next = n4;
    ListNode* n5 = new ListNode(5);
    n4->next = n5;
    ListNode* n6 = new ListNode(2);
    n5->next = n6;
    ListNode* tail = new ListNode();
    n6->next = tail;

    auto res = s.mergeNodes(head);
    REQUIRE(res->val == 4);
}