class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        nse = [n] * n
        pse = [-1] * n
        st = []

        for i in range(n-1 , -1 , -1):
            while st and heights[st[-1]] >= heights[i]:
                st.pop()
            nse[i] = st[-1] if st else n
            st.append(i) 

        st = []
        
        for i in range(n):
            while st and heights[st[-1]] >= heights[i]:
                st.pop()
            pse[i] = st[-1] if st else -1
            st.append(i)
        
        maxarea = -10**9

        for i in range(n):
            maxarea = max(maxarea , (nse[i] - pse[i] - 1)*heights[i])
        return maxarea
        