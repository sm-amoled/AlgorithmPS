# 접미사 배열

문제 번호: 11656
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 27일 오후 7:44

### 문제 링크

[https://www.acmicpc.net/problem/11656](https://www.acmicpc.net/problem/11656)

## 문제

접미사 배열은 문자열 S의 모든 접미사를 사전순으로 정렬해 놓은 배열이다.

baekjoon의 접미사는 baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n 으로 총 8가지가 있고, 이를 사전순으로 정렬하면, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon이 된다.

문자열 S가 주어졌을 때, 모든 접미사를 사전순으로 정렬한 다음 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000보다 작거나 같다.

## 출력

첫째 줄부터 S의 접미사를 사전순으로 한 줄에 하나씩 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

온전한 단어를 저장해두고, 한 글자씩 없애면서 벡터에 넣어 정렬하면 원하는 결과를 얻을 수 있다. 

## 풀이

1. 단어를 받아와 inputV 벡터에 넣어둔다. 
2. `pop_back()`을 이용해 가장 앞 자리 글자부터 제거하기 위해 벡터를 뒤집어준다. 
3. `pop_back`을 이용해 한 글자씩 없애고, 가장 뒤에서부터 한 글자씩 비어있는 string에 넣으면 필요한 부분의 바로된 글자 배열의 단어를 얻을 수 있다. 이를 stringV 벡터에 저장해둔다.
4. `op_back`으로 한 글자만 남을 때까지 제거하고, stringV 벡터에 있는 문자열을 사전순으로 정렬하여 출력하면 원하는 결과를 얻을 수 있다.

---

## 코멘트

`reverse(start, end)` / `append(howManyTimes, string)` 을 사용하면 편하다!

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> stringV;
    vector<char> inputV;
    string input;

    cin >> input;
    
    for(int i = 0; i < input.size(); i++) {
        inputV.push_back(input[i]);
    }
    reverse(inputV.begin(), inputV.end());
    
    int boundary = inputV.size();
    string subfixStr;

    for(int i = 0; i < boundary; i++) {
        for(int j = inputV.size()-1; j >= 0; j--) {
            subfixStr.append(1, inputV.at(j)); 
        }
        stringV.push_back(subfixStr);
        subfixStr.clear();
        inputV.pop_back();
    }

    sort(stringV.begin(), stringV.end());

    for(int i = 0; i < stringV.size(); i++) {
        cout << stringV.at(i) << '\n';
    }
    return 0;
}
```