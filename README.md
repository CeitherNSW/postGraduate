# 题解
## 分为K个子集
题目给定长度为 n 的数组 nums，和整数 k，我们需要判断是否能将数组分成 k 个总和相等的非空子集。首先计算数组的和 all，如果 all 不是 k 的倍数，那么不可能能有合法方案，此时直接返回 False。否则我们需要得到 k 个和为 per = k / all
​
  的集合，那么我们每次尝试选择一个还在数组中的数，若选择后当前已选数字和等于 per 则说明得到了一个集合，而已选数字和大于 per 时，不可能形成一个集合从而停止继续往下选择新的数字。

又因为 n 满足 1≤n≤16，所以我们可以用一个整数 S 来表示当前可用的数字集合：从低位到高位，第 i 位为 1 则表示数字 nums[i] 可以使用，否则表示 nums[i] 已被使用。为了避免相同状态的重复计算，我们用 dp[S] 来表示在可用的数字状态为 S 的情况下是否可行，初始全部状态为记录为可行状态 True。这样我们就可以通过记忆化搜索这种「自顶向下」的方式来进行求解原始状态的可行性，而当状态集合中不存在任何数字时，即 S=0 时，表示原始数组可以按照题目要求来进行分配，此时返回 True 即可。


## 考试的最大困扰度
只要求最大连续指定字符的数目

在指定字符的情况下，我们可以计算其最大连续数目。具体地，我们使用滑动窗口的方法，从左到右枚举右端点，维护区间中另一种字符的数量为 sum，当 sum 超过 k，我们需要让左端点右移，直到 sum≤k。移动过程中，我们记录滑动窗口的最大长度，即为指定字符的最大连续数目。

## 一个小组的最大实力
暴力枚举给定数组的所有子集，然后直接计算每个子集的累积，最后返回

或

排序后，如果当前元素<0且下一元素也<0，则将这两个元素分别乘到结果中，否则跳过，若当前元素=0，则直接跳过，若当前元素>0，则直接将当前元素乘到结果中。

## 构造有效字符串的最少插入数
dp
定义状态 d[i] 为将前 i 个字符（为了方便编码，下标从 1 开始）拼凑成若干个 abc 所需要的最小插入数。那么初始状态 d[0]=0，最终要求解 d[n]，其中 n 为 word 的长度。
转移过程有以下几种情况：

word[i] 单独存在于一组 abc 中，d[i]=d[i−1]+2。
如果 word[i]>word[i−1]，那么 word[i] 可以和 word[i−1] 在同一组 abc 中，d[i]=d[i−1]−1。
d[i] 取以上情况的最小值。在本题中，每个字符总是尽可能的与前面的字符去组合，因此情况 2 优于情况 1（从动态转移方程中也可以发现此规律），按照顺序依次更新 d[i] 即可，并不需要取最小值。

## 一个小组的最大实力值
思路与算法

根据题意可知，假设数组 nums 的长度为 n，此时设选中学生人数为 k，此时 k∈[0,n]，k 应满足如下：

所有满足 nums[i]<k 的学生应被选中；

所有满足 nums[i]>k 的学生不应被选中；

不能存在 nums[i]=k 的学生；

这意味着在确定当前已择中学生人数的前提下，则此时选择方案是唯一的，为方便判断，我们把 nums 从小到大排序。我们枚举选中的人数 k，由于 nums 已有序，此时最优分组一定是前 k 个学生被选中，剩余的 n−k 个学生不被选中，此时只需要检测选中的 k 个学生中的最大值是否满足小于 k，未被选中的学生中的最小值是否满足大于 k 即可，如果同时满足上述两个条件，则该分配方案可行，最终返回可行的方案计数即可，需要注意处理好边界 0 与 n。
```
这题动规好像会变的特别麻烦
```

## 让所有学生保持开心的分组方法数

在选择学生人数固定的时候，选择方案是否唯一呢？

假设恰好选 k 个学生，那么：

所有 ```nums[i]<k``` 的学生都要选；
所有 ```nums[i]>k``` 的学生都不能选；
不能出现 ```nums[i]=k``` 的情况，因为每个学生只有选或不选两种可能。
这意味着在选择学生人数固定的时候，选择方案是唯一的。把 nums 从小到大排序后，唯一性可以更明显地看出来：

以 k 为分界线，左边的都要选，右边的都不能选。
排序后：

如果选了 nums[i]，那么比 nums[i] 更小的学生也要选。
如果不选 nums[i]，那么比 nums[i] 更大的学生也不选。
具体地，如果选 nums[i−1] 而不选 nums[i]，由于数组已排序，我们必须要选下标为 0,1,2,⋯,i−1 的学生，一共 i 个，而下标 ≥i 的学生都不能选，所以需要满足

```nums[i−1]<i<nums[i]```
枚举 i=1,2,⋯,n−1（枚举分界线的位置），如果上式成立，就意味着我们可以选 i 个学生，算作一种方案。


## 清除数字
法一：

维护一个保存有需要删除的元素索引的列表，返回不包含索引对的字符串

法二：

因为题目描述
```
输入保证所有数字都可以按以上操作被删除。
```
所以可以直接判断每个字符是否是数字，是就直接pop，否则加入列表，返回列表中每个元素组成的字符串

## 求出最长好子序列 I

动规：

用dp[i][j]来表示以nums[i]结尾组成的最长合法*序列*中有j个数字与其在序列中的后一个数字不相等。其中i的取值为nums的长度，j不超过k。初始情况下，dp[i][0] = 1


### *dp[i][j]=max <sub>j</sub> dp[x][j−(nums[x]=nums[i])]+1*

动规优化思路：

实际上只需要枚举两种情况：

*nums[i] != nums[x]*，对于此情况可以维护一个长度为 k 的辅助数组sup。其中 sup[j] 表示枚举到 i 前有 j 个与其在序列中的后一个不相等的合法序列最长长度，有:
### *dp[i][j]=max<sub>j</sub>sup[j−1]+1。*

*nums[i]=nums[x]*，假设有索引 *a<b<c*， 并且 *nums[a]=nums[b]=nums[c]*，对于 c 来说如果选取由 a 转移过来计算答案。针对这种情况，dp 使用哈希表维护能节省一些空间，并且在哈希表中用 nums[i] 替换 i。

## 有序数组的平方

一行

return sorted([x*x for x in A])


## 合并零之间的节点
链表模拟

题目要求最后返回的链表中不存在0

创建一个辅助dummy节点
若当前节点不为0 且 ttl不为0 创建一个新的val为ttl的节点并且把它链接到dummy节点上
然后将ttl值置0
否则ttl值加上当前节点的值

最后直接返回dummy.next即可
若要考虑释放dummy的内存，则需要在先保存dummy的next节点，然后释放dummy，最后返回保存的next节点