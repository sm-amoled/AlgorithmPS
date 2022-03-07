# 잃어버린 괄호

문제 번호: 1541
알고리즘 분류: 그리디
푼 날짜: 2021년 3월 9일 오후 10:26

## 문제링크

[https://www.acmicpc.net/problem/1541](https://www.acmicpc.net/problem/1541)

## 문제

세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

## 입력

첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

## 출력

첫째 줄에 정답을 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

연산기호가 + 또는 - 밖에 없기 때문에, 결국 값은 더해지거나 빼지거나 둘 중 하나이다. 만약에 괄호 앞에 -이 붙어있다면 괄호를 풀었을 때 괄호 안의 연산 기호들이 -는 + 으로, +는 -으로 바꾸어주면 된다. 즉, 굳이 연산의 결과를 최소로 만들기 위해  괄호의 중첩을 복잡하게 따질 필요는 없다. 괄호를 풀면 결국 +냐 -냐이기 때문이다.

다시 말하자면, 최대한 많은 + 를 -를 앞에 둔 괄호로 묶으면 된다. 예시를 들어보자면, 아래의 수식처럼 최대한 많은 +가 -가 되도록 만들어주면 된다. 괄호가 굳이 중복이 될 필요는 없다.

```
  A + B - C + D + E - F - G + H
→ A + B - (C + D + E) - F - (G + H)
```

## 풀이

줄넘김이 입력될 때 까지 입력을 받아야 하므로, 아래와 같이 한 글자씩 읽어들이면서 ‘\n’을 만날 때 까지 반복문을 수행하도록 입력문을 만들어주었다.

```cpp
do {
	input = getchar();

	// 처리
} while(input != '\n');
```

값을 입력받고, 해당 문자가 숫자라면 temp에 숫자 값을 저장한다. 연속해서 숫자가 나오는 경우 한 숫자의 다른 자리 값을 의미하므로, temp에 10을 곱하고 뒤에 들어온 숫자를 더해 올바른 수를 만들어준다. 기호가 들어온 경우 해당 숫자의 입력이 종료되었으므로 계산 결과에 해당 값을 더하거나 빼주어야 한다. 이를 위해 나는 아래의 예시와 같이 값을 저장해주었다. 괄호 안에 +로 묶여있는 값은 한 cache 백터의 원소에 담아주고, -로 분리된 값끼리는 다른 cache 원소에 담아준다. 마지막에 결과를 낼 때 cache[0] (초기값)에서 뒤에 있는 원소들 (빼야하는 값들)을 모두 빼주면 된다. 이를 아래 코드로 구현하였다.

```
  A + B - C + D + E - F - G + H
→ (A + B) - (C + D + E) - F - (G + H)

cache[0] = A + B
cache[1] = C + D + E
cache[2] = F
cache[3] = G + H

result = cache[0] - cache[1] - cache[2] - cache[3]
```

이전에 나온 기호가 +라면 이번 수를 더해주어야 하므로, cache의 맨 뒤 원소에 값을 더해준다. 이전에 나온 기호가 -라면 이번 수부터 괄호가 쳐지므로 앞의 수와 분리되어야 하므로, 새로운 원소를 push하여 값을 넣어준다. 만약 ‘\n’가 기호로 입력된 경우 (나머지) 입력이 종료되었으므로, 입력받던 마지막 수를 이전에 나온 기호에 맞게 처리해주고 반복문을 종료한다.

```cpp
input = getchar();

if(input >= '0' && input <= '9') {
    temp = temp * 10 + (input-'0');
} else if (input == '+') {
    if(addV) {
        cache[cache.size()-1] += temp;
    } else {
        cache.push_back(temp);
    }
    temp = 0;
    addV = true;
} else if (input == '-') {
    if(addV) {
        cache[cache.size()-1] += temp;
    } else {
        cache.push_back(temp);
    }
    temp = 0;
    addV = false;
} else {
    if(addV) {
        cache[cache.size()-1] += temp;
    } else {
        cache.push_back(temp);
    }
}
```

result에 cache[0]을 담고 뒤에 나올 값들을 모두 빼주고 해당 값을 출력하면 올바른 결과를 얻을 수 있다.

```cpp
int result = cache[0];
for(int i = 1; i < cache.size(); i++) {
	  result -= cache[i];
}

cout << result;
```

---

## 코멘트

어렵게 생각할 게 없었다. 그냥 +- 일 뿐인데 말이야 ㅋㅋㅋ

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    char input;
    int temp = 0;
    bool addV = true;
    vector<int> cache(1, 0);
    
    do {
        input = getchar();
        
        if(input >= '0' && input <= '9') {
            temp = temp * 10 + (input-'0');
        } else if (input == '+') {
            if(addV) {
                cache[cache.size()-1] += temp;
            } else {
                cache.push_back(temp);
            }
            temp = 0;
            addV = true;
        } else if (input == '-') {
            if(addV) {
                cache[cache.size()-1] += temp;
            } else {
                cache.push_back(temp);
            }
            temp = 0;
            addV = false;
        } else {
            if(addV) {
                cache[cache.size()-1] += temp;
            } else {
                cache.push_back(temp);
            }
        }
    } while (input != '\n');
      
    int result = cache[0];
    for(int i = 1; i < cache.size(); i++) {
        result -= cache[i];
    }
    
    cout << result;
    
    return 0;
}
```