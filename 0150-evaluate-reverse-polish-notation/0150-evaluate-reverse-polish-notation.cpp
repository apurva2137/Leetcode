class Solution {
public:
    bool isvalid(string s){
            if(s=="+" || s=="-"|| s=="*" ||s=="/") return true;
             return false;
        }

    int calculate(int a,int b,string s){
            if(s=="+") return a+b;
            if(s=="-") return a-b;
            if(s=="*") return a*b;
            if(s=="/") return a/b;
            return 0;
        }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i=0;i<tokens.size();i++){

            if(isvalid(tokens[i])){

                int b= st.top();
                st.pop();
                int a=st.top();
                st.pop();

                int result=calculate(a,b,tokens[i]);
                st.push(result);
            }

            else{

                st.push(stoi(tokens[i]));

            }
        }
        return st.top();
    }
};