#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> value(N);
    for(int i = 1; i <= N; i++) {
        cin >> value[N-i];
    }
    
    int coinCount = 0;
    for(int i = 0; i < N; i++) {
        if(K >= value[i]) {
            K -= value[i];
            coinCount++;
            i--;
        }
    }
    
    cout << coinCount;
    
	return 0;
} 