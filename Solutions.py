from typing import List

class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        sum_nums = sum(nums)
        if sum_nums % k:
            return False
        target = sum_nums // k
        nums.sort()
        if nums[-1] > target:
            return False
        
        n = len(nums)
        visited = [False] * (1 << n)
        visited[0] = True
        curr_sum = [0] * (1 << n)
        for i in range(0, 1 << n):
            if not visited[i]:
                continue
            for j in range(n):
                if curr_sum[i] + nums[j] > target:
                    break
                if (i >> j & 1) == 0:
                    nxt = i | (1 << j)
                    if not visited[nxt]:
                        curr_sum[nxt] = (curr_sum[i] + nums[j]) % target
                        visited[nxt] = True
                
        return visited[(1 << n) - 1]
    
    def canPartitionKSubsets_dfs(self, nums: List[int], k: int) -> bool:
        s, mod = divmod(sum(nums), k)
        if mod:
            return False
        curr = [0] * k
        nums.sort(reverse=True)
        def dfs(i):
            if i == len(nums):
                return True
            for j in range(k):
                if j and curr[j] == curr[j - 1]:
                    continue
                curr[j] += nums[i]
                if curr[j] <= s and dfs(i + 1):
                    return True
                curr[j] -= nums[i]
            return False
        return dfs(0)
    
    def maxConseccutiveAnswers(self, answerKey: str, k: int) -> int:
        def maxConsecutive(target, k):
            res = 0
            left = 0
            count = 0
            for right in range(len(answerKey)):
                count += answerKey[right] != target
                while count > k:
                    count -= answerKey[left] != target
                    left += 1
                res = max(res, right - left + 1)
            return res

        return max(maxConsecutive('T', k), maxConsecutive('F', k))

        
            
        
# Test Cases
sol = Solution()
print(sol.canPartitionKSubsets([4,3,2,3,5,2,1], 4))
print(sol.canPartitionKSubsets([1,2,3,4], 3))
print(sol.canPartitionKSubsets([1,1,1,1,2,2,2,2], 2))

print(sol.canPartitionKSubsets_dfs([4,3,2,3,5,2,1], 4))
print(sol.canPartitionKSubsets_dfs([1,2,3,4], 3))
print(sol.canPartitionKSubsets_dfs([1,1,1,1,2,2,2,2], 2))

print(sol.maxConseccutiveAnswers("TTFF", 2))
print(sol.maxConseccutiveAnswers("TFFT", 1))
print(sol.maxConseccutiveAnswers("TTFTTFTT", 1))