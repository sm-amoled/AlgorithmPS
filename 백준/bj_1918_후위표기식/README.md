# 후위 표기식

문제 번호: 1918
알고리즘 분류: 스택
푼 날짜: 2021년 2월 13일 오후 9:59

## 문제링크

[https://www.acmicpc.net/problem/1918](https://www.acmicpc.net/problem/1918)

## 문제

수식은 일반적으로 3가지 표기법으로 표현할 수 있다. 연산자가 피연산자 가운데 위치하는 중위 표기법(일반적으로 우리가 쓰는 방법이다), 연산자가 피연산자 앞에 위치하는 전위 표기법(prefix notation), 연산자가 피연산자 뒤에 위치하는 후위 표기법(postfix notation)이 그것이다. 예를 들어 중위 표기법으로 표현된 a+b는 전위 표기법으로는 +ab이고, 후위 표기법으로는 ab+가 된다.

이 문제에서 우리가 다룰 표기법은 후위 표기법이다. 후위 표기법은 위에서 말한 법과 같이 연산자가 피연산자 뒤에 위치하는 방법이다. 이 방법의 장점은 다음과 같다. 우리가 흔히 쓰는 중위 표기식 같은 경우에는 덧셈과 곱셈의 우선순위에 차이가 있어 왼쪽부터 차례로 계산할 수 없지만 후위 표기식을 사용하면 순서를 적절히 조절하여 순서를 정해줄 수 있다. 또한 같은 방법으로 괄호 등도 필요 없게 된다. 예를 들어 a+b*c를 후위 표기식으로 바꾸면 abc*+가 된다.

중위 표기식을 후위 표기식으로 바꾸는 방법을 간단히 설명하면 이렇다. 우선 주어진 중위 표기식을 연산자의 우선순위에 따라 괄호로 묶어준다. 그런 다음에 괄호 안의 연산자를 괄호의 오른쪽으로 옮겨주면 된다.

예를 들어 a+b*c는 (a+(b*c))의 식과 같게 된다. 그 다음에 안에 있는 괄호의 연산자 *를 괄호 밖으로 꺼내게 되면 (a+bc*)가 된다. 마지막으로 또 +를 괄호의 오른쪽으로 고치면 abc*+가 되게 된다.

다른 예를 들어 그림으로 표현하면 A+B*C-D/E를 완전하게 괄호로 묶고 연산자를 이동시킬 장소를 표시하면 다음과 같이 된다.

![https://www.acmicpc.net/JudgeOnline/upload/201007/4.png](https://www.acmicpc.net/JudgeOnline/upload/201007/4.png)

이러한 사실을 알고 중위 표기식이 주어졌을 때 후위 표기식으로 고치는 프로그램을 작성하시오

## 입력

첫째 줄에 중위 표기식이 주어진다. 단 이 수식의 피연산자는 A~Z의 문자로 이루어지며 수식에서 한 번씩만 등장한다. 그리고 -A+B와 같이 -가 가장 앞에 오거나 AB와 같이 *가 생략되는 등의 수식은 주어지지 않는다. 표기식은 알파벳 대문자와 +, -, *, /, (, )로만 이루어져 있으며, 길이는 100을 넘지 않는다.

## 출력

첫째 줄에 후위 표기식으로 바뀐 식을 출력하시오

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

## 풀이

입력을 받아올 때 알파벳은 그대로 출력하고, 기호는 스택으로 쌓아올려 적절한 순서에 출력해주어야 한다.

‘(‘는 입력되면 바로 스택에 push해준다. ‘)’가 입력되었을 때 ‘(‘까지 쌓여있는 기호들을 한 번에 출력해주어야 한다. 이를 코드로 구현하면 아래와 같다.

```cpp
switch(temp) {
    case '(':
        stack.push_back(temp);
        break;
        
    case ')':
        while(stack.back() != '(') {
            cout << stack.back();
            stack.pop_back();
        }
				// 마지막 남아있는 '(' 제거
        stack.pop_back();
        break;
}
```

그 다음, +와 -는 가장 후순위 연산자이기에 ( 를 만날 때 까지 또는 스택이 빌 때 까지 남아있는 연산자를 모두 출력해준다. *와 /는 ( 를 만날 때 까지 또는 만나는 *, /를 모두 출력해준다. 그 다음, 현재 입력받은 연산자를 스택에 push 해준다.

```cpp
switch(temp) {
    case '+':
    case '-':
        while(!stack.empty()) {
            if(stack.back() == '(') {
                break;
            } else {
                cout << stack.back();
                stack.pop_back();
            }
        }
        stack.push_back(temp);
        break;
        
    case '*':
    case '/': 
        while(!stack.empty()) {
            if(stack.back() == '(') {
                break;
            } else if (stack.back() == '*' || stack.back() == '/') {
                cout << stack.back();
                stack.pop_back();
            } else {
                break;
            }
        }
        stack.push_back(temp);
        break;
}
```

그 다음, 스택에 남아있는 연산자를 모두 출력해주면 원하는 결과를 얻을 수 있다.

```cpp
while(!stack.empty()) {
    cout << stack.back();
    stack.pop_back();
}
```

---

## 코멘트

난 이거 헷갈리더라. 분명 자료구조 때 배운 내용인데, 코드로 구현하려니까 막히는 것 같았다. ㅜㅜ

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<char> stack;
    
    while(true) {
        char temp = getchar();
        if(temp == '\n' || temp == 0) break;
        
        if(temp >= 'A' && temp <= 'Z') {
            cout << temp;
        } else {
            if(stack.empty()) {
                stack.push_back(temp);
            } else {
                switch(temp) {
                    case '(':
                        stack.push_back(temp);
                        break;
                        
                    case ')':
                        while(stack.back() != '(') {
                            cout << stack.back();
                            stack.pop_back();
                        }
                        stack.pop_back();
                        break;
                        
                    case '+':
                    case '-':
                        while(!stack.empty()) {
                            if(stack.back() == '(') {
                                break;
                            } else {
                                cout << stack.back();
                                stack.pop_back();
                            }
                        }
                        stack.push_back(temp);
                        break;
                        
                    case '*':
                    case '/': 
                        while(!stack.empty()) {
                            if(stack.back() == '(') {
                                break;
                            } else if (stack.back() == '*' || stack.back() == '/') {
                                cout << stack.back();
                                stack.pop_back();
                            } else {
                                break;
                            }
                        }
                        stack.push_back(temp);
                        break;
                }
            }
        }
    }
    
    while(!stack.empty()) {
        cout << stack.back();
        stack.pop_back();
    }
        
    return 0;
}
```