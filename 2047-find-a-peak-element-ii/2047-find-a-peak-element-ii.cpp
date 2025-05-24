class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            bool leftIsBigger = mid - 1 >= 0 && mat[maxRow][mid - 1] > mat[maxRow][mid];
            bool rightIsBigger = mid + 1 < n && mat[maxRow][mid + 1] > mat[maxRow][mid];
            
            if (!leftIsBigger && !rightIsBigger) {
                return {maxRow, mid}; 
            } else if (leftIsBigger) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return {-1, -1}; 
    }
};
