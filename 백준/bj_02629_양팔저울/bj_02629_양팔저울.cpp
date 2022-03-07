#include <iostream>
#include <vector>
    
using namespace std;

int N, M, val;
vector<int> weight;
bool dp[31][40001]; // 가능하다면 true


void available(int idx, int wgh) {
    if(idx > N || dp[idx][wgh]) return;
    
    dp[idx][wgh] = true;
    available(idx + 1, wgh + weight[idx]);
    available(idx + 1, abs(wgh - weight[idx]));
    available(idx + 1, wgh);
}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> val;
        weight.push_back(val);
    }
    available(0, 0);
    
    cin >> M;
    
    for(int i = 0; i < M; i++) {
        cin >> val;
        
        if(dp[N][val]) cout << "Y ";
        else cout << "N ";
    }
    
    return 0;
}
