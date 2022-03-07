#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> stair(n+1);
    stair[0] = 0;
    for(int k = 1; k < n+1; k++) {
        cin >> stair[k];
    }
    
    vector<int> score(n+1, 0);
    for(int k = 1; k < n+1; k++) {
        
        if(k>2) {
            score[k] = max(stair[k]+score[k-2], stair[k]+stair[k-1]+score[k-3]);
        } else {
            if (k == 1) {
                score[k] = stair[k];    
            } else {
                score[k] = max(stair[k]+score[k-1], stair[k]+score[k-2]);
            }
        }
    }
    cout << score[n];

    return 0;
}