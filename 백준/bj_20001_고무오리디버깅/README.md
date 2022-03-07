# 고무오리 디버깅

문제 번호: 20001
알고리즘 분류: 문자열, 스택
푼 날짜: 2021년 2월 18일 오후 10:38

## 문제링크

[https://www.acmicpc.net/problem/20001](https://www.acmicpc.net/problem/20001)

## 문제

백준 문제 풀이에 힘들어하는 수진이를 위해 민우는 문제해결에 도움이 되는 고무오리를 준비했다. 민우가 준비한 고무오리는 신비한 능력이 존재하는데, 최근에 풀던 백준 문제를 해결해주는 능력이다. 신비한 고무오리와 함께 수진이의 백준 풀이를 도와주자!

고무오리의 사용법은 다음과 같다.

- "고무오리 디버깅 시작" 이라고 외친다
- 문제들을 풀기 시작한다
- 고무오리를 받으면 최근 풀던 문제를 해결한다
- "고무오리 디버깅 끝" 이라고 외치면 문제풀이를 종료한다.

하지만 고무오리에는 치명적인 문제가 있는데, 풀 문제가 없는데 사용한다면 고무오리는 체벌로 두 문제를 추가한다는 점이다.

## 입력

첫 번째 줄에 "고무오리 디버깅 시작"이라고 주어진다. 두 번째 줄부터 "고무오리" 또는 "문제"가 주어진다. 이는 "고무오리 디버깅 끝"이 주어질 때까지 반복한다. 최대 102줄이 입력으로 주어진다.

## 출력

고무오리 디버깅이 끝날 때, 주어진 문제를 수진이가 해결하였는지 여부에 따라 남은 문제 없이 모든 문제를 해결하였으면 "고무오리야 사랑해"을 출력하고 하나라도 문제가 남았다면 "힝구"를 출력하라.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 512MB

---

## 해설

입력을 받아왔을 때, “고무오리 디버깅 시작”이 입력되면 반복문을 시작한다. “문제”가 입력되면 스택에 문제를 push하고, “고무오리”가 입력되면 스택에서 문제를 pop해준다. “고무오리 디버깅 끝”이 입력되면 반복문을 끝낸다. 스택에 값이 남아있으면 “힝구”를 출력하고, 값이 없으면 “고무오리야 사랑해”를 출력한다. 

## 풀이

공백을 파함한 한 줄을 입력받기 위해서는 `scanf` 나 `cin` 이 아니라 `getline`을 이용해주었다. `getline(cin, input)` 함수를 사용하면 string 자료형의 input에 받아온 입력 한 줄을 저장한다.

만약 “고무오리 디버깅 시작”이 입력되지 않았다면 return 시킨다.

```cpp
string input;
getline(cin, input);

if(input != "고무오리 디버깅 시작") {
    return 0;
}
```

입력의 경우에 따라 다른 작업을 수행해준다.

```cpp
while(true) {
    getline(cin, input);
    
    if(input == "문제") {
        stack.push_back(1);
    } else if (input == "고무오리") {
        if(stack.empty()) {
            stack.push_back(1);
            stack.push_back(1);
        } else {
            stack.pop_back();
        }
    } else if (input == "고무오리 디버깅 끝") {
        break;
    }
}

```

반복문이 종료되었을 때 스택이 비어있으면 “고무오리야 사랑해”를, 차있으면 “힝구”를 출력한다.

```cpp
if(stack.empty()) {
    cout << "고무오리야 사랑해";
} else {
    cout << "힝구";
}
```

---

## 코멘트

`getline(cin, input)` 을 몰라서 좀 꼬였던 것 같다. 기억해놔야지.

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    
    if(input != "고무오리 디버깅 시작") {
        return 0;
    }
    
    vector<int> stack;
    
    while(true) {
        getline(cin, input);
        
        if(input == "문제") {
            stack.push_back(1);
        } else if (input == "고무오리") {
            if(stack.empty()) {
                stack.push_back(1);
                stack.push_back(1);
            } else {
                stack.pop_back();
            }
        } else if (input == "고무오리 디버깅 끝") {
            break;
        }
    }
    
    if(stack.empty()) {
        cout << "고무오리야 사랑해";
    } else {
        cout << "힝구";
    }
    
    return 0;
}
```