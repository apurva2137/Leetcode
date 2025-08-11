class Solution:
    def countparts(self , nums : List[int] , maxp : [int]) ->int:
        total = 0
        parts = 1
        for i in range(len(nums)):
            if total + nums[i] > maxp:
                parts += 1
                total = 0
            total += nums[i]
        return parts

    def splitArray(self, nums: List[int], k: int) -> int:
        left = max(nums)
        right = sum(nums)
        n = len(nums)
        ans = -1
        while left <= right:
            mid = left + ((right - left) // 2)

            if(self.countparts(nums,mid) <= k):
                ans = mid
                right = mid-1
            
            else:
                left = mid + 1
        return ans