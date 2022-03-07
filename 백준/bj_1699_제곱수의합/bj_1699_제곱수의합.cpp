#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> dp(N+1);
    
    dp[0] = 0;
    
    for(int i = 1; i <= N; i++) {
        int temp = 1;
        int min = 100000;
        while (temp*temp <= i) {
            if(dp[i-temp*temp] + 1 < min) {
                min = dp[i-temp*temp] + 1;
            }
            temp++;
        }
        
        dp[i] = min;
    }
    
    cout << dp[N];
    return 0;
}