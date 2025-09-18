class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int n = letters.size();
        int right = n - 1;
        int num = target - 'a';
        char ans = letters[0];

        while(left <= right){
            int mid = left + (right - left)/2;
            if((letters[mid] - 'a') > num){
                ans = letters[mid];
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};