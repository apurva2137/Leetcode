class Solution {
public:
vector<string> ans;
unordered_map<string,int> map;
void solve(string s,int minimum_removal_allowed)
{
    if(map[s]!=0)
        return;
    else
        map[s]++;
    
    if(minimum_removal_allowed==0)
    {
        int minimum_removal_now=getminimuminvalid(s);
        if(minimum_removal_now==0)
        {   
            ans.push_back(s);
        }
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        string left=s.substr(0,i);
        string right=s.substr(i+1);
        solve(left+right,minimum_removal_allowed-1);
    }
    return;
}
int getminimuminvalid(string s)
{
    stack<char>stack;
    int i=0;
    
    while(i<s.size())
    {
        if(s[i]=='(')
            stack.push('(');
        else if(s[i]==')')
        {
            if(stack.empty()==false && stack.top()=='(')
            {
                stack.pop();
            }
            else
                 stack.push(')');
        }
        i++;
    }
    return stack.size();
}
vector<string> removeInvalidParentheses(string s) 
{
    int minimum_removals=getminimuminvalid(s);
    
    solve(s,minimum_removals);
    return ans;
}
};