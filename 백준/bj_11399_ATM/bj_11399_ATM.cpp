#include <iostream>
using namespace std;

void mergeSort(int*, int, int);
void merge(int*, int, int, int);
int* inputArray(int count);

int main() {
    int number;
    int* arr;
    cin >> number;

    arr = inputArray(number);
    mergeSort(arr, 0, number-1);
    
    int sum=0, sumTime=0;
    for(int i = 0; i < number; i++) {
        sum+= arr[i];
        sumTime+= sum;
    }
    cout << sumTime;
    
    delete[] arr;
    arr=0;
    return 0;
}

void mergeSort(int* arr, int left, int right) {
    if(left < right) {
        int mid = (left+right)/2+1;
        
        mergeSort(arr, left, mid-1);
        mergeSort(arr, mid, right);
        
        merge(arr, left, mid, right);
    }
}

void merge(int* arr, int left, int mid, int right) {
    int i = left, j = mid-1, k = mid, l = right;
    int* sorted = new int[l-i+1];
    int index = 0;
    
    while(i <= j && k <= l) {
        if(arr[i] < arr[k]) {
            sorted[index++] = arr[i++];
        } else {
            sorted[index++] = arr[k++];
        }
    }
    
    if (i > j) {
        for(; k <= l;) {
            sorted[index++] = arr[k++];
        }
    } else {
        for(; i <= j;) {
            sorted[index++] = arr[i++];
        }
    }
    
    for(int m = left; m <= right; m++) {
        arr[m] = sorted[m-left];
    }
    
    delete[] sorted;
    return;
}

int* inputArray(int count) {
    int* arr = new int[count];
    for(int i = 0; i < count; i++) {
        cin >> arr[i];
    }    
    return arr;
}