#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	
	while(T--) {
	    int K;
	    cin >> K;
	    
	    vector<int> chapter(K+1);
	    vector<int> sum(K+1, 0);
	    
	    for(int i = 1; i <= K; i++) {
	        cin >> chapter[i];
	        sum[i] = sum[i-1] + chapter[i];
	    }
	    
	    vector<vector<int>> dp(K+1, vector<int>(K+1, 0));
        
	    for(int length = 1; length < K; length++) {
	        for(int start = 1; start+length <= K; start++) {
	            int end = start+length;
	            dp[start][end] = INT_MAX;
	            
	            for(int mid = start; mid < end; mid++) {
	                dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid+1][end] + sum[end] - sum[start-1]);
	            }
	        }
	    }
	    cout << dp[1][K] << '\n';
    }
	
	return 0;
}