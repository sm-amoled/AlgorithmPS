#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	vector<int> coin(N);
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	
	sort(coin.begin(), coin.end());
	unique(coin.begin(), coin.end());
    
	vector<int> dp(K+1, K+1);
	dp[0] = 0;
	for (int i = 1; i < K+1; i++) {
        for(auto x : coin) {
            if(x <= i) {
                dp[i] = (dp[i] < dp[i-x]+1)? dp[i] : dp[i-x] + 1;
            } else {
                break;
            }
        }
	}
    
	cout << ((dp.back() == K+1)? -1:dp.back());
	return 0;
}