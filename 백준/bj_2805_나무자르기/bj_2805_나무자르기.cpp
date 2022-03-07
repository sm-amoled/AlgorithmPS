#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int M, N;
    int max = 0;
    int left, right;
    int result = 0;
    
    cin >>  N >> M;
    int* tree = new int[N];
    
    for(int i = 0; i < N; i++) {
        cin >> tree[i];
        if(tree[i]>max) max=tree[i];
    }
    
    left = 0; right = max;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        long total = 0;

        for (int i = 0; i < N; i++) {
            if (mid < tree[i]) {
                total += tree[i]-mid;
            }
        }
        
        if(total >= M) {
            if(result < mid)
                result = mid;
            left = mid + 1;    
        } else {
            right = mid - 1;
        }
    }
    
    printf("%d", result);   
}