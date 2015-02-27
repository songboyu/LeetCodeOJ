/*
[ZigZag Conversion]

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
#include <iostream>
using namespace std;

string convert(string s, int nRows) {
    int len = s.length();
    string result;
    result.resize(len);
    if(nRows<=1 || nRows>=len){
        return s;
    }
    int k = 0;
    for(int i=0; i<nRows; i++){
        for(int j=i; j<len; j+=2*nRows-2){
            if(j%(nRows-1)!=0){
                result[k] = s[j];
                int tmp = j+2*(nRows-1-(j%(nRows-1)));
                if(tmp<len)
                    result[++k] = s[tmp];
            }else{
                result[k] = s[j];
            }
            k++;
        }
    }
    return result;
}

int main(){
    cout << convert("PAYPALISHIRING", 3) << endl;
    return 0;
}