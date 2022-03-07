#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    if(N == 1) {
        cout << 10 << '\n';
        return 0;
    }
    
    vector<long> dp(10);    
    for(int i = 0; i < 10; i++) {
        dp[i] = 10-i;
    }
    
    
    for(int i = 2; i < N; i++) {
        for(int j = 0; j < 10; j++) {
            long temp = 0;
            for(int k = j; k < 10; k++) {
                temp += dp[k];
            }
            dp[j] = temp % 10007;
        }   
    }
    
    
    long sum = 0;
    for(auto x : dp) {
        sum += x;
    }
    cout << sum%10007 << '\n';
 
    
    return 0;
}