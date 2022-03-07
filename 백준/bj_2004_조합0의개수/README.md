# 조합 0의 개수

문제 번호: 2004
알고리즘 분류: 수학
푼 날짜: 2021년 3월 17일 오후 10:37

## 문제링크

[https://www.acmicpc.net/problem/2004](https://www.acmicpc.net/problem/2004)

## 문제

nCm 의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에 정수 n, m (0≤m≤n≤2,000,000,000, n≠0)이 들어온다.

## 출력

첫째 줄에 nCm 의 끝자리 0의 개수를 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

nCm의 값을 나타내는 곱의 형태에서 2와 5의 개수를 각 카운트 하여 10을 얼마나 만들 수 있는지를 찾는다.

## 풀이

N!에 5의 개수를 N5, M!의 5의 개수를 M5, N-M의 5의 개수를 NminusM5라고 하고, 2에 대해서도 N2, M2, NminusM2라고 선언하자.

N의 5의 배수를 저장하는 과정에서, N을 5로 나눈 몫을 이용하면 5의 배수에서 5를 하나씩 뽑아낼 수 있다. 25로 나눈 몫을 이용하면 25의 배수(5가 2개 들어가있는 값들)에서 2개의 5를 가져올 수 있다. 이때, 5의 배수에서 하나의 5는 이미 가져왔으므로, 1개씩만 가져온다. 125의 배수를 이용하면 아직 가져오지 않은 5를 또 가져올 수 있다. N을 i로 나눈 몫이 1 이상인 동안 i에 5를 곱하며 반복하면 N5에 N! 을 소인수분해 했을 때 5의 개수를 구할 수 있다. 나머지 변수에 대해서도 동일한 반복문을 실행해준다.

```cpp
int N5 = 0, M5 = 0, NminusM5 = 0;
int N2 = 0, M2 = 0, NminusM2 = 0;

for(long long i = 5; N/i >= 1; i*=5) {
    N5 += N/i;
}
for(long long i = 5; M/i >= 1; i*=5) {
    M5 += M/i;
}
for(long long i = 5; (N-M)/i >= 1; i*=5) {
    NminusM5 += (N-M)/i;
}

for(long long i = 2; N/i >= 1; i*=2) {
    N2 += N/i;
}
for(long long i = 2; M/i >= 1; i*=2) {
    M2 += M/i;
}
for(long long i = 2; (N-M)/i >= 1; i*=2) {
    NminusM2 += (N-M)/i;
}
```

구하고자 하는 nCm의 5의 개수는 `N5 - (M5 + NminusM5)` 와 같다. 10을 만들기 위해서는 2와 5가 각각 하나씩 필요하므로, 2와 5의 개수 중에서 더 작은 쪽의 개수를 출력해주면 원하는 결과를 얻을 수 있다.

```cpp
cout << ((N5 - (M5 + NminusM5) < N2 - (M2 + NminusM2))? N5 - (M5 + NminusM5) : N2 - (M2 + NminusM2));
```

---

## 코멘트

5의 개수만 따지면 될 줄 알았는데, 2의 개수가 5의 개수보다 적은 경우가 있나보다. 아, 5C1이 그런 경우겠네.

---

## 코드

---

```cpp
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
      
    int N5 = 0, M5 = 0, NminusM5 = 0;
    int N2 = 0, M2 = 0, NminusM2 = 0;
    
    for(long long i = 2; N/i >= 1; i*=2) {
        N2 += N/i;
    }
    for(long long i = 2; M/i >= 1; i*=2) {
        M2 += M/i;
    }
    for(long long i = 2; (N-M)/i >= 1; i*=2) {
        NminusM2 += (N-M)/i;
    }
    
    for(long long i = 5; N/i >= 1; i*=5) {
        N5 += N/i;
    }
    for(long long i = 5; M/i >= 1; i*=5) {
        M5 += M/i;
    }
    for(long long i = 5; (N-M)/i >= 1; i*=5) {
        NminusM5 += (N-M)/i;
    }
    
    cout << ((N5 - (M5 + NminusM5) < N2 - (M2 + NminusM2))? N5 - (M5 + NminusM5) : N2 - (M2 + NminusM2));
    return 0;
}
```

## 문제 해결에 대한 고민

```cpp

```