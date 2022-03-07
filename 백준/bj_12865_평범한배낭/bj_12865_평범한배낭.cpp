#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct thing {
    int w;
    int v;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, K;
	cin >> N >> K;
	
	vector<thing> things(N+1);
	for(int i = 1; i <= N; i++) {
	    thing temp;
	    cin >> temp.w >> temp.v;
	    
	    things[i] = temp;
	}

	
	vector<vector<int>> DP(N+1, vector<int>(K+1, 0));
	
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            int wi = things[i].w;
            int vi = things[i].v;
            
            if(wi > j) {
                DP[i][j] = DP[i-1][j];
            } else {
                DP[i][j] = max(DP[i-1][j], vi + DP[i-1][j-wi]);
            }
        }
    }
    
    cout << DP[N][K];
	return 0;
}