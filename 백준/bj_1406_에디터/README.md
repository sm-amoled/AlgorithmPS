# 에디터

문제 번호: 1406
알고리즘 분류: 스택
푼 날짜: 2021년 2월 11일 오전 10:02

## 문제링크

[https://www.acmicpc.net/problem/1406](https://www.acmicpc.net/problem/1406)

## 문제

한 줄로 된 간단한 에디터를 구현하려고 한다. 이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 입력할 수 있다.

이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽), 문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다. 즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.

이 편집기가 지원하는 명령어는 다음과 같다.

- `L` : 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
- `D` : 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
- `B` : 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨) 삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
- `P $` $라는 문자를 커서 왼쪽에 추가함

초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때, 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오. 단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.

## 입력

첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 이 문자열은 길이가 N이고, 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다. 둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 M(1 ≤ M ≤ 500,000)이 주어진다. 셋째 줄부터 M개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 명령어는 위의 네 가지 중 하나의 형태로만 주어진다.

## 출력

첫째 줄에 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 출력한다.

## 조건

- 시간 제한 : 0.3s
- 메모리 제한 : 512MB

---

## 해설

1개의 배열을 이용해 스택을 구현하려면 삽입/삭제를 위해 문자들을 옮겨담는 과정에서 시간이 많이 소요된다. 커서를 기준으로 하는 2개의 배열을 이용하면 쉽게 해결할 수 있다. 

## 풀이

커서를 기준으로 하여 2개의 스택을 이용한다. 커서가 움직이면 1번 스택과 2번 스택 사이에서 원소를 하나씩 옮기고, 추가나 삭제하는 경우 1번 스택에서 push/pop을 구현해주면 쉽게 해결이 가능하다. 이를 위해 스택의 방향은 꼬리가 마주보는 형태로 구현하였다.

```
1begin [000000 1end <cursor> 2end 000000] 2begin
```

우선 커서의 초기 위치가 가장 오른쪽이므로, 받아온 문자열은 왼쪽 스택에 쌓아준다.

```cpp
cin >> s;
cin >> n;

vector<char> leftStack(s.begin(), s.end());
vector<char> rightStack;
```

switch 구문으로 입력받은 명령어마다 다른 역할을 수행하도록 분기시켜주었다. 2개의 스택을 이용해 명령어들의 처리는 쉽게 해결 가능하다.

```cpp
while(n--) {
    char inst;
    cin >> inst;
    
    switch(inst) {
        case 'L':
            if(leftStack.size()) {
                rightStack.push_back(leftStack.back());
                leftStack.pop_back();
            }
        break;
        case 'D':
            if(rightStack.size()) {
                leftStack.push_back(rightStack.back());
                rightStack.pop_back();
            }
        break;
        case 'B':
            if(leftStack.size()) leftStack.pop_back();
        break;
        case 'P':
            char temp;
            cin >> temp;
            leftStack.push_back(temp);
        break;
    }
}
```

출력은 1번째 스택은 정상적으로, 2번째 스택은 반대방향으로 진행해주어야 한다.

```cpp
for(int i = 0; i < leftStack.size(); i++) {
    cout << leftStack[i];
}
for(int i = rightStack.size()-1; i >= 0; i--) {
    cout << rightStack[i];
}
```

---

## 코멘트

### 고민

아래는 스택을 1개 사용하여 구현하려고 시도했던 코드이다. 아래의 코드를 수행하면 배열 내에 원소를 삽입할 때 1칸씩 문자들을 다 움직이고 빈 공간에 문자를 넣는 방식이라 시간효율이 나오지 않아 시간초과가 나온다. 2개의 스택을 이용하면 쉽게 해결이 가능하다.

```cpp
// 시간초과 코드
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    char str[600000];
    cin >> str;
    int length = 0, index = 0;
    while(str[index] != 0) {
        length++; index++;
    }
    int cursor = length;
    
    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        string instruction;
        cin >> instruction;
        
        if(instruction == "L") {
            cursor = (cursor == 0)? 0:cursor-1;
        } else if (instruction == "D") {
            cursor = (cursor == length)? length:cursor+1;
        } else if (instruction == "B") {
            if(cursor > 0) {
                for(int k = cursor; k <= length; k++) {
                    str[k-1] = str[k];
                }
                length--;
                cursor--;
            }
        } else {
            for(int k = length; k >= cursor; k--) {
                    str[k+1] = str[k];
            }
            cin >> str[cursor];
            length++;
            cursor++;
        }
    }
    
    cout << str;
    return 0;
}
```

---

## 코드

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    
    cin >> s;
    cin >> n;
    
    vector<char> leftStack(s.begin(), s.end());
    vector<char> rightStack;
    
    while(n--) {
        char inst;
        cin >> inst;
        
        switch(inst) {
            case 'L':
                if(leftStack.size()) {
                    rightStack.push_back(leftStack.back());
                    leftStack.pop_back();
                }
            break;
            case 'D':
                if(rightStack.size()) {
                    leftStack.push_back(rightStack.back());
                    rightStack.pop_back();
                }
            break;
            case 'B':
                if(leftStack.size()) leftStack.pop_back();
            break;
            case 'P':
                char temp;
                cin >> temp;
                leftStack.push_back(temp);
            break;
        }
    }
    
    for(int i = 0; i < leftStack.size(); i++) {
        cout << leftStack[i];
    }
    for(int i = rightStack.size()-1; i >= 0; i--) {
        cout << rightStack[i];
    }
    
    return 0;
}
```