# 배수와 약수

문제 번호: 5086
알고리즘 분류: 수학
푼 날짜: 2021년 3월 10일 오후 9:23

## 문제링크

[https://www.acmicpc.net/problem/5086](https://www.acmicpc.net/problem/5086)

## 문제

4 × 3 = 12이다.

이 식을 통해 다음과 같은 사실을 알 수 있다.

3은 12의 약수이고, 12는 3의 배수이다.

4도 12의 약수이고, 12는 4의 배수이다.

두 수가 주어졌을 때, 다음 3가지 중 어떤 관계인지 구하는 프로그램을 작성하시오.

1. 첫 번째 숫자가 두 번째 숫자의 약수이다.
2. 첫 번째 숫자가 두 번째 숫자의 배수이다.
3. 첫 번째 숫자가 두 번째 숫자의 약수와 배수 모두 아니다.

## 입력

입력은 여러 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 10,000이 넘지않는 두 자연수로 이루어져 있다. 마지막 줄에는 0이 2개 주어진다. 두 수가 같은 경우는 없다.

## 출력

각 테스트 케이스마다 첫 번째 숫자가 두 번째 숫자의 약수라면 factor를, 배수라면 multiple을, 둘 다 아니라면 neither를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

앞의 수가 뒤 수의 약수인지, 배수인지, 두 관계가 아닌지를 판별하는 문제이다. 앞의 수를 A, 뒤의 수를 B라고 하자. 이를 구분하기 위해서 A와 B의 대소관계에 따라 약수, 배수가 될 수 있는 경우를 구분하여 비교해본다.

## 풀이

입력이 `0 0`이 들어오면 프로그램이 종료되므로, 아래와 같이 해당 입력이 들어오면 반복문을 탈출하도록 만들어주었다.

```cpp
int A, B;

while(true) {
    cin >> A >> B;
    if(A == 0 && B == 0) break;
	 
	// 비교문 처리   
}
```

A가 B보다 작을 때 약수인지를 확인하고, A가 B보다 클 때 배수인지를 확인해야 한다. 이를 확인하는 쉬운 방법은 나누었을 때 나머지가 0인지 아닌지를 확인하는 것이고, 해당하지 않는다면 neither를 출력한다.

```cpp
if(A < B) {
    if(B % A == 0) {
        cout << "factor\n";
    } else {
        cout << "neither\n";
    }
} else {
    if(A % B == 0) {
        cout << "multiple\n";
    } else {
        cout << "neither\n";
    }
}

```

---

## 코멘트

EZEZ

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B;
    
    while(true) {
        cin >> A >> B;
        if(A == 0 && B == 0) break;
        
        if(A < B) {
            if(B % A == 0) {
                cout << "factor\n";
            } else {
                cout << "neither\n";
            }
        } else {
            if(A % B == 0) {
                cout << "multiple\n";
            } else {
                cout << "neither\n";
            }
        }
    }
    
    return 0;
}
```