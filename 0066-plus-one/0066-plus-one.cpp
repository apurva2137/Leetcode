class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int c=0;
        for(int i=0;i<digits.size();i++){
            int num=digits[i]+(i == 0 ? 1 : 0)+c;
            digits[i] = num%10;
            c=num/10;
            if(c==0 && i>0) break;
        }
        if(c) digits.push_back(c);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};