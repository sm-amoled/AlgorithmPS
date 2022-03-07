#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<long> arr(N);
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int left = 0, right = N-1;
    int minLeft, minRight;
    long minValue = 1000000000;
    
    if(arr[left] > 0 && arr[right] > 0) {
        printf("%ld %ld\n", arr[left], arr[left+1]);
        return 0;
    } else if (arr[left] < 0 && arr[right] < 0) {
        printf("%ld %ld\n", arr[right-1], arr[right]);
        return 0;
    }
    
    while(left < right) {
        long sum = arr[left]+arr[right];
        
        if(minValue > abs(sum)) {
            minLeft = left;
            minRight = right;
            minValue = abs(sum);
        }
        
        if(sum < 0) {
            left++;
        } else if(sum > 0){
            right--;
        } else {
            break;
        }
    }
    
    printf("%ld %ld\n", arr[minLeft], arr[minRight]);
    
    return 0;
}