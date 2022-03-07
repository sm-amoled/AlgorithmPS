# 수 정렬하기 2

문제 번호: 2751
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 17일 오후 8:13

### 문제 링크

[https://www.acmicpc.net/submit/2751](https://www.acmicpc.net/submit/2751)

## 문제

N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

## 입력

첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

## 출력

첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 256MB

---

## 해설

수를 정렬하는 알고리즘을 이용하면 된다. 

## 풀이

병합 정렬을 사용해보았다.

---

## 코멘트

코드 안보고 개념만 보고 구현한다고 고생 좀 했네. 아직 C++은 적응이 안되네. 그냥 코딩이 적응이 안되는 듯 ㅋㅋㅋ... 휴....

---

## 코드

```cpp
#include <iostream>
using namespace std;

void mergeSort(int*, int, int);
void merge(int*, int, int, int);
int* inputArray(int count);
void printArray(int* arr, int count);

int main() {
    int number;
    int* arr;
    cin >> number;

    arr = inputArray(number);
    mergeSort(arr, 0, number-1);
    printArray(arr, number);
    
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

void printArray(int* arr, int count) {
    for(int i = 0; i < count; i++) {
        cout << arr[i] << "\n";
    }    
    // cout << "\n";
}
```