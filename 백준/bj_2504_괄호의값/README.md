# 괄호의 값

문제 번호: 2504
알고리즘 분류: 스택
푼 날짜: 2021년 2월 12일 오후 12:34

## 문제링크

[https://www.acmicpc.net/problem/2504](https://www.acmicpc.net/problem/2504)

## 문제

4개의 기호 ‘(’, ‘)’, ‘[’, ‘]’를 이용해서 만들어지는 괄호열 중에서 올바른 괄호열이란 다음과 같이 정의된다.

1. 한 쌍의 괄호로만 이루어진 ‘()’와 ‘[]’는 올바른 괄호열이다.
2. 만일 X가 올바른 괄호열이면 ‘(X)’이나 ‘[X]’도 모두 올바른 괄호열이 된다.
3. X와 Y 모두 올바른 괄호열이라면 이들을 결합한 XY도 올바른 괄호열이 된다.

예를 들어 ‘(()[[]])’나 ‘(())[][]’ 는 올바른 괄호열이지만 ‘([)]’ 나 ‘(()()[]’ 은 모두 올바른 괄호열이 아니다. 우리는 어떤 올바른 괄호열 X에 대하여 그 괄호열의 값(괄호값)을 아래와 같이 정의하고 값(X)로 표시한다.

1. ‘()’ 인 괄호열의 값은 2이다.
2. ‘[]’ 인 괄호열의 값은 3이다.
3. ‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
4. ‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.
5. 올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다.

예를 들어 ‘(()[[]])([])’ 의 괄호값을 구해보자.  ‘()[[]]’ 의 괄호값이 2 + 3×3=11 이므로  ‘(()[[ ]])’의 괄호값은 2×11=22 이다. 그리고  ‘([])’의 값은 2×3=6 이므로 전체 괄호열의 값은 22 + 6 = 28 이다.

여러분이 풀어야 할 문제는 주어진 괄호열을 읽고 그 괄호값을 앞에서 정의한대로 계산하여 출력하는 것이다.

## 입력

첫째 줄에 괄호열을 나타내는 문자열(스트링)이 주어진다. 단 그 길이는 1 이상, 30 이하이다.

## 출력

첫째 줄에 그 괄호열의 값을 나타내는 정수를 출력한다. 만일 입력이 올바르지 못한 괄호열이면 반드시 0을 출력해야 한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

(, ), [, ]을 조합하여 나올 수 있는 모든 경우의 수에 대해 대응을 해주면 쉽게 해결이 가능하다. 

## 풀이

들어온 입력을 처리해주기 위한 스택으로 int 벡터를 선언해주었다. 나는 숫자의 합과 기호를 같은 스택 상에서 한번에 관리하는 방법을 사용하였다.

입력받는 각 기호에 따라 다르게 처리를 해주어야 한다. 우선 **정상적인 입력에 대한 처리**부터 살펴보자. 괄호가 처리되어 값으로 반환된 경우 - ()[]가 쌍이 만들어지는 경우 - 에는 숫자가 push 되어있다.

- ( : 입력되면 stack에 0을 push 한다.
- ) : 입력되면 stack에서 0이 나올 때 까지 있는 수를 다 더한다. 0을 pop 하고, 합x2를 push 한다. )에 대한 push 는 없다.
- [ : 입력되면 stack에 1을 push 한다.
- ] : 입력되면 stack에서 1이 나올 때 까지 있는 수를 다 더한다. 1을 pop 하고, 합x3을 push 한다. ]에 대한 push 는 없다.

```cpp
temp = getchar();
if(temp == '\n') break;

if(temp == '(') {
    stack.push_back(0);
} else if (temp == '[') {
    stack.push_back(1);
} else if (temp == ')' || temp == ']') {
    int match = (temp == ')')? 0:1;
    
		// ()인 경우 / []인 경우
    if(stack.back() == match) {
        stack.pop_back();
        stack.push_back(match+2);
    } 
		// (X)인 경우 / [X]인 경우 ← X는 스택에 푸쉬되어있는 숫자!
		else {
        if(stack[stack.size()-2] == match) {
						// ( 자리에 값을 넣고 기존에 있던 숫자는 pop
            stack[stack.size()-2] = stack.back()*(match+2);
            stack.pop_back();
        }
    }
    
		// ( X Y 같은 상황에서 ( X+Y 로 합쳐주는 역할을 하는 코드
    if(stack.size() >= 2) {
        if(stack.back() > 1 && stack[stack.size()-2] > 1) {
            stack[stack.size()-2] += stack.back();
            stack.pop_back();
        }
    }
}
```

다음은 **비정상적 입력에 대한 처리**이다. 

- ( [ ) : stack에서 1을 찾는데 / 0을 찾는데 반대의 0 / 1이 나온 경우
- ( ) )  : 1/0 없이 완성된 괄호와 )/]만 있는 경우 (stack에 2만 있을 때 ‘)’가 들어오면)→ stack back이 0/1이 아니고 size가 1일 때
- ) : 문자열 ) 또는 ] 만 있는 경우 → stack size가 0일 때

```cpp
if(stack.size() == 0) {
		// 반례 : )
    cout << "0";
    return 0;
}

if(stack.back() == match) {
		// 처리
} else if (stack.back() == (match == 0)? 1:0) {
    // 반례 : ( [ )
    cout << "0";
    return 0;
} else {
    if(stack.size() == 1) {
        // 반례 : X )
        cout << "0";
        return 0;
    }
}
```

- ( [ ] : 시작 괄호의 쌍을 못찾았을 때 ← 스택에 0 또는 1이 아직 들어있음 ... stack size가 1 이 아닐 때

```cpp
if(stack.size() > 1) {
    // 반례 : X ( 
    cout << "0";
    return 0;
}
```

위 조건을 다 가려내고 나면 stack의 첫 번째 원소이자 마지막 원소에 원하는 결과가 들어있다.

---

## 코멘트

아주 어려웠어... 생각보다 쉬울 것 같으면서도 어려웠던 문제인 것 같다. 

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> stack;
    char temp;
    
    while(true) {
        temp = getchar();
        if(temp == '\n') break;
        
        if(temp == '(') {
            stack.push_back(0);
        } else if (temp == '[') {
            stack.push_back(1);
        } else if (temp == ')' || temp == ']') {
            int match = (temp == ')')? 0:1;
            
            if(stack.size() == 0) {
                cout << "0";
                return 0;
            }
            
            if(stack.back() == match) {
                stack.pop_back();
                stack.push_back(match+2);
            } else if (stack.back() == (match == 0)? 1:0) {
                // 반례 : ( [ )
                cout << "0";
                return 0;
            } else {
                if(stack.size() == 1) {
                    // 반례 : X )
                    cout << "0";
                    return 0;
                }
                else if(stack[stack.size()-2] == match) {
                    stack[stack.size()-2] = stack.back()*(match+2);
                    stack.pop_back();
                }
            }
            
            if(stack.size() >= 2) {
                if(stack.back() > 1 && stack[stack.size()-2] > 1) {
                    stack[stack.size()-2] += stack.back();
                    stack.pop_back();
                }
            }
        }
    }
    if(stack.size() > 1) {
        // 반례 : X ( 
        cout << "0";
        return 0;
    }
    
    cout << stack.back();
    return 0;
}
```