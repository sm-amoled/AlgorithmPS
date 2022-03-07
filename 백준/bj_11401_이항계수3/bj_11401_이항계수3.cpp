#include <iostream>

using namespace std;
int mod = 1000000007;

long long devidePow(long long exp, long long value) {
    if(exp == 1) return value % mod;

    long long temp = devidePow(exp/2, value);
    if(exp % 2) {
        return (((temp * temp) % mod) * value) % mod;
    } else {
        return (temp * temp) % mod;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    long long A = 1;
    for(int i = 1; i <= N; i++) {
        A *= i;
        A = A % mod;
    }

    long long B = 1, C = 1;
    for(int i = 1; i <= K; i++) {
        B *= i;
        B = B % mod;
    }
    for(int i = 1; i <= N-K; i++) {
        C *= i;
        C = C % mod;
    }

    long long result = devidePow(mod-2, (B*C) % mod);
    result = (A * result) % mod;
    
    cout << result;
    return 0;
}