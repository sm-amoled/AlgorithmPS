#include <iostream>
#include <vector>


using namespace std;

int main() {
    int t;
    cin >> t;
    for(int k = 0; k < t; k++) {
        int n;
        cin >> n;
        vector<long> spiral(n);
        
        if(n < 5) {
            cout << ((n-1)/3)+1 << "\n";
            continue;
        }
        
        for(int i = 0; i<5; i++) {
            spiral[i] = i/3 + 1;
        }
        
        for(int i = 5; i < n; i++) {
            spiral[i] = spiral[i-1] + spiral[i-5];
        }
        
        cout << spiral[n-1] << "\n";
    }
    return 0;
}