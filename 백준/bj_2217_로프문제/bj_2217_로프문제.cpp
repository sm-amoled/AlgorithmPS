#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int sum=0; 
    int* arr;
    
    scanf("%d", &N);
    arr = new int[N];
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    sort(arr, arr+N);
    
    for(int i = 0; i < N; i++) {
        if(sum < arr[i] * (N-i)) {
            sum = arr[i] * (N-i);
        } 
        // else {
        //     break;
        // }
    }
    
    printf("%d", sum);
    return 0;
}