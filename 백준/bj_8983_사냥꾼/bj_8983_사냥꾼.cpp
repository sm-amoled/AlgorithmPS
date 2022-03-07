#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int M, N, L;
    int killCount = 0;
    
    cin >> M >> N >> L;
    
    vector<int> m(M);
    
    for(int i = 0; i < M; i++) {
        cin >> m[i];    
    }
    
    sort(m.begin(), m.end());
    
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        
        if(y > L) continue;
        
        int lower = x+y-L, upper = x-y+L;
        
        int left = 0, right = m.size()-1;
        while(left <= right) {
            int mid = (left+right) / 2;
                
            if(lower <= m[mid] && m[mid] <= upper) {
                killCount++;
                break;
            } else if (m[mid] < lower) {
                left = mid + 1;
            } else if (upper < m[mid]) {
                right = mid - 1;
            }
        }
    }
    
    cout << killCount;
    return 0;
}