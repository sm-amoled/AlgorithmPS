#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tile(n);
    
    if(n < 3) {
        printf("%d\n", (n==1)? 1:3);
        return 0;
    }
    tile[0] = 1;
    tile[1] = 3;
    
    for(int i = 2; i < n; i++) {
        tile[i] = tile[i-1] + tile[i-2]*2;
        tile[i] %= 10007;
    }
    
    cout << tile[n-1];
    return 0;
}