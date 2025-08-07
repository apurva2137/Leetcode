from collections import defaultdict
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mp = defaultdict(int)
        for num in nums:
            mp[num]+=1
        
        n = len(nums)
        n = n//2

        for key , value in mp.items():
            if mp[key] > n:
                return key
        return -1
        