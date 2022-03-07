# 약수

문제 번호: 1037
알고리즘 분류: 수학
푼 날짜: 2021년 3월 11일 오후 7:48

## 문제링크

[https://www.acmicpc.net/problem/1037](https://www.acmicpc.net/problem/1037)

## 문제

양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N의 진짜 약수의 개수가 주어진다. 이 개수는 50보다 작거나 같은 자연수이다. 둘째 줄에는 N의 진짜 약수가 주어진다. 1,000,000보다 작거나 같고, 2보다 크거나 같은 자연수이고, 중복되지 않는다.

## 출력

첫째 줄에 N을 출력한다. N은 항상 32비트 부호있는 정수로 표현할 수 있다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 512MB

---

## 해설

모든 진짜 약수가 주어지므로, 진짜 약수 중 가장 작은 값과 가장 큰 값의 곱이 원래 값 N의 값과 같다. N을 2개의 수의 곱으로 나타낼 때, 가장 작은 약수와 가장 큰 약수의 곱으로 나타내어지기 때문이다.

## 풀이

입력받은 값 중에서 가장 작은 값과 가장 큰 값을 저장하고, 입력이 완료되면 가장 작은 값과 가장 큰 값의 곱을 출력한다.

```cpp
int N;
cin >> N;

int input;
int min = 1000001, max = 1;
for(int i = 0; i < N; i++) {
    cin >> input;
    
    if(min > input) min = input;
    if(max < input) max = input;
}

cout << max * min;
```

---

## 코멘트

약수가 아니라 진짜 약수라고 말하기에 뭔가 좀 더 어려울 줄 알았는데, 생각보다는 쉽게 해결되는 문제였다.

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int input;
    int min = 1000001, max = 1;
    for(int i = 0; i < N; i++) {
        cin >> input;
        
        if(min > input) min = input;
        if(max < input) max = input;
    }
    
    
    cout << max * min;
      
    return 0;
}
```