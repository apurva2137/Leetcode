class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = ""
        st = []

        for i in range(len(s)):
            if s[i]=='(':
                if st:
                    ans += '('
                st.append(s[i])
            elif s[i] == ')':
                st.pop()
                if len(st) >= 1:
                    ans += ')'
        return ans


    

        