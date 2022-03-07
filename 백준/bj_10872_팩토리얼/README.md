# 팩토리얼

문제 번호: 10872
푼 날짜: 2021년 2월 28일 오후 9:58

## 문제링크

[https://www.acmicpc.net/problem/10872](https://www.acmicpc.net/problem/10872)

## 문제

0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.

## 출력

첫째 줄에 N!을 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

재귀를 이용해서 팩토리얼을 구현해보자!

팩토리얼을 재귀로 구현하기 위해서는 팩토리얼 함수 안에서 팩토리얼 함수를 호출할 수 있으면 된다. 이를 생각해보면 `factorial(N) = N * factorial(N-1)` 으로 구현할 수 있다. `factorial(0)`의 값이 1이고, N이 0보다 작아질 수 없기 때문에, `factorial(0)` 에서 1값을 return해주면 된다. 

## 풀이

factorial 함수는 아래의 방법으로 구현된다.

- N ≥ 1 : N * fact(N-1)
- N = 0 : 1

이를 코드로 구현하면 아래와 같다. N의 범위가 12까지이므로, fact(12)는 int의 범위 안에 들어가기 때문에 반환형을 int 자료형으로 만들어주면 된다.

```cpp
int fact(int numb) {
    if(numb == 0) return 1;
    else return numb*fact(numb-1);
}
```

입출력을 구현하여 처리하면 원하는 결과를 얻을 수 있다!

```cpp
int main() {
	int N;
	cin >> N;
	
	cout << fact(N);
	
	return 0;
}
```

---

## 코멘트

팩토리얼 정도는! 후후

---

## 코드

```cpp
#include <iostream>

using namespace std;

int fact(int numb) {
    if(numb == 0) return 1;
    else return numb*fact(numb-1);
}

int main() {
	int N;
	cin >> N;
	
	cout << fact(N);
	
	return 0;
}
```