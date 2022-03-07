# 행렬 곱셈

문제 번호: 2740
알고리즘 분류: 수학, 구현
푼 날짜: 2021년 3월 22일 오후 19:32

## 문제링크
https://www.acmicpc.net/problem/2740

## 문제
N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.

## 입력
첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다. N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

## 출력
첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.


---

## 해설
입력받은 행렬에 대해 행렬 곱을 수행해주면 된다. NXM, MXK 크기의 두 행렬의 곱은 NXK 크기의 행렬이 나온다. 
행렬의 곱은 아래와 같이 수행되며, 이를 구현해주면 된다.
![IMAGE](IMAGE1.jpg)


## 풀이
A, B 행렬을 입력받아준다.
```cpp
cin >> N >> M;

for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
        cin >> A[i][j];
    }
}

cin >> M >> K;
for(int i = 0; i < M; i++) {
    for(int j = 0; j < K; j++) {
        cin >> B[i][j];
    }
}
```

result 행렬에 행렬의 곱을 저장해준다. A의 i행, B의 j열에 대해 p값으로 움직이며 곱의 합을 result에 저장한다.
```cpp
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            for(int p = 0; p < M; p++) {
                result[i][j] += A[i][p] * B[p][j];
            }
        }
    }
```

구한 행렬합을 양식에 맞게 출력해준다.
```cpp
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
```
---

## 코멘트
아직 이정도는 괜찮다구.

---

## 코드

```cpp
#include <iostream>

using namespace std;

int A[100][100], B[100][100], result[100][100] = {0};

int main() {
    int N, M, K;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    cin >> M >> K;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < K; j++) {
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            for(int p = 0; p < M; p++) {
                result[i][j] += A[i][p] * B[p][j];
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
```
