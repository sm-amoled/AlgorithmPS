# 이항 계수 3

문제 번호: 11401
알고리즘 분류: 분할 정복
푼 날짜: 2021년 3월 21일 15시 21분

## 문제링크

[https://www.acmicpc.net/problem/11401](https://www.acmicpc.net/problem/11401)

## 문제
자연수 n과 정수 k가 주어졌을 때 이항 계수 nCk를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

## 입력
첫째 줄에 n과 k가 주어진다. (1 ≤ n ≤ 4,000,000, 0 ≤ k ≤ n)

## 출력
 
nCk를 1,000,000,007로 나눈 나머지를 출력한다.
---

## 해설
[페르마의 소정리](https://namu.wiki/w/%ED%8E%98%EB%A5%B4%EB%A7%88%EC%9D%98%20%EC%86%8C%EC%A0%95%EB%A6%AC)를 이용해 해결할 수 있는 문제이다.
[참고 블로그](https://m.blog.naver.com/hongjg3229/221650178981)

태블릿이 없어서 식을 기록하기가 되게 애매하다. 위 블로그에서 수식적인 내용을 확인하면 좋겠다.
대충 요약해서 알려주자면, 페르마의 소정리를 이용해 음의 제곱의 나머지 값이 특정 형태의 나머지 값과 동일함을 을 구할 수 있고, 이를 이용해 나머지값을 구할 수 있다.


## 풀이
우선, mod 값을 1000000007 이라고 할 때, `nCk % mod`는 `(N! / (K! * (N-K)!)) % mod`의 값과 같고, 분모의 값 (나누기 값)에 대한 나머지를 구하기 위해 페르마의 소정리를 이용해준다. 이를 이용해 다시 수식을 작성하면 `nCk % mod` 는 `N! % mod * (K! * (N-K)!)^(mod-2) % mod`와 같다. 이를 위해 `N!`, `K!`, `(N-K)!` 3개의 값들을 구해주어야 한다. 아래 코드에서 A, B, C 가 각각의 값들을 mod(1000000007)로 나눈 나머지 값들이다.

```cpp
    long long A = 1;
    for(int i = 1; i <= N; i++) {
        A *= i;
        A = A % mod;
    }

    long long B = 1, C = 1;
    for(int i = 1; i <= K; i++) {
        B *= i;
        B = B % mod;
    }
    for(int i = 1; i <= N-K; i++) {
        C *= i;
        C = C % mod;
    }
```

mod-2 제곱을 구하기 위해서, 아래와 같은 함수를 만들어주었다. 아래 함수는 지수를 절반씩 접으면서 나머지를 구하여 반환하는 함수이다. `value^exp = value^(exp/2) * value^(exp/2) % mod` 의 방식으로 값을 찾는다. 홀수의 경우 value를 한 번 더 곱해 처리해준다.

```cpp
long long devidePow(long long exp, long long value) {
    if(exp == 1) return value % mod;

    long long temp = devidePow(exp/2, value);
    if(exp % 2) {
        return (((temp * temp) % mod) * value) % mod;
    } else {
        return (temp * temp) % mod;
    }
}
```
이렇게 찾은 값은 result에 저장하여 A값(N!)을 곱한 뒤 한 번 더 나머지를 구해준다. 이 값을 출력하면 우리가 원하는 결과를 얻을 수 있다.


```cpp
    long long result = devidePow(mod-2, (B*C) % mod);
    result = (A * result) % mod;
    
    cout << result;
```
---

## 코멘트
나의 수학실력으로는 해결할 수 없는 문제였나봐. 시간복잡도에서 걸리네.

---

## 코드

```cpp
#include <iostream>

using namespace std;
int mod = 1000000007;

long long devidePow(long long exp, long long value) {
    if(exp == 1) return value % mod;

    long long temp = devidePow(exp/2, value);
    if(exp % 2) {
        return (((temp * temp) % mod) * value) % mod;
    } else {
        return (temp * temp) % mod;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    long long A = 1;
    for(int i = 1; i <= N; i++) {
        A *= i;
        A = A % mod;
    }

    long long B = 1, C = 1;
    for(int i = 1; i <= K; i++) {
        B *= i;
        B = B % mod;
    }
    for(int i = 1; i <= N-K; i++) {
        C *= i;
        C = C % mod;
    }

    long long result = devidePow(mod-2, (B*C) % mod);
    result = (A * result) % mod;
    
    cout << result;
    return 0;
}
```
---
## 고민
처음에는 아래 코드처럼 DP로 짜서 해당 값까지 가는 동안 계속 나머지를 이용하고, 원하는 값의 나머지를 출력하고자 하였다. 그러나 시간초과로 실패.
```cpp
#include <iostream>

using namespace std;
int DP[4000001];

int main() {

    int N, K;
    cin >> N >> K;
    DP[0] = 1; DP[1] = 1;

    for(int i = 1; i <= N; i++) {
        int beforeValue;
        for(int index = 0; index <= i; index++) {
            int temp = DP[index];

            if(index == 0 || index == i) {
                DP[index] = 1;
            } else {
                DP[index] = (DP[index] + beforeValue) % 1000000007;
            }

            beforeValue = temp;
        }
    }

    cout << DP[K];

    return 0;
}
```