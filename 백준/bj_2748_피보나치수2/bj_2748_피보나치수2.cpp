#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<long> fibo(n+1);
    
    fibo[0] = 0;
    fibo[1] = 1;
    
    for(int i = 2; i < n+1; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    cout << fibo[n];
    
    return 0;
}