class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.rbegin() , arr.rend());
        unordered_map<int,int> mp;
        for(int i = 0 ; i < arr.size() ; i++){        
            for(int j = 0 ; j < arr.size() ; j++){
                if(i!=j && arr[i] == arr[j] * 2) return true;
            }
        }
        return false;
    }
};