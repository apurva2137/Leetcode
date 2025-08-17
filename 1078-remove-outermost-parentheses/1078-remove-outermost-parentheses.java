class Solution {
    public String removeOuterParentheses(String s) {
        Stack<Character> st = new Stack<>();
        String ans = "";

        for(int i = 0 ; i < s.length(); i++){
            char c = s.charAt(i);

            if(c == '('){
                if(!st.isEmpty()) 
                ans += c;
                st.push(c);
            }
            else{
                st.pop();
                if(!st.isEmpty()) ans += ')';
            }
        }
        return ans;
    }
}