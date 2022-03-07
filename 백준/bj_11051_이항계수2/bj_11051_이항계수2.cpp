#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    long temp1, temp2;
    vector<long> dp(2, 1);
    for(int i = 1; i < N; i++) {
        dp.push_back(1);
        temp1 = 1;
        for(int j = 1; j <= i; j++) {
            temp2 = dp[j];
            dp[j] = (temp1 + dp[j])%10007;
            temp1 = temp2;
        }
    }
    
    cout << dp[K];
    return 0;
}