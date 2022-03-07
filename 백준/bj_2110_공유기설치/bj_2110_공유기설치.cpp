#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;
    
    cin >> N >> C;
    vector<int> house(N);
    for(int i = 0; i < N; i++){
        cin >> house[i];
    }
    
    sort(house.begin(), house.end());
    
    int left = 1, right = house[N-1] - house[0];
    int answer;
    while(left<=right) {
        int mid = (left+right)/2;
        int count = 1;
        int start = house[0];
        
        for(int i = 1; i < N; i++) {
            int d = house[i]-start;
            if(d>=mid) {
                start = house[i];
                count++;
            }
        }
        
        if(count >= C) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer;
    return 0;
}