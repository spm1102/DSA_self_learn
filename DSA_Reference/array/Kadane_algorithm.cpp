//Given an integer array arr[]. Find the contiguous sub-array
// (containing at least one number) that has the maximum sum and return its sum.
/*
Input: arr[] = [1, 2, 3, -2, 5]
Output: 9
Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    
    int current_sum = 0;
    int max_sum = INT_MIN;
    for(int i = 0; i < n; i++){
        current_sum += arr[i];
        if(current_sum > max_sum) {
            max_sum = current_sum;
        }
        if(current_sum < 0) {
            current_sum = 0;
        }
    }
    cout << max_sum;

    return 0;
}