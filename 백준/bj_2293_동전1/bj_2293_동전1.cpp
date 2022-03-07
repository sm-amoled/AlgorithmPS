#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> coin(N);
    vector<int> dp(K+1, 0);
    
    for(int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end());
       
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K+1; j++) {
            if(j-coin[i] >= 0) {
                dp[j] += dp[j-coin[i]];
            }
            
            if(coin[i] == j) {
                dp[j] += 1;
            }
        }
    }
    
    cout << dp[K];
    return 0;
}