# 오르막 수

문제 번호: 11057
알고리즘 분류: DP
푼 날짜: 2021년 2월 19일 오후 11:25

## 문제링크

[https://www.acmicpc.net/problem/11057](https://www.acmicpc.net/problem/11057)

## 문제

오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.

예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.

## 입력

첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.

## 출력

첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

오르막 수의 자릿수에 따라 증가되는 값의 규칙을 파악하면 쉽게 해결할 수 있다.

```
1 → 10
2 → 10 + 9 + 8 + ... + 2 + 1
3 → (10+9+...+1) + (9+...+1) + (8+...+1) + ... + 1
...
```

즉, 1자리수를 제외한 나머지 단계에서는 `N[i] = N-1[i ~ 끝까지]의 합`이라는 식을 만족한다. 

## 풀이

먼저 계산을 위한 기본 값을 채운다.

```cpp
vector<long> dp(10);    
	  for(int i = 0; i < 10; i++) {
    dp[i] = 10-i;
}
```

각 dp의 원소값은 다음 단계(다음 자릿수)로 갈 때 이전 단계에서의 값의 부분합을 이용한다.  `N[i] = N-1[i ~ 끝까지]의 합`를 이용하기 위해 아래와 같이 코드를 작성해준다. 조건에 따라 10007로 나누어 dp에 대입해주어야 한다.

```cpp
for(int i = 2; i < N; i++) {
    for(int j = 0; j < 10; j++) {
        long temp = 0;
        for(int k = j; k < 10; k++) {
            temp += dp[k];
        }
        dp[j] = temp % 10007;
    }   
}
```

결과를 출력하기 위해서는 단계에 있는 원소의 총 합을 10007로 나눈 나머지를 구하면 된다.

```cpp
long sum = 0;
for(auto x : dp) {
    sum += x;
}
cout << sum%10007 << '\n';
```

---

## 코멘트

[[1010 : 다리놓기]](https://www.acmicpc.net/problem/1010) 문제의 쉬운 버전이라는 생각이 든다. 규칙만 찾으면 쉽게 풀 수 있는 문제!

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    if(N == 1) {
        cout << 10 << '\n';
        return 0;
    }
    
    vector<long> dp(10);    
    for(int i = 0; i < 10; i++) {
        dp[i] = 10-i;
    }
    
    
    for(int i = 2; i < N; i++) {
        for(int j = 0; j < 10; j++) {
            long temp = 0;
            for(int k = j; k < 10; k++) {
                temp += dp[k];
            }
            dp[j] = temp % 10007;
        }   
    }
    
    
    long sum = 0;
    for(auto x : dp) {
        sum += x;
    }
    cout << sum%10007 << '\n';
 
    
    return 0;
}
```