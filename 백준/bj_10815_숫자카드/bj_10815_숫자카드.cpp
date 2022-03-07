#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int* arr, int arrSize, int target) {
    // arr가 정렬된 상태일 때
    int index = arrSize/2;
    int low = 0, high = arrSize-1;
    
    while(arr[index] != target) {

        if((high-low)/2 == 0)  {
            // there's no target in array
            return false;
        }
        
        if(arr[index] > target) {
            high = index;
            index = (index+low-1)/2;
        } else {
            low = index;
            index = (index+high+1)/2;
        }
        
    }
    
    return true;
}

int main() {
    int N, M; 
    
    cin >> N;
    int* arrN = new int[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &arrN[i]);
    }
    
    sort(arrN, arrN+N);
    
    cin >> M;
    int* arrM = new int[M];
    for(int i = 0; i < M; i++) {
        scanf("%d", &arrM[i]);
    }

    
    for(int i = 0; i < M; i++) {
        if(binarySearch(arrN, N, arrM[i])) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
    
    return 0;
}