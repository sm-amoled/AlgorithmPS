#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
      
    int N5 = 0, M5 = 0, NminusM5 = 0;
    int N2 = 0, M2 = 0, NminusM2 = 0;
    
    for(long long i = 2; N/i >= 1; i*=2) {
        N2 += N/i;
    }
    for(long long i = 2; M/i >= 1; i*=2) {
        M2 += M/i;
    }
    for(long long i = 2; (N-M)/i >= 1; i*=2) {
        NminusM2 += (N-M)/i;
    }
    
    for(long long i = 5; N/i >= 1; i*=5) {
        N5 += N/i;
    }
    for(long long i = 5; M/i >= 1; i*=5) {
        M5 += M/i;
    }
    for(long long i = 5; (N-M)/i >= 1; i*=5) {
        NminusM5 += (N-M)/i;
    }
    
    cout << ((N5 - (M5 + NminusM5) < N2 - (M2 + NminusM2))? N5 - (M5 + NminusM5) : N2 - (M2 + NminusM2));
    return 0;
} 