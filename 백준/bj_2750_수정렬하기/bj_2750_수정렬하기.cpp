#include <iostream>
using namespace std;

int* inputArray(int count) {
    int* arr = new int[count];
    
    for(int i = 0; i < count; i++) {
        cin >> arr[i];
    }    
    
    return arr;
}

void printArray(int* arr, int count) {
    for(int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }    
    return ;
}

void swap(int* arr1, int* arr2) {
    int temp;
    temp = *arr1;
    *arr2 = *arr1;
    *arr1 = temp;
}

void bubbleSort(int* arr, int count) {
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < count-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int number;
    int* arr;
    cin >> number;

    arr = inputArray(number);
    bubbleSort(arr, number);
    printArray(arr, number);
    
    return 0;
}