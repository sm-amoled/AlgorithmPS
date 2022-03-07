#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    
    for(int k = 0; k < n+1; k++) {
        if(k > 1) {
            arr[k] = arr[k-1] + arr[k-2];
            arr[k] %= 10007;
        } else {
            arr[k] = 1;
        }
    }
    cout << arr[n];

    return 0;
}