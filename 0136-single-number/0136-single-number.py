from collections import defaultdict
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        mp = defaultdict(int)
        for num in nums:
            mp[num] += 1
        
        for key,value in mp.items():
            if value == 1:
                return key