#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> LDS;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    LDS.push_back(arr[0]);
    for(int i = 0; i < N; i++) {
        if(LDS.back() < arr[i]) {
            LDS.push_back(arr[i]);
            continue;
        } 
        
        int left = 0, right = LDS.size()-1;
        while(left <= right) {
            int mid = (left + right)/2;
            
            if(LDS.at(mid) >= arr[i]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        if(LDS.at(left) > arr[i]) {
            LDS[left] = arr[i];
        }
    }
    
    printf("%d", (int)LDS.size());
    
    return 0;
}