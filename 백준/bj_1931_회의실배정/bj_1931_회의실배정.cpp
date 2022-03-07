#include <iostream>
using namespace std;

struct conference {
    int startTime;
    int endTime;
};

void mergeSort(conference* arr, int left, int right);
void merge(conference* arr, int left, int mid, int right);


void mergeSort(conference* arr, int left, int right) {
    if(left < right) {
        int mid = (left+right)/2+1;
        
        mergeSort(arr, left, mid-1);
        mergeSort(arr, mid, right);
        
        merge(arr, left, mid, right);
    }
}

void merge(conference* arr, int left, int mid, int right) {
    int i = left, j = mid-1, k = mid, l = right;
    conference* sorted = new conference[l-i+1];
    int index = 0;
    
    while(i <= j && k <= l) {
        if(arr[i].endTime < arr[k].endTime) {
            sorted[index++] = arr[i++];
        } else if(arr[i].endTime > arr[k].endTime) {
            sorted[index++] = arr[k++];
        } else {
            if(arr[i].startTime < arr[k].startTime) {
                sorted[index++] = arr[i++];
            } else {
                sorted[index++] = arr[k++];
            }
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

int main() {
    int count, startTime, endTime;
    int confTime = 0, confCount = 0;
    
    scanf("%d", &count);
    conference* confArray = new conference[count+1];
    
    for(int i = 0; i < count; i++) {
        scanf("%d %d", &startTime, &endTime);
        confArray[i] = conference {startTime, endTime};
    }
    
    mergeSort(confArray, 0, count-1);
    
    for(int i = 0; i < count; i++) {
        if(confTime <= confArray[i].startTime) {
            confCount++;
            confTime = confArray[i].endTime;
        }
    }

    printf("%d", confCount);
    
    delete[] confArray;
    return 0;
}