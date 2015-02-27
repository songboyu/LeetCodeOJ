/*
[Longest Substring Without Repeating Characters]

Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */
#include <iostream>
#include <string.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int mp[256];
    memset(mp, -1, sizeof(mp));

    int index = -1;
    int max_len = 0;
    for(int i=0; i<s.size(); i++){
        if(mp[s[i]] > index){
            index = mp[s[i]];
        }
        if(i-index > max_len){
            max_len = i - index;
        }
        mp[s[i]] = i;
    }
    return max_len;
}

int main(){
    string a = "abcbcadc";
    cout << lengthOfLongestSubstring(a) << endl;
    return 0;
}