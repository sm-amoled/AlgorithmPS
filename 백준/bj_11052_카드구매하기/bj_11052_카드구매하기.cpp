#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> card(N+1);
    
    for(int i = 1; i <= N; i++) {
        cin >> card[i];
        
        for(int k = 1; k <= i; k++) {
            card[i] = (card[i] > card[k]+card[i-k])? card[i]:card[k]+card[i-k];
        }
    }
    
    cout << card[N];
    return 0;
}