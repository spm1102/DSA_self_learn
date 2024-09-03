
// Print out the missing index
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        if(arr[i] != i) {
            cout << i;
            break;
        }
    }
    return 0;
}

