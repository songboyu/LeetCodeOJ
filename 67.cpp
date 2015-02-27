/*
[Add Binary]

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */
#include <iostream>
using namespace std;

string addBinary(string a, string b) {
    string c;
    int sign = 0;
    int i = a.length()-1;
    int j = b.length()-1;
    while(i>=0 && j>=0){
        if(a.at(i) + b.at(j) - '0'*2 == 2){
            if(sign){
                c.insert(0, 1, '1');
            }else{
                c.insert(0, 1, '0');
            }
            sign = 1;
        }else if(a.at(i) + b.at(j) - '0'*2 == 0){
            if(sign){
                c.insert(0, 1, '1');
            }else{
                c.insert(0, 1, '0');
            }
            sign = 0;
        }else{
            if(sign){
                c.insert(0, 1, '0');
                sign = 1;
            }else{
                c.insert(0, 1, '1');
                sign = 0;
            }
        }
        i--;
        j--;
    }
    while(i>=0){
        if(a.at(i) == '1'){
            if(sign){
                c.insert(0, 1, '0');
                sign = 1;
            }else{
                c.insert(0, 1, '1');
                sign = 0;
            }
        }else{
            if(sign){
                c.insert(0, 1, '1');
            }else{
                c.insert(0, 1, '0');
            }
            sign = 0;
        }
        i--;
    }
    while(j>=0){
        if(b.at(j) == '1'){
            if(sign){
                c.insert(0, 1, '0');
                sign = 1;
            }else{
                c.insert(0, 1, '1');
                sign = 0;
            }
        }else{
            if(sign){
                c.insert(0, 1, '1');
            }else{
                c.insert(0, 1, '0');
            }
            sign = 0;
        }
        j--;
    }
    if(sign == 1){
        c.insert(0, 1, '1');
    }
    return c;
}

int main(){
    string a = "111";
    string b = "11";
    cout << addBinary(a, b) << endl;
    return 0;
}