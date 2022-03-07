#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> costR(n+1);
    vector<int> costG(n+1);
    vector<int> costB(n+1);
    
    int R, G, B;
    for(int k = 1; k < n+1; k++) {
        cin >> R >> G >> B;
        
        // costX[k]는 k번째 집에 해당 색을 골랐을 때 최소 비용
        costR[k] = min(costG[k-1], costB[k-1]) + R;
        costG[k] = min(costR[k-1], costB[k-1]) + G;
        costB[k] = min(costG[k-1], costR[k-1]) + B;
    }
    
    cout << min(min(costR[n], costG[n]), costB[n]);

    return 0;
}