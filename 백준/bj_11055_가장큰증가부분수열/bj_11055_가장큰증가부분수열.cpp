#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    // 입력    
    vector<int> input(N);
    for(int i = 0; i < N; i++) cin >> input[i];
    
    // DP
    vector<int> sum(N);
    int maxSum = 0;
    for(int i = 0; i < N; i++) {
        int max = 0;
        for(int k = 0; k < i; k++) {
            if(input[i] > input[k]) {
                max = (max > sum[k])? max:sum[k];
            }
        }
        sum[i] = max + input[i];
        if(sum[i] > maxSum) {
            maxSum = sum[i];
        }
    }
    cout << maxSum;
    
    return 0;
}