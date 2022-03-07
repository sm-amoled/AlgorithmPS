#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int testCase = 0; testCase < T; testCase++) {
        int N;
        cin >> N;
        
        vector<int> note1(N);
        for(int i = 0; i < N; i++) {
            cin >> note1[i];
        }
        sort(note1.begin(), note1.end());
        
        int M;
        cin >> M;
        
        int numb;
        for(int i = 0; i < M; i++) {
            cin >> numb;
            
            int left = 0, right = note1.size()-1;
            int result;
            while(left <= right) {
                int mid = (left+right)/2;
                
                if(note1[mid] > numb) {
                    right = mid - 1;
                } else {
                    result = mid;
                    left = mid + 1;
                }
            }
            
            if(note1[result] == numb) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}