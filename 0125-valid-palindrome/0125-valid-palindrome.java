class Solution {
    public boolean isPalindrome(String s) {
        String t = "";

        t = s.toLowerCase();
        String st = "";
        for(int i = 0 ; i < t.length() ; i++){
            char c = t.charAt(i);
            if(Character.isLetterOrDigit(c)) st += c;
        }
        int n = st.length();
        for(int i = 0 ; i < n /2 ; i++){
           if(st.charAt(i) != st.charAt(n-i-1)) return false;
        }
        return true;
    }
}