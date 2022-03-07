#include <iostream>
#include <algorithm>
using namespace std;
void indexMergeSort(int* arr, int* indexArr, int left, int right);
void merge(int* arr, int* indexArr, int left, int mid, int right);

void indexMergeSort(int* arr, int* indexArr, int left, int right) {
    if(left < right) {
        int mid = (left+right)/2+1;
        
        indexMergeSort(arr, indexArr, left, mid-1);
        indexMergeSort(arr, indexArr, mid, right);
        
        merge(arr, indexArr, left, mid, right);
    }
}

void merge(int* arr, int* indexArr, int left, int mid, int right) {
    int i = left, j = mid-1, k = mid, l = right;
    int* sorted = new int[l-i+1];
    int index = 0;
    
    while(i <= j && k <= l) {
        if(*(arr+indexArr[i]) < *(arr+indexArr[k])) {
            sorted[index++] = indexArr[i++];
        } else {
            sorted[index++] = indexArr[k++];
        }
    }
    
    if (i > j) {
        for(; k <= l;) {
            sorted[index++] = indexArr[k++];
        }
    } else {
        for(; i <= j;) {
            sorted[index++] = indexArr[i++];
        }
    }
    
    for(int m = left; m <= right; m++) {
        indexArr[m] = sorted[m-left];
    }
    
    delete[] sorted;
    return;
}

int main() {
    int number, sum = 0;
    int* aArray; 
    int* bArray; 
    int* aSortedArray;
    int* bIndexArray;
// 입력
    cin >> number;
    aArray = new int[number];
    bArray = new int[number];
    aSortedArray = new int[number];
    bIndexArray = new int[number];
    
    for(int i = 0; i < number; i++) {
        scanf("%d", &aArray[i]);
        aSortedArray[i] = aArray[i];
    }
    
    for(int i = 0; i < number; i++) {
        scanf("%d", &bArray[i]);  
        bIndexArray[i] = i;
    }
    
// 정렬
    sort(aSortedArray, aSortedArray+number);
    indexMergeSort(bArray, bIndexArray, 0, number-1);
    
// 출력
    for(int i = 0; i < number; i++) {
        aArray[bIndexArray[i]] = aSortedArray[number-i-1];
    }
    
    for(int i = 0; i < number; i++) {
        sum += aArray[i] * bArray[i];
    }
    
    printf("%d", sum);
    return 0;
}