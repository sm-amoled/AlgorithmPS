#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    
    cin >> N;
    cin >> K;
    
    int left = 1, right = K;
    int result;
    while(left <= right) {
        int count = 0;
        int mid = (left + right) /2;
        for(int i = 1; i <= N; i++) {
            count += min(mid/i, N);
        }
        
        if(count >= K) {
            right = mid-1;
            result = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result;
    
    return 0;
}