class Solution:
    def countDigitOne(self, n: int) -> int:
        count = 0
        k = 0
        ori = n

        while n:
            last = n % 10
            if k > 0 and last == 1:
                count += ((n-1) // 10) * 10**k + ori % (10**k) + 1
            else:
                count += ((n-1) // 10 + 1) * 10**k
            n //= 10
            k += 1
        
        return count