# ATM

문제 번호: 11397
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 18일 오후 9:37

### 문제 링크

[https://www.acmicpc.net/problem/11399](https://www.acmicpc.net/problem/11399)

## 문제

인하은행에는 ATM이 1대밖에 없다. 지금 이 ATM앞에 N명의 사람들이 줄을 서있다. 사람은 1번부터 N번까지 번호가 매겨져 있으며, i번 사람이 돈을 인출하는데 걸리는 시간은 Pi분이다.

사람들이 줄을 서는 순서에 따라서, 돈을 인출하는데 필요한 시간의 합이 달라지게 된다. 예를 들어, 총 5명이 있고, P1 = 3, P2 = 1, P3 = 4, P4 = 3, P5 = 2 인 경우를 생각해보자. [1, 2, 3, 4, 5] 순서로 줄을 선다면, 1번 사람은 3분만에 돈을 뽑을 수 있다. 2번 사람은 1번 사람이 돈을 뽑을 때 까지 기다려야 하기 때문에, 3+1 = 4분이 걸리게 된다. 3번 사람은 1번, 2번 사람이 돈을 뽑을 때까지 기다려야 하기 때문에, 총 3+1+4 = 8분이 필요하게 된다. 4번 사람은 3+1+4+3 = 11분, 5번 사람은 3+1+4+3+2 = 13분이 걸리게 된다. 이 경우에 각 사람이 돈을 인출하는데 필요한 시간의 합은 3+4+8+11+13 = 39분이 된다.

줄을 [2, 5, 1, 4, 3] 순서로 줄을 서면, 2번 사람은 1분만에, 5번 사람은 1+2 = 3분, 1번 사람은 1+2+3 = 6분, 4번 사람은 1+2+3+3 = 9분, 3번 사람은 1+2+3+3+4 = 13분이 걸리게 된다. 각 사람이 돈을 인출하는데 필요한 시간의 합은 1+3+6+9+13 = 32분이다. 이 방법보다 더 필요한 시간의 합을 최소로 만들 수는 없다.

줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어졌을 때, 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램을 작성하시오.

## 입력

[https://www.acmicpc.net/problem/11399](https://www.acmicpc.net/problem/11399)

## 출력

[https://www.acmicpc.net/problem/11399](https://www.acmicpc.net/problem/11399)

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

인출하는데 걸리는 시간이 짧은 사람이 앞에 있을수록 모든 인원이 돈을 인출하는데 걸리는 시간의 합이 작아진다. 원하는 바가 시간의 합의 최솟값이므로, 시간의 작은 순으로 정렬하여 합을 구하면 된다. 

## 풀이

정렬 알고리즘을 통해 값을 정렬하고, 개인의 누적 시간을 총 시간에 더하여 시간의 합의 최솟값을 구한다.

---

## 코멘트

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
    // printArray(arr, number);
    
    int sum=0, time=0;
    for(int i = 0; i < number; i++) {
        sum+= arr[i];
        time+= sum;
    }
    cout << time;
    
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
}
```