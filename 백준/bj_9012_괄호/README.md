# 괄호

문제 번호: 9012
알고리즘 분류: 스택
푼 날짜: 2021년 2월 10일 오후 7:10

## 문제링크

[https://www.acmicpc.net/problem/9012](https://www.acmicpc.net/problem/9012)

## 문제

괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.

여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.

## 입력

입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다.

## 출력

출력은 표준 출력을 사용한다. 만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

‘(‘와 ‘)’가 짝지어져 같은 개수가 나오는지를 확인하는 문제이다. 스택 구조의 형식을 사용하여 ‘(‘를 Push하고, ‘)’이 나올 때 Pop하여 개수가 맞는지를 확인한다.

## 풀이

이 문제에서 스택 구조에 들어가야할 값들이 ‘(‘밖에 없으므로, 굳이 스택을 만들기 위한 배열을 선언할 필요는 없다. top 변수를 두고, ‘(‘이 들어오면 `top++` 을 하고, ‘)’이 들어오면 `top-—`을 해주면 () 쌍이 적절하게 들어오는지 확인할 수 있다. 

`string` 타입으로 받아온 문자열에서 문자열의 끝을 의미하는 널 포인터가 나올 때 까지 값을 check 한다. (이 들어오면 top++, )이 들어오면 top—, 만약 top이 초기값(-1)보다 작아지면 break를 한다. 반복문의 끝에서는 top이 초기값으로 돌아왔는지를 확인한다. 만약 -1보다 크거나 작다면(break으로 탈출한 경우) NO를 출력하고, 일치한다면 YES를 출력한다.

```cpp
string input;
cin >> input;

int index = 0;
top = -1;
while(input[index] != '\0') {
    if(input[index] == '(') {
        top++;
    } else if (input[index] == ')') {
        top--;
        if(top < -1) {
            break;
        }
    }
    index++;
}

cout << ((top == -1)? "YES":"NO") << "\n";
```

---

## 코멘트

이정도 문제는 누워서 식은 죽 먹기!

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int top = -1;
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        
        int index = 0;
        top = -1;
        while(input[index] != '\0') {
            if(input[index] == '(') {
                top++;
            } else if (input[index] == ')') {
                top--;
                if(top < -1) {
                    break;
                }
            }
            index++;
        }
        
        cout << ((top == -1)? "YES":"NO") << "\n";
    }
    
    return 0;
}
```