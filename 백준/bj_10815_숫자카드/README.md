# 숫자 카드

문제 번호: 10815
알고리즘 분류: 정렬, 탐색
푼 날짜: 2021년 1월 23일 오후 9:05

### 문제 링크

[https://www.acmicpc.net/problem/10815](https://www.acmicpc.net/problem/10815)

## 문제

숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

## 출력

첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 256MB

---

## 해설

상근이가 가지고 있는 카드를 정렬하여 오름차순으로 만들고, 주어진 숫자를 이분탐색법으로 찾아 있으면 1을, 없으면 0을 반환한다.

## 풀이

`sort()` 함수를 통해 입력받아온 상근이의 카드 숫자 배열을 오름차순으로 정렬한다. 그 다음, 탐색을 통해 배열에 찾고자 하는 수가 있는지를 살펴본다. 탐색을 위한 알고리즘으로 이분 탐색 (binary search)를 사용하였다. 

---

## 코멘트

이건 뭐가 틀려서 안되는걸까..? 직접 구현하다가 어쩔 수 없이 치트를 써버렸다..

```cpp
bool binarySearch(int* arr, int arrSize, int target) {
    // arr가 정렬된 상태일 때
    int index = arrSize/2;
    int low = 0, high = arrSize-1;
    int movableSpace = arrSize/2;
    
    while(arr[index] != target) {
        // printf("target : %d / index : %d / L : %d H : %d\n", target, index , low, high);
        if(movableSpace == 0)  {
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
        
        movableSpace /= 2;
    }
    
    return true;
}
```

호성쿤과 소현쿤의 도움으로 알아낸 결과, movableSpace가 잘못된 것이였다. 마지막 원소까지 검사를 못해서 에러가 발생하는 거였어. 어쩐지... 존재 자체가 많이 수상스럽긴 했어.

```cpp
bool binarySearch(int* arr, int arrSize, int target) {
    // arr가 정렬된 상태일 때
    int index = arrSize/2;
    int low = 0, high = arrSize-1;
    
    while(arr[index] != target) {
        // printf("target : %d / index : %d / L : %d H : %d\n", target, index , low, high);
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
```

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int* arr, int arrSize, int target) {
    // arr가 정렬된 상태일 때
    int index = arrSize/2;
    int low = 0, high = arrSize-1;
    
    while(arr[index] != target) {
        // printf("target : %d / index : %d / L : %d H : %d\n", target, index , low, high);
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
```
