from collections import defaultdict
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp1 = defaultdict(int)
        mp2 = defaultdict(int)

        for i in range(len(s)):
            c = s[i]
            ch = t[i]
            if c in mp1 and mp1[c] != ch :
                return False
            elif ch in mp2 and mp2[ch] != c:
                return False

            mp1[c] = ch
            mp2[ch] = c
        return True
        