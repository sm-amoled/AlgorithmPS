#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long mix(long a, long b) {
    return (a+b > 0)? a+b: 0-(a+b);
}

int main() {
    int N;
    cin >> N;
    vector<long> arr(N);
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    int minusIndex = 0, plusIndex = N-1;
    int minusIndex0 = 0, plusIndex0 = N-1;
    long minSum = mix(arr[minusIndex], arr[plusIndex]);
    
    while(minusIndex < plusIndex) {
        long sum = mix(arr[minusIndex], arr[plusIndex]);
        
        if(sum < minSum) {
            minusIndex0 = minusIndex;
            plusIndex0 = plusIndex;
            
            minSum = sum;
        }
        
        if(arr[minusIndex] + arr[plusIndex] > 0) {
            plusIndex--;
        } else {
            minusIndex++;
        }
    }
    
    
    printf("%ld %ld", arr[minusIndex0], arr[plusIndex0]);
    
    return 0;
}