class Solution {
    public String reverseWords(String s) {
        String ans = "";
        String temp = "";
        int i = 0;

        while(i < s.length() && s.charAt(i) == ' ') i++;

        while( i < s.length()){
            char c = s.charAt(i);
            if(c != ' '){
                temp += c;
            }
            else{
                if(temp != ""){
                    if(ans != ""){
                        ans = temp + ' ' + ans;
                    }
                    else ans = temp;
                }
                temp = "";
            }
            i++;
        }
        if(temp != ""){
            if(ans != ""){
                ans = temp + ' ' + ans;
            }
            else ans = temp;
        }
        return ans;
    }
}