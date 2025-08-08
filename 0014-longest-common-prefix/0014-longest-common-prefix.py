class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        s = strs[0]
        t = strs[-1]
        ans = ""

        minlen = min(len(s) , len(t))

        for i in range(minlen):
            if s[i] != t[i]:
                break
            ans += s[i]
        return ans
