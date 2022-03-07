# 최대공약수와 최소공배수

푼 날짜: 2021년 3월 11일 오후 7:53

## 문제링크

[https://www.acmicpc.net/problem/2609](https://www.acmicpc.net/problem/2609)

## 문제

두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

## 출력

첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

최대공약수를 찾고, 최소공배수를 찾는 방식을 사용하면 쉽게 이 문제를 해결할 수 있다.

## 풀이

최대공약수를 찾는 방법 : 양 쪽의 수가 같아질 때 까지 두 수 중 큰 수에서 작은 수를 빼면서 값을 비교한다. 양쪽 값이 같아지면 최대공약수를 찾을 수 있다.

```
입력받은 수가 AxC BxC 이고, AxC < BxC 라고 하면,
AxC > (B-A)xC
(2A-B)xC < (B-A)xC
...
YxC = ZxC → Y와 Z가 1일 때 최대공약수인 C를 찾을 수 있다.
```

이를 코드로 구현하면 아래와 같다.

```cpp
int factA = A, factB = B;
while(factA != factB) {
    if(factA < factB) {
        factB -= factA;
    } else {
        factA -= factB;
    }
}
cout << factA << '\n';
```

최소공배수를 찾는 방법 : 양 쪽의 값 중 더 작은 값에 원래 값을 더하면서 양쪽의 두 값이 같아질 때 까지 비교한다. 같아지면 이게 최소공배수이다. 이를 코드로 구현하면 아래와 같다.

```cpp
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

이정도는 쉽게 해결할 수 있다. 생각보다 괜찮은 풀이 방법을 찾아낸 것 같다.

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    int factA = A, factB = B;
    while(factA != factB) {
        if(factA < factB) {
            factB -= factA;
        } else {
            factA -= factB;
        }
    }
    cout << factA << '\n';
    
    int multA = A, multB = B;
    while(multA != multB) {
        if(multA < multB) {
            multA += A;
        } else {
            multB += B;
        }
    }
    cout << multA << '\n';
    
    return 0;
}
```