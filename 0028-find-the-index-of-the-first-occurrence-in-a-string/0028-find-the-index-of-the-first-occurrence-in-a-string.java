class Solution {
    public int strStr(String h, String needle) {
        int n = needle.length();
        for(int i = 0 ; i <= h.length() - n; i++){
            String st = h.substring(i,i+n);
            if(st.equals(needle)) return i;
        }
        return -1;
    }
}