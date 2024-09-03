#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> mp;
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;
    cout << mp.size() << endl;
    return 0;
}