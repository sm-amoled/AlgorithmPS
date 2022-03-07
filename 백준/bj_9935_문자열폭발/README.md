# 문자열 폭발

문제 번호: 9935
알고리즘 분류: 문자열, 스택
푼 날짜: 2021년 2월 13일 오후 10:18

## 문제링크

[https://www.acmicpc.net/problem/9935](https://www.acmicpc.net/problem/9935)

## 문제

상근이는 문자열에 폭발 문자열을 심어 놓았다. 폭발 문자열이 폭발하면 그 문자는 문자열에서 사라지며, 남은 문자열은 합쳐지게 된다.

폭발은 다음과 같은 과정으로 진행된다.

- 문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
- 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
- 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.

상근이는 모든 폭발이 끝난 후에 어떤 문자열이 남는지 구해보려고 한다. 남아있는 문자가 없는 경우가 있다. 이때는 "FRULA"를 출력한다.

폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.

## 입력

첫째 줄에 문자열이 주어진다. 문자열의 길이는 1보다 크거나 같고, 1,000,000보다 작거나 같다.

둘째 줄에 폭발 문자열이 주어진다. 길이는 1보다 크거나 같고, 36보다 작거나 같다.

두 문자열은 모두 알파벳 소문자와 대문자, 숫자 0, 1, ..., 9로만 이루어져 있다.

## 출력

첫째 줄에 모든 폭발이 끝난 후 남은 문자열을 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

입력받은 문자열을 str, 폭탄을 담은 문자열을 bomb, 폭탄이 발견되지 않아 살아남은 채로 지나간 문자를 담는 문자열을 survived라 하자.

str에서 index를 증가시키며 해당 원소를 survived 벡터에 push하면서 survived 벡터 내에 폭탄이 있는지 없는지를 찾는다. 만약 폭탄이 있다면 폭탄의 사이즈만큼 원소를 pop해주고, survived에서 검사가 필요한 부분에서 폭탄과 겹치는 문자열 부분이 있는지를 검사한다. survived의 마지막 원소까지 폭탄과 겹치는 문자열을 확인한 다음, str에서 index를 증가시키며 위 과정을 반복한다.

![%E1%84%86%E1%85%AE%E1%86%AB%E1%84%8C%E1%85%A1%E1%84%8B%E1%85%A7%E1%86%AF%20%E1%84%91%E1%85%A9%E1%86%A8%E1%84%87%E1%85%A1%E1%86%AF%20a1c726bfb1ce4d7b92efb434009ed46f/E89CABE2-EC5F-49D0-915E-3E1691DD4BDC.jpeg](%E1%84%86%E1%85%AE%E1%86%AB%E1%84%8C%E1%85%A1%E1%84%8B%E1%85%A7%E1%86%AF%20%E1%84%91%E1%85%A9%E1%86%A8%E1%84%87%E1%85%A1%E1%86%AF%20a1c726bfb1ce4d7b92efb434009ed46f/E89CABE2-EC5F-49D0-915E-3E1691DD4BDC.jpeg)

폭탄이 완성되어 터진 경우에는 str에서 push 해온 문자 하나가 폭탄을 만들 수 있기 때문에 survived에서 미리 앞선 원소들을 검사하여 bombIndex를 쌓아 폭탄이 완성될 것을 준비해야한다.

![%E1%84%86%E1%85%AE%E1%86%AB%E1%84%8C%E1%85%A1%E1%84%8B%E1%85%A7%E1%86%AF%20%E1%84%91%E1%85%A9%E1%86%A8%E1%84%87%E1%85%A1%E1%86%AF%20a1c726bfb1ce4d7b92efb434009ed46f/AA43639A-B697-403C-AF8E-BF58D4ED6460.jpeg](%E1%84%86%E1%85%AE%E1%86%AB%E1%84%8C%E1%85%A1%E1%84%8B%E1%85%A7%E1%86%AF%20%E1%84%91%E1%85%A9%E1%86%A8%E1%84%87%E1%85%A1%E1%86%AF%20a1c726bfb1ce4d7b92efb434009ed46f/AA43639A-B697-403C-AF8E-BF58D4ED6460.jpeg)

## 풀이

우선 3개의 벡터를 선언해주고, str과 bomb 벡터에는 필요한 값들을 입력받는다.

```cpp
vector<char> str;
vector<char> bomb;
vector<char> survived;

while(true) {
    char temp = getchar();
    if(temp == '\n') break;
    
    str.push_back(temp);
}
 
while(true) {
    char temp = getchar();
    if(temp == '\n') break;
    
    bomb.push_back(temp);
}
```

str 벡터에서 값을 하나씩 survived 벡터에 push한다. 폭탄이 있는지를 검사하는 과정은 survived 벡터에서만 일어난다.

```cpp
survived.push_back(str[strIndex]);
survivedIndex = survived.size() - 1;

if(survived[survivedIndex] == bomb[bombIndex]) {
    bombIndex++;
} else if (survived[survivedIndex] == bomb[0]) {
    bombIndex = 1;
} else {
    bombIndex = 0;
}
```

만약 bombIndex가 `bomb.size()`와 같다면 (폭탄 문자열을 찾았다면) 폭탄 문자열을 survived 벡터에서 pop시켜준다. 그 다음, survived 벡터의 끝에서부터 `bomb.size()-1`개의 문자에서 폭탄 문자열의 부분 문자열이 있는지를 검사한다. (그 이전에 폭탄이 있었다면 이미 발견되어 폭발하였을 것이다. 여기에서 검사하는 것은 다음 str의 문자가 push 되었을 때 폭탄이 완성될 수 있는 가능성이 있는 부분 문자열을 검사하는 것이다.)

```cpp
if(bombIndex == bomb.size()) {
    for(int i = 0; i < bomb.size(); i++) {
        survived.pop_back();
    }
    bombIndex = 0;
    
    survivedIndex = (int)survived.size() - (int)bomb.size() + 1;
    survivedIndex = (survivedIndex>=0)? survivedIndex:0;
    for(; survivedIndex < survived.size(); survivedIndex++) {
        
        if(survived[survivedIndex] == bomb[bombIndex]) {
            bombIndex++;
        } else if (survived[survivedIndex] == bomb[0]) {
            bombIndex = 1;
        } else {
            bombIndex = 0;
        }
    }
}
```

위 과정을 `strIndex`가 `str.size()`와 같아질 때 까지 반복한다. 

```cpp
while(strIndex < str.size()) {

		//위의 코드들

		strIndex++;
}
```

만약 문자열이 모두 폭발한 경우에는 “FRULA”를 출력하고, 아니면 남아있는 survived 문자열을 출력한다.

```cpp
if(survived.size() > 0) {
    for(auto x : survived) {
        cout << x;
    }
} else {
    cout << "FRULA";
}
```

---

## 코멘트

어젯밤에 2시간 넘게 고민하고 못풀었는데, 아침에 와서 코드 한 두 줄 수정하고 나니 바로 풀려서 한 번에 통과가 되었다. 역시 잠을 자야 하는건가..? ㅋㅋㅋ

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
    
    vector<char> str;
    vector<char> bomb;
    vector<char> survived;
    
    while(true) {
        char temp = getchar();
        if(temp == '\n') break;
        
        str.push_back(temp);
    }
     
    while(true) {
        char temp = getchar();
        if(temp == '\n') break;
        
        bomb.push_back(temp);
    } 
    
    int strIndex = 0;
    int bombIndex = 0;
    int survivedIndex;
    
    while(strIndex < str.size()) {
        survived.push_back(str[strIndex]);
        survivedIndex = survived.size() - 1;
        
        if(survived[survivedIndex] == bomb[bombIndex]) {
            bombIndex++;
        } else if (survived[survivedIndex] == bomb[0]) {
            bombIndex = 1;
        } else {
            bombIndex = 0;
        }
        
        if(bombIndex == bomb.size()) {
            for(int i = 0; i < bomb.size(); i++) {
                survived.pop_back();
            }
            bombIndex = 0;
            
            survivedIndex = (int)survived.size() - (int)bomb.size() + 1;
            survivedIndex = (survivedIndex>=0)? survivedIndex:0;
            for(; survivedIndex < survived.size(); survivedIndex++) {
                
                if(survived[survivedIndex] == bomb[bombIndex]) {
                    bombIndex++;
                } else if (survived[survivedIndex] == bomb[0]) {
                    bombIndex = 1;
                } else {
                    bombIndex = 0;
                }
            }
        }
    
        strIndex++;
    }
    
    if(survived.size() > 0) {
        for(auto x : survived) {
            cout << x;
        }
    } else {
        cout << "FRULA";
    }
    return 0;
}
```