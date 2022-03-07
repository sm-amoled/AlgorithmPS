#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	vector<int> app(N+1, 0);
	vector<int> cost(N+1, 0);
	
	int maxCost = 0;
	for(int i = 1; i <= N; i++) {
	    cin >> app[i];
	}
	for(int i = 1; i <= N; i++) {
	     cin >> cost[i];
	    maxCost += cost[i];
	}
	
	vector<vector<int>> dp(N+1, vector<int>(maxCost+1, 0));
	
	for(int index = 1; index <= N; index++) {
	    for(int c = 1; c <= maxCost; c++) {
	        if(c >= cost[index]) {
	            dp[index][c] = max(dp[index-1][c], dp[index-1][c-cost[index]] + app[index]);    
	        } else {
	            dp[index][c] = max(dp[index-1][c], dp[index][c-1]);
	        }
	        
	    }
	}
	
	for(int i = 0; i <= maxCost; i++) {
	    if(dp[N][i] >= M) {
	        cout << i;
	        break;
	    }
	}
	
	return 0;
}