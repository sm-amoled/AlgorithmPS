#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<long> pinary(n+1);
    long sum = 1;
    
    pinary[1] = 1;
    for(int i = 2; i <= n; i++) {
        sum += pinary[i-2];
        pinary[i] = sum;
    }
    
    cout << pinary[n];
    return 0;
}