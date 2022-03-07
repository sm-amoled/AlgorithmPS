#include <iostream>
#include <vector>


using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> dp (10, vector<int>(N, 0));
    
    // N=1일때의 값 초기화
    for(int i = 0; i < 10; i++) {
        if(i==0) {
            dp[i][0] = 0;
            continue;
        }
        dp[i][0] = 1;
    }
    
    // k는 자릿수, i는 0~9
    for(int k = 1; k < N; k++) {
        for(int i = 0; i < 10; i++) {
            if(i==0) {
                dp[0][k] += dp[1][k-1];
            } else if (i < 9) {
                dp[i][k] += dp[i-1][k-1];
                dp[i][k] += dp[i+1][k-1];
            } else {
                dp[9][k] += dp[8][k-1];
            }
            dp[i][k] %= 1000000000;
        }
    }
    
    long result = 0;
    for(int i = 0; i <10; i++) {
        result += dp[i][N-1];
        result %= 1000000000;
    }
    
    cout << result;
    return 0;
}