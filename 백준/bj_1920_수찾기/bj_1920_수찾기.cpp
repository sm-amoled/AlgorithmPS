#include <iostream>
#include <algorithm>

using namespace std;

bool binarySearch(int* arr, int arrSize, int target) {
    int index = 0;
    int size = arrSize;
    
    for(int jump = size/2; jump > 0; jump /= 2) {
        while(index+jump < size && arr[index+jump] <= target) {
            index += jump;
        }
    }
    if(arr[index] == target) return true;
    return false;
}

int main() {
    int N, M;
    
    cin >> N;
    int* A = new int[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, A+N);
    
    cin >> M;
    int* B = new int[M];
    for(int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }
    
    for(int i = 0; i < M; i++) {
        printf("%d\n", binarySearch(A, N, B[i])? 1:0);
    }
    
    return 0;
}