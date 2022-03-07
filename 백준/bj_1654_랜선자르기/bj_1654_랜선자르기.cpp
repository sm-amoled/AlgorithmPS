#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    int* cable;
    int max = 0;
    long left, right, mid;
    int cableCount;
    long result = 0;
    
    cin >> K >> N;
    cable = new int[K];
    
    for(int i = 0; i < K; i++) {
        cin >> cable[i];
        if(max < cable[i]) max = cable[i];
    }
    
    left = 0; right = max;
    while(left <= right) {
        mid = (left+right+1)/2;
        cableCount = 0;
        
        for(int i = 0; i < K; i++) {
            cableCount += cable[i]/mid;
        }
        
        if(cableCount >= N) {
            if(result < mid) result = mid;
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    
    printf("%ld", result);
    
    return 0;
}