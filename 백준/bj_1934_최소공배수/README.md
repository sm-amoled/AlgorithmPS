# 최소공배수

문제 번호: 1934
알고리즘 분류: 수학
푼 날짜: 2021년 3월 13일 오전 11:38

## 문제링크

[https://www.acmicpc.net/problem/1934](https://www.acmicpc.net/problem/1934)

## 문제

두 자연수 A와 B에 대해서, A의 배수이면서 B의 배수인 자연수를 A와 B의 공배수라고 한다. 이런 공배수 중에서 가장 작은 수를 최소공배수라고 한다. 예를 들어, 6과 15의 공배수는 30, 60, 90등이 있으며, 최소 공배수는 30이다.

두 자연수 A와 B가 주어졌을 때, A와 B의 최소공배수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 둘째 줄부터 T개의 줄에 걸쳐서 A와 B가 주어진다. (1 ≤ A, B ≤ 45,000)

## 출력

첫째 줄부터 T개의 줄에 A와 B의 최소공배수를 입력받은 순서대로 한 줄에 하나씩 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

두 값이 같아질 때 까지 두 수 중에서 더 작은 값에 각각 값을 계속 더해보면서 최소공배수를 찾으면 된다.

## 풀이

A와 B 두 값이 있다고 할 때, multA, multB에 대해 두 값이 같아질 때 까지 두 값 중 작은 값에 multA에는 A를, multB에는 B를 더해나간다. 두 값이 같아지면 최소공배수이며, 이를 출력하면 원하는 결과를 얻을 수 있다.

```cpp
int A, B;
cin >> A >> B;

int multA = A, multB = B;
while(multA != multB) {
    if(multA < multB) {
        multA += A;
    } else {
        multB += B;
    }
}
cout << multA << '\n';
```

---

## 코멘트

약수를 통해 구하는 방법보다 이게 더 간편한 것 같다.

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    
    while(T--) {
        int A, B;
        cin >> A >> B;
        
        int multA = A, multB = B;
        while(multA != multB) {
            if(multA < multB) {
                multA += A;
            } else {
                multB += B;
            }
        }
        cout << multA << '\n';
    }
    return 0;
}
```