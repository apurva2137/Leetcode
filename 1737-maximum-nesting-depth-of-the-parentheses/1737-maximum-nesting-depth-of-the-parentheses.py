class Solution:
    def maxDepth(self, s: str) -> int:
        n = 0
        count = 0
        for c in s:
            if c == '(':
                count += 1
            n = max(count , n)    
            if c == ')':
                count -= 1
        return n
                
