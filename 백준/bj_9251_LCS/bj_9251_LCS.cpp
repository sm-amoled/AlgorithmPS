#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string A, B;
	cin >> A >> B;
	
	A = '0' + A;
	B = '0' + B;
	
	vector<vector<int>> dp(A.size(), vector<int> (B.size(), 0));
	
	for(int i = 1; i < A.size(); i++) {
	    for(int j = 1; j < B.size(); j++) {
	        if(A[i] == B[j]) {
	            dp[i][j] = dp[i-1][j-1] + 1;
	        } else {
	            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	        }
	    }
	}
	
    cout << dp[A.size()-1][B.size()-1];
	return 0;
}