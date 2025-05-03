class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n[6]={0};
        for(int i=0;i<tops.size();i++){
            if(tops[i]==bottoms[i]) n[tops[i]-1]++;
            else 
            {
               n[tops[i]-1]++;
               n[bottoms[i]-1]++;
            } 
        }
        int nn=bottoms.size();
        int ti=0; int bi=0;
        int mino=INT_MAX;
        for(int i=0;i<6;i++){
               if(n[i]==nn){
                ti=0; bi=0;
                 
                 for(int j=0;j<nn;j++){
                     if(tops[j]==i+1) ti++;
                     if(bottoms[j]==i+1) bi++;
                 }
                 mino=min(nn-max(ti,bi),mino);
               }
        }
        if(mino!=INT_MAX) return mino;
        return -1;

    }
};