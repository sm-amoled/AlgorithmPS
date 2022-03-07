#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> dp(N+1, 0);
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i < N+1; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%15746; 
        
    }
    
    cout << dp[N];
    return 0;
}