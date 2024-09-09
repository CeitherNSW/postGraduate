from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

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

    def maxStrength(self, nums: List[int]) -> int:
        # input nums = [3,-1,-5,2,5,-9]
        # output = 1350
        def subsets(lis):
            if not lis:
                return [[]]
            res = []
            first, rest = lis[0], lis[1:]
            without_first = subsets(rest)
            with_first = [ [first] + i for i in without_first]
            return with_first + without_first
        tmp = subsets(nums)
        tar = [e for e in tmp if e]
        res = []
        for e in tar:
            cal = 1
            for i in e:
                cal *= i
            res.append(cal)
        return max(res)
    
    def maxStrengthGreedy(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        if n == 1:
            return nums[0]
        if nums[1] == nums[-1] == 0:
            return 0
        ans, i = 1, 0
        while i < n:
            if nums[i] < 0 and i + 1 < n and nums[i + 1] < 0:
                ans *= nums[i] * nums[i + 1]
                i += 2
            elif nums[i] <= 0:
                i += 1
            else:
                ans *= nums[i]
                i += 1
        
        return ans
    
    def addMinimum(self, word: str) -> int:
        n = len(word)
        d = [0] * (n + 1)
        for i in range(1, n + 1):
            d[i] = d[i-1] + 2
            if i > 1 and word[i-1] > word[i - 2]:
                d[i] = d[i - 1] - 1
        return d[n]
        # k, prev = 0, 'z'
        # for c in word:
        #     k += c <= prev
        #     prev = c
        # return k * 3 - len(word)

    def countWays(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        ans = 0
        for i in range(0, n + 1): 
            if i > 0 and nums[i - 1] >= i:
                continue
            if i < n and nums[i] <= i:
                continue
            ans += 1
        return ans
    
    def clearDigits(self, s: str) -> str:
        cnt = 0
        delete = []
        for c in s:
            if c.isdigit():
                temp = cnt - 1
                while temp in delete:
                    temp -= 1
                delete.append(cnt)
                delete.append(temp)
                cnt += 1
            else:
                cnt += 1
        
        return ''.join([c for i, c in enumerate(s) if i not in delete])
    
    def clearDigits2(self, s: str) -> str:
        res = []
        for c in s:
            if c.isdigit():
                if res:
                    res.pop()
                else:
                    continue
            else:
                res.append(c)
        return ''.join(res)
        
    def sortedSquares(self, nums: List[int]) -> List[int]:
        return sorted([x*x for x in nums])
    
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        tail = dummy
        curr = head.next
        ttl = 0
        
        while curr:
            if curr.val == 0:
                if ttl != 0:
                    node = ListNode(ttl)
                    tail.next = node
                    tail = tail.next
                    ttl = 0
            else:
                ttl += curr.val
            curr = curr.next
            
        return dummy.next
        
                
            
        
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

print(sol.maxStrength([3,-1,-5,2,5,-9]))
print(sol.maxStrengthGreedy([3,-1,-5,2,5,-9]))
print(sol.maxStrengthGreedy([8,6,0,5,-4,-8,-4,9,-1,6,-4,8,-5]))


print(sol.addMinimum("abbbcaa"))
print(sol.countWays([1, 1]))

print(sol.clearDigits("ab1234cd"))
print(sol.clearDigits2("ab1234cd"))

ListNode1 = ListNode(0)
ListNode2 = ListNode(1)
ListNode3 = ListNode(3)
ListNode4 = ListNode(0)

ListNode1.next = ListNode2
ListNode2.next = ListNode3
ListNode3.next = ListNode4

print(sol.mergeNodes(ListNode1).val)