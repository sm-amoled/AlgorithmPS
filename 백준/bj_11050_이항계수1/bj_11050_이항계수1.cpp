#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    int result = 1;
    for(int i = 0; i < K; i++) {
        result *= N - i;
    }
    for(int i = 1; i <= K; i++) {
        result /= i;
    }
       
	cout << result;		
    return 0;
} 