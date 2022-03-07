#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> p(N);
    vector<int> t(N);
    vector<int> dp(N+1, 0);
    
    for(int i = 0; i < N; i++) {
        cin >> t[i] >> p[i];
    }
    
    int result = 0;
    
    for(int i = 0; i < N; i++) {
        if(i+t[i] <= N) {
            dp[i+t[i]] = max(dp[i+t[i]], dp[i]+p[i]);
            result = max(result, dp[i+t[i]]);
        }
        
        dp[i+1] = max(dp[i+1], dp[i]);
        result = max(result, dp[i+1]);
    }
    
    cout << result;
    return 0;
}