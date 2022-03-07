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
        vector<int> arr(n+1);
        
        for(int k = 1; k <= n; k++) {
            if(k > 3) {
                arr[k] = arr[k-1] + arr[k-2] + arr[k-3];
            } else{
                if(k==1) arr[k] = 1;
                else if (k==2) arr[k] = 2;
                else arr[k] = 4;
            }
        }
        printf("%d\n", arr[n]);
    }

    return 0;
}