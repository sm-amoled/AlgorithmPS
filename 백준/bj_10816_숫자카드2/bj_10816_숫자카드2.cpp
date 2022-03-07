#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
        cin.tie(0);



    int N;
    cin >> N;
    vector<int> card(N);
    
    for(int i = 0; i < N; i++) {
        cin >> card[i];
    }
    
    sort(card.begin(), card.end());
    
    int M;
    cin >> M;
    
    for(int i =0; i < M; i++) {
        int num;
        cin >> num;
        
        cout << upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num) << " ";
    }
    return 0;
}