# 스택

문제 번호: 10828
알고리즘 분류: 스택
푼 날짜: 2021년 2월 9일 오후 10:34

## 문제링크

[https://www.acmicpc.net/problem/10828](https://www.acmicpc.net/problem/10828)

## 문제

정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

- push X: 정수 X를 스택에 넣는 연산이다.
- pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- size: 스택에 들어있는 정수의 개수를 출력한다.
- empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
- top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

## 입력

첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

## 출력

출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

## 조건

- 시간 제한 : 0.5s
- 메모리 제한 : 256MB

---

## 해설

스택 구조를 직접 만들어보자! 배열에서 topPointer의 위치가 값을 넣고 빼는 위치라고 생각하면 쉽게 만들 수 있다.

## 풀이

함수에서도 접근하기 위해 전역변수로 `topPointer`를 선언해주었다. 각 명령어들은 명세에 맞게 작동하도록 만들어준다. 

`Push`는 topPointer를 1 증가시키고 X를 대입한다.

```cpp
void push(int* arr, int X) {
    arr[++topPointer] = X;
}
```

`Pop`은 X를 출력하고 topPointer를 1 감소시킨다. topPointer가 -1인 경우 -1을 출력한다.

```cpp
void pop(int* arr) {
    cout << ((topPointer == -1)? -1:arr[topPointer--]) << "\n";
}
```

`Size`는 topPointer+1의 값을 출력한다. (index 0 포함)

```cpp
void size(int* arr) {
    cout << topPointer+1 << "\n";
}
```

`empty`는 topPointer가 -1인 경우 -1을, 그 외에는 0을 출력한다.

```cpp
void empty(int* arr) {
    cout << ((topPointer == -1)? "1":"0") << "\n";
}
```

`top`은 현재 스택의 top에 있는 원소를 출력한다. topPointer가 -1인 경우 -1을 출력한다.

```cpp
void top(int* arr) {
    cout << ((topPointer==-1)? -1:arr[topPointer]) << "\n";
}
```

위 분기는 switch 문을 통해 만들어주었다.

### 참고사항

동적 할당으로 만든 배열의 경우 `sizeof(arr)/sizeof(*arr)`을 이용해 길이를 구할 수 없다!

---

## 코멘트

동적할당으로 만들면 길이를 구하는 식을 못쓴다는 걸 오늘 알았다. 

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int topPointer = -1;

void push(int* arr, int X) {
    arr[++topPointer] = X;
}

void pop(int* arr) {
    cout << ((topPointer == -1)? -1:arr[topPointer--]) << "\n";
}

void size(int* arr) {
    cout << topPointer+1 << "\n";
}

void empty(int* arr) {
    cout << ((topPointer == -1)? "1":"0") << "\n";
}

void top(int* arr) {
    cout << ((topPointer==-1)? -1:arr[topPointer]) << "\n";
}

int main() {
    int N;
    cin >> N;
    
    int* arr = new int[10001];
    for(int i = 0; i < N; i++) {
        int temp;
        
        string instruction;
        cin >> instruction;
        
        if(instruction == "push") {
            cin >> temp;
            push(arr, temp);
        } else if (instruction == "pop") {
            pop(arr);
        } else if (instruction == "size") {
            size(arr);
        } else if (instruction == "empty") {
            empty(arr);
        } else if (instruction == "top") {
            top(arr);
        } 
        
    }   
    return 0;
}
```