class Solution:
    def sortColors(self, nums: List[int]) -> None:
        zeroes = nums.count(0)
        ones = nums.count(1)
        twos = nums.count(2)
        
        n = len(nums)
        
        for i in range(zeroes):
            nums[i] = 0
        
        for i in range(zeroes , zeroes+ones):
            nums[i] = 1
        
        for i in range(zeroes+ones , n ):
            nums[i] = 2
        


 
        