class Solution {
public:
    vector<int> generaterow(int numrows){

        vector<int> ans;

        ans.push_back(1);

        int temp = 1;

        for(int col = 1 ; col < numrows ; col++){

            temp = temp * (numrows - col);
            temp /= col;
            ans.push_back(temp);

        }

        return ans;
    }
    vector<vector<int>> generate(int numrows){

        vector<vector<int>> v;

        for(int i = 1 ; i <= numrows ; i++){
 
            v.push_back(generaterow(i));

        }

        return v ;
    }
};