class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        tot = sum(nums)
        n = len(nums)
        act_sum = (n * (n+1)) // 2
        return act_sum - tot