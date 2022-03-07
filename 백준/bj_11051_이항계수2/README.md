# 이항 계수 2

문제 번호: 11051
알고리즘 분류: DP
푼 날짜: 2021년 2월 21일 오후 8:24

## 문제링크

[https://www.acmicpc.net/problem/11051](https://www.acmicpc.net/problem/11051)

## 문제

자연수 N과 정수 K가 주어졌을 때 이항 계수 (N / K)를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

여기에서 (N / K)는 아래의 수식을 의미한다.

$$N \choose K$$

## 입력

첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ K ≤ N)

## 출력

(N / K)를 10,007로 나눈 나머지를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

파스칼의 삼각형을 DP로 만들어 범위의 위험에서 안전하게 해결할 수 있다.

```
1 : 1 1
2 : 1 2 1
3 : 1 3 3 1
4 : 1 4 6 4 1
...

5C2 → 5번째 줄의 2번 index 값을 출력
```

## 풀이

파스칼의 삼각형을 만들면 해결할 수 있다. N에 해당하는 값이 커질수록 삼각형의 자리도 하나씩 늘어나므로, dp에 push 해준다. 각 줄을 K단계라고 할 때, `K[i] = K-1[i-1] + K-1[i]` 이므로 temp를 이용하여 `K-1[i-1]`을 미리 저장해주었다. 위 식을 이용해 파스칼의 삼각형을 만들어내는 DP를 코드로 구현하면 아래와 같다.

```cpp
long temp1, temp2;
vector<long> dp(2, 1);
for(int i = 1; i < N; i++) {
    dp.push_back(1);
    temp1 = 1;
    for(int j = 1; j <= i; j++) {
        temp2 = dp[j];
        dp[j] = (temp1 + dp[j])%10007;
        temp1 = temp2;
    }
}
```

N까지의 삼각형이 만들어졌으므로, K번째 index에 접근하여 값을 출력하기만 하면 된다.

```cpp
cout << dp[K];
```

---

## 코멘트

범위를 항상 신경쓰자. 난 그래도 값이 될 줄 알았는데, 나올 수 있는 경우 중 제일 큰 값이 1000 x 999 x ... x 501 이니깐 못담는게 당연하지... ㅋㅋㅋㅋ

## 고민

원래는 수학적인 지식대로 단순하게 5C2 = 5x4 / 2x1 로 해결하려고 했지만, 곱셈의 값이 너무 커져서 overflow가 발생하게 된다. 그래서 파스칼의 삼각형을 만들어 해결하였다. 이게 시간이 더 오래 걸릴거라 생각해서 일부러 곱셈으로 만들려고 했던건데... ㅋㅋㅋ

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    long temp1, temp2;
    vector<long> dp(2, 1);
    for(int i = 1; i < N; i++) {
        dp.push_back(1);
        temp1 = 1;
        for(int j = 1; j <= i; j++) {
            temp2 = dp[j];
            dp[j] = (temp1 + dp[j])%10007;
            temp1 = temp2;
        }
    }
    
    cout << dp[K];
    return 0;
}
```