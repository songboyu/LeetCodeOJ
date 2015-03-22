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
    int* makeMap(char *needle){
        int n = strlen(needle);
        int cMap[] = {0,0,0,0,1,2,0};
        for(int i=0; i<n; i++){

        }
        return cMap;
    }
    int strStr(char *haystack, char *needle) {
        int *cMap = makeMap(needle);
        int m = strlen(haystack);
        int n = strlen(needle);
        int i = 0,j = 0;

        while(i<m && j<n) {
            while(haystack[i]!=needle[j] && j==0){
                i++;
            }
            while (haystack[i]==needle[j] && j<n) {
                i++;
                j++;
            }
            if (j == n) {
                return i - n;
            } else {
                j = cMap[j - 1];
            }
        }
        return -1;
    }
};

int main(){
    char *haystack = "BBC ABCDAB ABCDABCDABDE";
    char *needle = "ABCDABD";
    //Ó¦·µ»Ø15
    Solution s;
    cout << s.strStr(haystack, needle) << endl;
};