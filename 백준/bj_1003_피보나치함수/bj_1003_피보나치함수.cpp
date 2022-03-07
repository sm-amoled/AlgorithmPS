#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        if(n == 0) {
            printf("1 0\n");
            continue;
        }
        
        vector<int> arr(n+1);
        
        for(int k = 0; k < n+1; k++) {
            if(k > 1) {
                arr[k] = arr[k-1] + arr[k-2];
            } else {
                arr[k] = k;
            }
        }
        
        printf("%d %d\n", arr[n-1], arr[n]);
    }
    return 0;
}