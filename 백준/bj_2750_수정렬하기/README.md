# 수 정렬하기

문제 번호: 2750
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 17일 오전 10:56

### 문제 링크

[https://www.acmicpc.net/problem/2750](https://www.acmicpc.net/problem/2750)

## 문제

N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

## 입력

첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

## 출력

첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

값을 받아와 수를 정렬한 뒤, 정렬된 순서대로 출력한다.

## 풀이

버블 정렬을 이용해 문제를 해결해주었다. 

---

## 코멘트

알고리즘 공부 시작!

---

## 코드

```cpp
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
```