/*
[Implement strStr()]

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int* getNext(char *p){
        int j,k;
        int n = strlen(p);
        int next[n];
        next[0]=-1;
        j=0;
        k=-1;
        while(j<n-1)
        {
            if(k==-1||p[j]==p[k])    //匹配的情况下,p[j]==p[k]
            {
                j++;
                k++;
                next[j]=k;
            }
            else                   //p[j]!=p[k]
                k=next[k];
        }
        return next;
    }
    int strStr(char *haystack, char *needle) {
        int m = strlen(haystack);
        int n = strlen(needle);
        if(n == 0){
            return 0;
        }
        int *next = getNext(needle);
        int i = 0,j = 0;

        while(i<m) {
            if (haystack[i]==needle[j] || j==-1) {
                i++;
                j++;
            }else{
                j = next[j];
            }
            if (j == n) {
                return i - n;
            }
        }
        return -1;
    }
};

int main(){
    char *haystack = "";
    char *needle = "a";
    Solution s;
    cout << s.strStr(haystack, needle) << endl;
};