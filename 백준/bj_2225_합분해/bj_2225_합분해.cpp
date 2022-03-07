#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int N, K;
	cin >> N >> K;
	
	vector<vector<int>> dp(K, vector<int> (N+1, 0));
    
    long sum = 1;
    long nextSum;
    
    for(int i = 1; i < K; i++) {
        nextSum = 0;
        
        for(int j = 0; j <= N; j++) {
            dp[i][j] = sum % 1000000000;
            sum -= dp[i-1][j];
            
            nextSum += dp[i][j];
        }
        sum = nextSum;
    }
    
    cout << sum % 1000000000;
    
	return 0;
}

  	