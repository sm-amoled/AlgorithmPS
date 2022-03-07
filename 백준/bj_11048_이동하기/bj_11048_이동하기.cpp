#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int M, N;
    cin >> M >> N;
    
    vector<vector<int>> dp(M+1, vector<int> (N+1, 0));
    
    int input;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> input;   
            dp[i][j] += (input + ((dp[i-1][j] > dp[i][j-1])? dp[i-1][j] : dp[i][j-1]));  
        }
    }
    
    cout << dp[M][N];
    return 0;
}