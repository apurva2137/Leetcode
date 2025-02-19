class Solution {
public:
    int compress(vector<char>& chars) {
        int ans=0;
        for(int i=0;i<chars.size();i++){
            char letter=chars[i];
            int count=0;
            while(i<chars.size() && chars[i]==letter){
                count++;
                i++;
            }
            if(count==1) {chars[ans]=letter;
            ans++;}
            else{
                chars[ans]=letter;
                ans++;
                string str = to_string(count);
                for(char dig : str){
                    chars[ans++] = dig;
                }
            }
            i--;
        }
        return ans;
    }
};