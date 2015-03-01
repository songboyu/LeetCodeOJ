/*
[Two Sum]

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result;
    map<int,int> mp;
    for(int i=0; i<numbers.size(); i++){
        if(mp.count(target-numbers[i])){
            result.push_back(mp[target-numbers[i]]);
            result.push_back(i+1);
            break;
        }else{
            mp[numbers[i]] = i+1;
        }
    }
    return result;
}

int main(){
    vector<int> numbers = {2,4,9,6,7,3,8};
    vector<int> result = twoSum(numbers, 15);
    for(vector<int>::iterator it=result.begin(); it!=result.end(); it++){
        cout << *(it) << endl;
    }
    return 0;
}