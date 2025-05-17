class Solution {
public:
    int totalDigits;
    int computeFactorial(int n) {
        int result = 1;
        while (n > 1)
            result *= n--;
        return result;
    }

    string getNthUnusedDigit(vector<bool>& isUsed, int nthAvailable) {
        for (int i = 1; i <= totalDigits; i++) {
            if (!isUsed[i]) {
                nthAvailable--;
                if (nthAvailable == 0) {
                    isUsed[i] = true;
                    return to_string(i);
                }
            }
        }
        return "-1";
    }

    string getPermutation(int n, int k) {
        totalDigits = n;
        int blockSize = computeFactorial(n - 1); 
        vector<bool> isUsed(n + 1, false); 
        string result = "";

        while (n > 1) {
            int indexInBlock = k % blockSize == 0 ? blockSize : k % blockSize;
            int position = ceil((double)k / blockSize);
            result += getNthUnusedDigit(isUsed, position);

            k = indexInBlock;
            n--;
            blockSize = computeFactorial(n - 1); 
        }

        for (int i = 1; i <= totalDigits; i++) {
            if (!isUsed[i]) {
                result += to_string(i);
                break;
            }
        }

        return result;
    }
};