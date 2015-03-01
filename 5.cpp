/*
[Longest Palindromic Substring]

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */
#include <iostream>
using namespace std;

string longestPalindrome(string s) {
    string tmp = "^";
    for(int i=0; i<s.length(); i++){
        tmp += '#';
        tmp += s[i];
    }
    tmp += "#$";

    int tmp_len = tmp.length();
    int len[tmp_len];
    int po = 0, p = 0, pos = 0, max = 0;
    for(int i=1; i<tmp_len; i++){
        len[i] = i<=p ? min(len[2*po-i], p-i) : 1;
        while(tmp[i-len[i]] == tmp[i+len[i]]){
            len[i]++;
        }
        if(len[i]+i > p){
            p = len[i] + i;
            po = i;
        }
        if(len[i] > max){
            max = len[i];
            pos = i;
        }
    }
    return s.substr((pos-max+1)/2, max-1);
}

int main(){
    cout << longestPalindrome("absssabababauudi") << endl;
    return 0;
}