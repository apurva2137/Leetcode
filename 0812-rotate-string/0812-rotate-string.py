class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        n = len(s)
        for i in range(n):
            st = s[i+1:] + s[:i+1]
            if st == goal:
                return True   
        return False