# 스택 수열

문제 번호: 1874
알고리즘 분류: 스택
푼 날짜: 2021년 2월 10일 오후 9:00

## 문제링크

[https://www.acmicpc.net/problem/1874](https://www.acmicpc.net/problem/1874)

## 문제

스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.

1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.

## 입력

첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 물론 같은 정수가 두 번 나오는 일은 없다.

## 출력

입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

## 풀이

수열의 값을 차례로 하나씩 읽어오고, 해당 값이 stack의 top에 있을 때까지 push를 한다. push를 수행할 때는 +를 instruction 벡터에 삽입한다.

```cpp
cin >> currentValue;

if(top == -1) {
    stack.push_back(k++);
    top++;
    instruction.push_back('+');
} 
```

top에 해당 값이 있으면 pop하여 다음 수열의 값으로 넘어가고, 해당 값이 없으면 (push를 끝까지 해도 없으면) 만들 수 없는 수열이므로 NO를 출력한다. pop을 수행할 때는 -를 instruction 벡터에 삽입한다.

```cpp
while(stack[top] != currentValue) {
    stack.push_back(k++);
    top++;
    instruction.push_back('+');
    
    if(k > N+1) {
        cout << "NO\n";
        return 0;
    }
}
stack.pop_back();
top--;
instruction.push_back('-');
```

위 코드를 수열의 숫자만큼 반복하여 만들어진 instruction 벡터를 출력한다.

```cpp
for(auto x : instruction) {
    cout << x << "\n";
}
```

---

## 코멘트

아직은 할 만 하다!

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int top = -1, k = 1, currentValue;
    vector<int> stack;
    vector<char> instruction;
    
    for(int i = 0; i < N; i++) {
        cin >> currentValue;
        
        if(top == -1) {
            stack.push_back(k++);
            top++;
            instruction.push_back('+');
        } 
        
        while(stack[top] != currentValue) {
            
            stack.push_back(k++);
            top++;
            instruction.push_back('+');
            
            if(k > N+1) {
                cout << "NO\n";
                return 0;
            }
        }
        
        stack.pop_back();
        top--;
        instruction.push_back('-');
    }
    
    for(auto x : instruction) {
        cout << x << "\n";
    }
    
    return 0;
}
```