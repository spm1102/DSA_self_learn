/*
Given an unsorted array arr of size n that contains only non negative integers, 
find a sub-array (continuous elements) that has sum equal to s. 
You mainly need to return the left and right indexes(1-based indexing) of that subarray.
In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. 
If no such subarray exists return an array consisting of element -1.

Input: arr[] = [1,2,3,7,5], n = 5, s = 12
Output: 2 4
Explanation: The sum of elements from 2nd to 4th position is 12.
*/

#include<iostream>
using namespace std;

int main() {
    int n, s;
    cout << "Nhap n "; cin >> n;
    cout << "Nhap s "; cin >> s;
    int arr_src[n];
    for(int i = 0; i < n; i++) {
        cin >> arr_src[i];
    }
    bool flag = true;
    int sub_arr[2], count = 0;
    while(flag) {
        int sum = 0;
        for(int i = count; i <= n; i++){
            sum += arr_src[i];  
            sub_arr[0] = count;
            if(sum == s){
                sub_arr[1] = i;
                flag = false;
                break;
            }
            else if(sum > s){
                break;
            }
            if(count == n && sum != s) {
                cout << "-1";
            }
        }
        count++;
    }
    for (int i = 0; i < 2; i++){
        cout << sub_arr[i] + 1 << ' ';
    }
    return 0;
}
