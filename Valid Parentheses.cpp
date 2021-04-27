// Link : https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string A) {
        stack<char> stk;
    int n=A.length();
    for(int i=0;i<n;i++)
    {
        if(A[i]=='(' || A[i]=='{' || A[i]=='[')
        {
            stk.push(A[i]);
            continue;
        }
        if(stk.empty() && (A[i]==')' || A[i]=='}' || A[i]==']'))
            return 0;
        if(A[i]==')' && stk.top()=='(')
        {
            stk.pop();
        }
        else if(A[i]=='}' && stk.top()=='{')
        {
            stk.pop();
        }
        else if(A[i]==']' && stk.top()=='[')
        {
            stk.pop();
        }
        else
        {
            return 0;
        }
    }
    return stk.empty();
    }
};