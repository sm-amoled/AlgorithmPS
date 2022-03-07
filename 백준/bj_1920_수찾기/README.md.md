# 수 찾기

문제 번호: 1920
알고리즘 분류: 탐색
푼 날짜: 2021년 1월 28일 오후 8:13

### 문제 링크

[https://www.acmicpc.net/problem/1920](https://www.acmicpc.net/problem/1920)

## 문제

N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

## 입력

첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

## 출력

M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

탐색을 이용하면 쉽게 해결되는 문제이다. 첫 탐색 문제인 만큼, 탐색 알고리즘을 구현하여 사용하였다. 방법으로는 이분 탐색 - binary search를 사용했다.

## 풀이

이분 탐색 - binary search는 정렬된 값에 대하여 효율적으로 원하는 값을 찾는 알고리즘이다. 이를 사용하면 이 문제를 쉽게 해결 가능하다. 이분 탐색을 구현하는 방법은 아래와 같다.

```cpp
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
```

for문에서 한 번에 넘어갈 거리인 jump 변수의 초기값을 size/2로 주고, 0보다 큰 경우에 반으로 나누면서 반복문이 돌도록 만들었다.  그 안에 있는 while 문은 같은 jump 값에 대해 여러 번 이동을 할 수 있게 한다. (size가 12일 때 6 → 3 → 1 → 1 → 0으로 1칸씩 두 번 움직여야 모든 원소를 탐색할 수 있다.) `arr[index+jump] ≤ target` 조건 덕분에 이런 방식으로 하면 index를 1씩 여러 번 더할 수 있다. 

반복문을 빠져나왔을 때 index의 위치에 target이 있으면 배열에 target이 존재하기에 true를 반환하고, 없으면 false를 반환한다. 

---

## 코멘트

1을 여러 번 더하는 저 방식을 생각해내지 못했어... 조금 더 고민해보자!

---

## 코드

```cpp
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
```