# 후위 표기식 2

문제 번호: 1935
알고리즘 분류: 수학, 스택
푼 날짜: 2021년 2월 14일 오후 9:47

## 문제링크

[https://www.acmicpc.net/problem/1935](https://www.acmicpc.net/problem/1935)

## 문제

후위 표기식과 각 피연산자에 대응하는 값들이 주어져 있을 때, 그 식을 계산하는 프로그램을 작성하시오.

## 입력

첫째 줄에 피연산자의 개수(1 ≤ N ≤ 26) 가 주어진다. 그리고 둘째 줄에는 후위 표기식이 주어진다. (여기서 피연산자는 A~Z의 영대문자이며, A부터 순서대로 N개의 영대문자만이 사용되며, 길이는 100을 넘지 않는다) 그리고 셋째 줄부터 N+2번째 줄까지는 각 피연산자에 대응하는 값이 주어진다. (3번째 줄에는 A에 해당하는 값, 4번째 줄에는 B에 해당하는값 , 5번째 줄에는 C ...이 주어진다, 그리고 피연산자에 대응 하는 값은 정수이다)

## 출력

계산 결과를 소숫점 둘째 자리까지 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

숫자는 스택에 push 하고, 연산자가 나와 계산할 때마다 숫자를 2개 pop하여서 계산하고 결과를 push 한다. 마지막에 스택에 남아있는 숫자가 연산결과이다.

## 풀이

문자열을 str, 계산에 사용할 스택을 stack, 변수가 담긴 벡터는 variable이라고 하자. str에서 문자 하나를 가져올 때, 숫자이면 (알파벳이면) stack에 variable에서 적절한 값을 찾아 push해주고, 연산자이면 2개의 숫자를 stack에서 pop해와 적절한 연산을 시행해주고 stack에 push한다.

```cpp
for(int i = 0; i < str.size(); i++) {
    temp = str[i];
    
    if(temp >= 'A' && temp <= 'Z') {
        stack.push_back(variable[temp-'A']);
    } else {
        double a, b;
        b = stack.back();
        stack.pop_back();
        a = stack.back();
        stack.pop_back();
                
        switch(temp) {
            case '+':
                stack.push_back(a+b);
                break;
            case '-':
                stack.push_back(a-b);
                break;
            case '*':
                stack.push_back(a*b);
                break;
            case '/':
                stack.push_back(a/b);
                break;
        }
    }
}

```

소숫점 2자리를 남기고 출력하기 위해, 아래와 같은 코드를 사용해주었다. `setprecision(N)`은 가장 큰 자리의 수부터 N자리까지 출력한다는 의미이고, `fixed`는 소숫점을 고정한다는 의미이다. 이 둘을 같이 쓰면 소숫점으로부터 N자리까지 출력한다는 의미가 된다.

```cpp
#include <iomanip>

cout << setprecision(2) << fixed;
cout << calc.back();
```

---

## 코멘트

입출력으로 고생 좀 했다. 휴...

## 고민

실수를 한가지 했다. 분명 입출력 가속 코드랑 get~(), printf() 같은 함수를 같이 사용하지 말라고 했는데, `getchar()`를 사용했다가 봉변을 당했다. 한 30분을 쓴 것 같다... 문자열을 입력받을 때는 그냥 string 타입으로 한 번에 입력을 받는게 제일 간편하고 빠른 방법인 것 같다!

---

## 코드

```cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    
    string stack;
    cin >> stack;
    
    vector<int> variable(N);
    vector<double> calc;
    
    char temp;
    
    for(int i = 0; i < N; i++) {
        cin >> variable[i];
    }
    
    for(int i = 0; i < stack.size(); i++) {
        temp = stack[i];
        
        if(temp >= 'A' && temp <= 'Z') {
            calc.push_back(variable[temp-'A']);
        } else {
            double a, b;
            b = calc.back();
            calc.pop_back();
            a = calc.back();
            calc.pop_back();
                    
            switch(temp) {
                case '+':
                    calc.push_back(a+b);
                    break;
                case '-':
                    calc.push_back(a-b);
                    break;
                case '*':
                    calc.push_back(a*b);
                    break;
                case '/':
                    calc.push_back(a/b);
                    break;
            }
        }
    }
    
    cout << setprecision(2) << fixed;
    cout << calc.back();
    
    return 0;
}
```