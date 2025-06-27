class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        int left = 0;
        int mincount = INT_MAX;

        for(int i = 0 ; i < blocks.size() ; i++){
            if(i-k >= 0 && blocks[i-k] == 'B') count--;
            if(blocks[i] == 'B') count++;
            mincount = min(mincount , k-count);
        }
        return mincount;
    }
};