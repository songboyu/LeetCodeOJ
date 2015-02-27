/*
[Median of Two Sorted Arrays ]

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */
#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    vector<int> C;
    int i=0, j=0;
    while(i<m && j<n){
        while(A[i] <= B[j] && i<m){
            C.push_back(A[i++]);
        }
        while(A[i] > B[j] && j<n){
            C.push_back(B[j++]);
        }
    }
    while(i<m){
        C.push_back(A[i++]);
    }
    while(j<n){
        C.push_back(B[j++]);
    }
    /*for(vector<int>::iterator it=C.begin(); it!=C.end(); ++it){
		cout << *(it) << endl;
    }*/
    double result = 0;
    int size = C.size();
    if(size % 2){
        result = C[(size+1)/2-1];
    }else{
        result = ((double)(C[size/2-1] + C[size/2]))/2;
    }
    return result;
}

int main(){
    int A[] = {2,4,5,7,8,12,46,77,78,898};
    int B[] = {4,6,7,13,23,45,46};
    cout << findMedianSortedArrays(A, 10, B, 7) << endl;
    return 0;
}