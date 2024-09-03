/*
Given an array arr[] of size n of non-negative integers. 
Each array element represents the maximum length of the jumps that can be made forward from that element. 
This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
Find the minimum number of jumps to reach the end of the array starting from the first element. 
If an element is 0, then you cannot move through that element.
Note:  Return -1 if you can't reach the end of the array.


Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}, n = 11
Output: 3 
Explanation:First jump from 1st element to 2nd element with value 3.
From here we jump to 5th element with value 9, and from here we will jump to the last. 
*/

#include<iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int curr_index = 0;
    int index_max = 0;
    int total_jump = 0;
    int minimum_jump_times = 0;
    while(total_jump < n) {
        int max_val = arr[curr_index + 1];
        int curr_value = arr[curr_index];
        minimum_jump_times++;
        for(int i = curr_index + 1; i < curr_index + curr_value + 1; i++) {
            if(max_val < arr[i + 1] && i + 1 + arr[i + 1] <= n && arr[i + 1 + arr[i + 1]] != 0){
                max_val = arr[i + 1];
                index_max = i + 1;
            }
        }
        curr_index = index_max;
        curr_value = arr[curr_index];
        if(curr_index + curr_value >= n - 1){
            cout << minimum_jump_times + 1 << endl;
            break;
        }
        total_jump = curr_index;
    }
    cout << "Hello" << endl;
    return 0;
}