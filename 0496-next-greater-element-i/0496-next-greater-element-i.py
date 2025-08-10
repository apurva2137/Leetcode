from collections import defaultdict
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        st = []
        mp = defaultdict(int)

        for i in range(len(nums2) - 1 , -1 , -1):
            while st and st[-1] <= nums2[i]:
                st.pop()
            mp[nums2[i]] = st[-1] if st else -1
            st.append(nums2[i])
        
        ans = [-1]*len(nums1)

        for i in range(len(nums1)):
            ans[i] = mp[nums1[i]]
        return ans
            
        
        