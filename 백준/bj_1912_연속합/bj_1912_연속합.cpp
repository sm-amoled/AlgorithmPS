#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N); 
    vector<long> arrSum(N);
    
    long maxSum = 0;
    
    // set initial value
    cin >> arr[0];
    arrSum[0] = arr[0];
    maxSum = arr[0];
    
    for(int i = 1; i < N; i++) {
        cin >> arr[i];
        
        // arrSum[i-1]+arr[i] → 수열이 증가하고 있음
        // arr[i] → 앞에 합치는 것보다 arr[i]를 고르는 것이 더 큼
        arrSum[i] = max(arrSum[i-1]+arr[i], (long)arr[i]);
        
        // 기존의 sum이 더 큰지, 새로 만든 arrSum[i]가 더 큰지 비교
        maxSum = max(arrSum[i], maxSum);
    }
    
    cout << maxSum;
    
    return 0;
}