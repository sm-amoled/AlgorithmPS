#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    vector<int> lds;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // initial value
    lds.push_back(arr[0]);
    for(int i = 1; i < N; i++) {
        if(lds.back() < arr[i]) {
            lds.push_back(arr[i]);
        } else {
            int left = 0, right = lds.size();
            int mid;
            while(left <= right) {
                mid = (left+right)/2;
            
                if(lds[mid] <= arr[i]) {
                    left=mid+1;
                } else {
                    right=mid-1;
                }
            }
            lds[left] = arr[i];
        }
    }
    
    printf("%d\n", (int)lds.size());
    return 0;
}