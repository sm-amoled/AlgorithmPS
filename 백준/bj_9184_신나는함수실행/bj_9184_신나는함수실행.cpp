#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while(true) {
    	int a, b, c;
        cin >> a >> b >> c;
	
	    if(a == -1 && b == -1 && c == -1) return 0;
	    
	    cout << "w(" << a << ", " << b << ", " << c << ") = ";
	    
	    if(a <= 0 || b <= 0 || c <= 0) {
            cout << 1 << '\n';
            continue;
	    }
	    
	    
	    if(a > 20 || b > 20 || c > 20) {
	        a = 20;
	        b = 20;
	        c = 20;
	    }
	    
	    vector<vector<vector<int>>> dp(a+1, vector<vector<int>>(b+1, vector<int>(c+1, 0)));
	    
	    for(int i = 0; i <= a; i++) {
	        for(int j = 0; j <= b; j++) {
	            for(int k = 0; k <= c; k++) {
	                if(i == 0 || j == 0 || k == 0) {
	                    dp[i][j][k] = 1;
	                } else {
	                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
	                }
	            }
	        }
	    }
	    cout << dp[a][b][c] << '\n';
	}
	
	
	return 0;
}