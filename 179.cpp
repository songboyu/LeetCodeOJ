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
        int i = a, j = b;
        int x = a*10, y = b*10;

        while(j /= 10) x *= 10;
        while(i /= 10) y *= 10;

        x += b;
        y += a;

        return x>y ? 1 : 0;
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

        for(vector<int>::iterator it=num.begin(); it!=num.end(); it++){
            stringstream ss;
            ss << *(it);
            string n;
            ss >> n;
            ans += n;
        }
        return ans;
    }
};

int main(){
    vector<int> num = {3, 30, 34, 5, 9};
    Solution s;
    cout << s.largestNumber(num) << endl;
}