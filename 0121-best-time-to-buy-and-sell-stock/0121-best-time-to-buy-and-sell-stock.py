class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minval = prices[0]
        maxval = 0
        for i in range(1,len(prices)):
            if prices[i] < minval:
                minval = prices[i]
            maxval = max(maxval , prices[i] - minval)
        return maxval

        