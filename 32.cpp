/*
[Longest Valid Parentheses]

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */
#include <iostream>
#include <stack>
using namespace std;
//dp
int longestValidParentheses_01(string s) {
    int i,j;
    int mx = 0;
    int len = s.length();
    int dp[len];
    for(i=0; i<len; i++){
        dp[i] = 0;
    }
    for(i=1; i<len; i++){
        if(s[i] == ')'){
            j = i-dp[i-1]-1;
            if(j>=0 && s[j]=='('){
                dp[i] = dp[i-1] + 2;
                if(j-1 >= 0){
                    dp[i] += dp[j-1];
                }
            }
        }
        mx = max(mx, dp[i]);
    }
    return mx;
}
//stack
int longestValidParentheses_02(string s) {
    int mx = 0;
    int last = -1;
    stack<int> stk;
    for(int i=0; i<s.length(); i++){
       if(s[i] == '('){
           stk.push(i);
       }else{
           if(stk.empty()){
               last = i;
           }else{
               stk.pop();
               if(stk.empty()){
                   mx = max(mx, i-last);
               }else{
                   mx = max(mx, i-stk.top());
               }
           }
       }
    }
    return mx;
}

int main(){
    cout << longestValidParentheses_02("(()") << endl;
}