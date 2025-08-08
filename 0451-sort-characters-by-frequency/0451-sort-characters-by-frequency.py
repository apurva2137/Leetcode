from collections import Counter
class Solution:
    def frequencySort(self, s: str) -> str:
        mp = Counter(s)
        ans = ""
        v = [(count , ch) for ch, count in mp.items()]
        v.sort(reverse = True)

        for i in range(len(v)):
            c = v[i][1]
            count = v[i][0]
            while count > 0:
                ans += c
                count-=1
        return ans
        