# 이항 계수 1

문제 번호: 11050
알고리즘 분류: 수학
푼 날짜: 2021년 3월 14일 오후 12:48

## 문제링크

[https://www.acmicpc.net/problem/11050](https://www.acmicpc.net/problem/11050)

## 문제

이하 이항 계수를 아래와 같이 표기한다.

$$(N, K) → \binom{N}{K}$$

자연수 N과 정수 K가 주어졌을 때 이항 계수 (N, K)를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)

## 출력

(N, K)를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

입력되는 값의 크기가 그렇게 크지 않으므로, 이항 계수를 구하는 수식적인 방법을 그대로 이용하여 값을 구해준다.

`N ~ N-K+1` 까지 곱한 값에 `1 ~ K` 까지 곱한 값을 나눈 결과를 출력한다.

## 풀이

해설에 적힌 방법대로 `N` 부터 `N-K+1` 까지를 `result`에 차례대로 곱하고, `1`부터 `K`까지의 값을 `result`에 차례대로 나누어준다. 이 값을 출력하면 원하는 결과를 얻을 수 있다.

```cpp
int result = 1;
for(int i = 0; i < K; i++) {
    result *= N - i;
}
for(int i = 1; i <= K; i++) {
    result /= i;
}
```

---

## 코멘트

만약 입력받는 값이 커져서 연산해야할 수가 늘어난다면 result의 자료형의 크기를 더 늘여주어야 하고, 연산 속도가 느려질 수 있으므로 성능을 위해서라면 파스칼의 삼각형을 이용해 이미 구한 이항 계수 값으로 다음 이항 계수를 구하는 DP 방식을 사용해주어야 한다.

---

## 코드

```cpp
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    int result = 1;
    for(int i = 0; i < K; i++) {
        result *= N - i;
    }
    for(int i = 1; i <= K; i++) {
        result /= i;
    }
       
    cout << result;
    return 0;
}
```