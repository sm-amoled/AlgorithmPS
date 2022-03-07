# 균형잡힌 세상

문제 번호: 4949
알고리즘 분류: 스택
푼 날짜: 2021년 2월 11일 오후 3:07

## 문제링크

[https://www.acmicpc.net/problem/4949](https://www.acmicpc.net/problem/4949)

## 문제

세계는 균형이 잘 잡혀있어야 한다. 양과 음, 빛과 어둠 그리고 왼쪽 괄호와 오른쪽 괄호처럼 말이다.

정민이의 임무는 어떤 문자열이 주어졌을 때, 괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램을 짜는 것이다.

문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고, 문자열이 균형을 이루는 조건은 아래와 같다.

- 모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
- 모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
- 모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
- 모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
- 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.

정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.

## 입력

하나 또는 여러줄에 걸쳐서 문자열이 주어진다. 각 문자열은 영문 알파벳, 공백, 소괄호("( )") 대괄호("[ ]")등으로 이루어져 있으며, 길이는 100글자보다 작거나 같다.

입력의 종료조건으로 맨 마지막에 점 하나(".")가 들어온다.

## 출력

각 줄마다 해당 문자열이 균형을 이루고 있으면 "yes"를, 아니면 "no"를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

공백을 포함하는 문자열을 입력받아와 (, [은 스택이 나올 때 마다 push하고 ), ]이 나오면 스택에서 각 (, [과 매칭되게 pop한다. 서로 짝이 맞지않으면 no를 출력한다.

## 풀이

공백을 포함하는 문자열을 입력으로 받아오기 위해 getline으로 입력을 받아온다. 괄호의 쌍이 제대로 입력되는지를 파악하기 위해 equal 벡터를 사용해주었다.

`s[index]`의 값이 (, ), [, ]인지에 따라 분기한다. )가 나온 경우, equal 벡터의 back에는 (이 있어야 하고, ]가 나온 경우에는 [이 있어야 한다. 만약에 적절하지 않은 값이 나오면 break으로 반복문을 탈출해준다.

```cpp
int index = 0;
while(s[index] != 0) {
    
    if(s[index] == '(' || s[index] == '[') equal.push_back(s[index]);
    if(s[index] == ')' || s[index] == ']') {
        // )가 먼저 나오는 경우
        if(equal.size() == 0) break;
        
        if((equal.back() == '(' && s[index] == ')') || (equal.back() == '[' && s[index] == ']')) equal.pop_back();
        else {
           break;
        }
    }
    index++;
}
```

반복문을 나오면 정상적으로 반복문을 돌았는지, 아니면 중간에 빠져나왔는지를 검사하는 코드로 결과를 출력해준다.

```cpp
cout << ((s[index] == 0 && equal.size() == 0)? "yes\n":"no\n");
```

입력받은 문장이 “.”와 같을 때까지 반복한다.

---

## 코멘트

입력을 getChar로 처리하면 시간초과가 뜨더라. 아무래도 문자로 입력받는 게 문자열로 한 번에 입력받는 것보다 head가 큰가보다.

---

## 코드

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // vector<char> s;
    string s;
    char temp;
    while(true) {
        getline(cin, s, '\n');
        
        if(s[0] == '.') { return 0;}
        vector<char> equal;
        
        int index = 0;
        while(s[index] != 0) {
            
            if(s[index] == '(' || s[index] == '[') equal.push_back(s[index]);
            if(s[index] == ')' || s[index] == ']') {
                // )가 먼저 나오는 경우
                if(equal.size() == 0) break;
                
                if((equal.back() == '(' && s[index] == ')') || (equal.back() == '[' && s[index] == ']')) equal.pop_back();
                else {
                   break;
                }
            }
            index++;
        }
        
        cout << ((s[index] == 0 && equal.size() == 0)? "yes\n":"no\n");
        s.clear();
    }
    
    return 0;
}
```