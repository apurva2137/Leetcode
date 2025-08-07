class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxcount = 0
        count = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                count = 0
            else:
                count += 1
                maxcount = max(maxcount , count)
        return maxcount
