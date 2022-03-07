#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T; 
    cin >> T;
    for(int k = 0; k < T; k++) {
        
        int N;
        cin >> N;
        vector<vector<int>> sticker(2,vector<int>(N, 0));
        vector<vector<int>> dp(2,vector<int>(N));

        for(int i = 0; i < N; i++) {
            cin >> sticker[0][i];
        }
        for(int i = 0; i < N; i++) {
            cin >> sticker[1][i];
        }
        
        if(N == 1) {
            cout << max(sticker[0][0], sticker[1][0]);  
            continue;
        } else if (N == 2) {
            cout << max(sticker[0][0] + sticker[1][1], sticker[1][0] + sticker[0][1]);  
            continue;
        }

        // DP
        int maxValue = 0;
        
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        maxValue = (maxValue > max(dp[0][0], dp[1][0]))? maxValue:max(dp[0][0], dp[1][0]);
        
        dp[0][1] = dp[1][0] + sticker[0][1];
        dp[1][1] = dp[0][0] + sticker[1][1];
        maxValue = (maxValue > max(dp[0][1], dp[1][1]))? maxValue:max(dp[0][1], dp[1][1]);
        
        for(int i = 2; i < N; i++) {
            dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
            maxValue = (maxValue > max(dp[0][i], dp[1][i]))? maxValue:max(dp[0][i], dp[1][i]);
        }
        
        cout << maxValue << "\n";
    }   
    return 0;
}