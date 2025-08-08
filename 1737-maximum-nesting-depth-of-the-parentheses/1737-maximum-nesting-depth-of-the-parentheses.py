class Solution:
    def maxDepth(self, s: str) -> int:
        st = []
        maxd = 0
        for i in range(len(s)):
            if s[i] == '(':
                st.append('(')
            elif s[i] == ')':
                n = len(st)
                maxd = max(maxd , n)
                st.pop()
        return maxd


        