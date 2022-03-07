#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        int N, M;
        cin >> N >> M;
        
        if(N == 1) {
            cout << M << '\n';
            continue;
        }
        
        vector<long> dp(M);    
        for(int i = 0; i < M; i++) {
            dp[i] = M-i;
        }
        
        
        for(int i = 2; i < N; i++) {
            for(int j = 0; j < M; j++) {
                long temp = 0;
                for(int k = j+1; k < M; k++) {
                    temp += dp[k];
                }
                dp[j] = temp;
            }   
        }
        
        long sum = 0;
        for(int i = 1; i < M; i++) {
            sum += dp[i];
        }
        cout << sum << '\n';
    }
 
    
    return 0;
}