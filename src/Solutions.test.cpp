#include "Solutions.hpp"
#include <catch2/catch.hpp>
#include <string>
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
// TEST_CASE("mergeNodes") {
//     solution s;
//     ListNode* head = new ListNode();
//     ListNode* n1 = new ListNode(3);
//     head->next = n1;
//     ListNode* n2 = new ListNode(1);
//     n1->next = n2;
//     ListNode* n3 = new ListNode(0);
//     n2->next = n3;
//     ListNode* n4 = new ListNode(4);
//     n3->next = n4;
//     ListNode* n5 = new ListNode(5);
//     n4->next = n5;
//     ListNode* n6 = new ListNode(2);
//     n5->next = n6;
//     ListNode* tail = new ListNode();
//     n6->next = tail;

//     auto res = s.mergeNodes(head);
//     REQUIRE(res->val == 4);
// }

TEST_CASE("sq5") {
    solution s;
    REQUIRE(s.climbStairs(4) == 5);
}

TEST_CASE("climbStairsDP") {
    solution s;
    REQUIRE(s.climbStairsDP(4) == 5);
}

TEST_CASE("maximumRobots") {
    solution s;
    std::vector<int> chargeTimes = {3,6,1,3,4};
    std::vector<int> runningCosts = {2,1,3,4,5};
    int budget = 25;
    // REQUIRE(s.maximumRobots(chargeTimes, runningCosts, budget) == 3);
    auto rs = s.maximumRobots(chargeTimes, runningCosts, budget);
    REQUIRE(rs == 3);
    std::vector<int> chargeTime = {8,76,74,9,75,71,71,42,15,58,88,38,56,59,10,11};
    std::vector<int> runningCost = {1,92,41,63,22,37,37,8,68,97,39,59,45,50,29,37};
    int budget1 = 412;
    auto res = s.maximumRobots(chargeTime, runningCost, budget1);
    REQUIRE(res == 3);
}

TEST_CASE("minCostClimbingStairs") {
    solution s;
    std::vector<int> cost = {10,15,20};
    std::vector<int> cost1 = {1,100,1,1,1,100,1,1,100,1};
    REQUIRE(s.minCostClimbingStairs(cost) == 15);
    REQUIRE(s.minCostClimbingStairs(cost1) == 6);
}

TEST_CASE("deleteAndEarn") {
    solution s;
    // std::vector<int> nums = {3,4,2};
    std::vector<int> nums1 = {2,2,3,3,3,4};
    auto a = s.deleteAndEarn(nums1);
}

TEST_CASE("removeDuplicates2") {
    solution s;
    // std::string s1 = "pbbcggttciiippooaais";
    std::string s2 = "yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy";
    // std::cout << s.removeDuplicates2(s1, 2) << std::endl;
    std::cout << "required s2:" << "ybth" << std::endl; 
    std::cout << s.removeDuplicates2(s2, 4) << std::endl;
}

TEST_CASE("replaceNonCoprimes") {
    solution s;
    std::vector<int> nums = {6,4,3,2,7,6,2};
    auto res = s.replaceNonCoprimes(nums);
    for (const auto& n : res) {
        std::cout << n << " ";
    }
}

TEST_CASE("findValidSplit") {
    solution s;
    std::vector<int> nums = {557663,280817,472963,156253,273349,884803,756869,763183,557663,964357,821411,887849,891133,453379,464279,574373,852749,15031,156253,360169,526159,410203,6101,954851,860599,802573,971693,279173,134243,187367,896953,665011,277747,439441,225683,555143,496303,290317,652033,713311,230107,770047,308323,319607,772907,627217,119311,922463,119311,641131,922463,404773,728417,948281,612373,857707,990589,12739,9127,857963,53113,956003,363397,768613,47981,466027,981569,41597,87149,55021,600883,111953,119083,471871,125641,922463,562577,269069,806999,981073,857707,831587,149351,996461,432457,10903,921091,119083,72671,843289,567323,317003,802129,612373};
    auto res = s.findValidSplit(nums);
    std::cout << res << std::endl;
}