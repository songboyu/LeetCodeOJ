/*
[Largest Number]

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
 */
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int shouldBeFront(int a, int b){
        string strA, strB;
        stringstream ssA, ssB;

        ssA << a;
        ssA >> strA;

        ssB << b;
        ssB >> strB;

        return (strA + strB) > (strB + strA);
    }
    void quick_sort(vector<int> &s, int l, int r){
        if(l < r) {
            int key = s[l];
            int i = l;
            int j = r;
            while (i < j) {
                while (i < j && shouldBeFront(key, s[j])) j--;
                if(i < j)   s[i++] = s[j];

                while (i < j && shouldBeFront(s[i], key)) i++;
                if(i < j)   s[j--] = s[i];
            }
            s[i] = key;
            quick_sort(s, l, i - 1);
            quick_sort(s, i + 1, r);
        }
    }
    string largestNumber(vector<int> &num) {
        string ans;
        quick_sort(num, 0, num.size()-1);

        for(vector<int>::iterator it=num.begin(); it!=num.end(); it++) {
            stringstream ss;
            string s;

            ss << *(it);
            ss >> s;

            ans += s;
        }
        return ans[0]=='0' ? "0" : ans;
    }
};

//c++11
class Solution2 {
public:
    string largestNumber(vector<int> &num) {
        vector<string> strs;
        for_each(num.begin(), num.end(), [&](int i) {
            strs.push_back(to_string(i));
        });
        sort(strs.begin(), strs.end(), [&](const string& a, const string& b) {
            return (a + b) > (b + a);
        });
        string ans = "";
        for_each(strs.begin(), strs.end(), [&](string& i) {
            if (ans == "" && i == "0") return;
            ans += i;
        });
        return ans == "" ? "0" : ans;
    }
};

int main(){
    vector<int> num = {3, 30, 34, 5, 9};
//    vector<int> num = {0, 0, 0, 0};
    Solution2 s;
    cout << s.largestNumber(num) << endl;
    return 0;
}