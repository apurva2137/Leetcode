class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        int i = n-1;
        while(i >=0 && s.charAt(i) == ' ') i--;
        int len = 0;
        while(i >= 0){
            if(s.charAt(i) == ' ') break;
            len++;
            i--;
        }
        return len;
    }
}