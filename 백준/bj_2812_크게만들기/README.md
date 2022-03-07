# 크게 만들기

문제 번호: 2812
알고리즘 분류: 스택
푼 날짜: 2021년 2월 16일 오후 9:53

## 문제링크

[https://www.acmicpc.net/problem/2812](https://www.acmicpc.net/problem/2812)

## 문제

N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)

둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.

## 출력

입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

큰 수를 만드는 규칙을 그대로 스택에 옮겨 적용하면 쉽게 해결할 수 있는 문제. 큰 수를 만드는 규칙은 앞에 있을 수록, 큰 수 앞에 작은 수가 있으면 우선 제거 대상이다.

## 풀이

각 자리 숫자를 입력받을 때마다 그 숫자보다 작은 숫자는 스택에서 pop해버리고 해당 숫자를 push 한다. pop의 횟수가 K를 넘어가면 push만 수행한다.

```cpp
for(int i = 0; i < N; i++) {
    while(K && !numb.empty() && numb.back() < str[i]-'0') {
        numb.pop_back();
        K--;
    }
    
    numb.push_back(str[i]-'0');
}
```

만약 숫자 입력을 다 받았는데도 K를 못채웠다면 스택을 출력할 때 맨 앞에서부터 남은 K값만큼 출력을 뛰어넘는다.

```cpp
for(int i = 0; i < numb.size()-K; i++) {
    cout << numb[i];
}
```

---

## 코멘트

살짝 어려웠다. 문제 자체가 어려웠다기 보다는, 규칙을 찾는게 어려웠다. 그게 문제 자체가 어려웠다고 표현해야 하는건가..? ㅋㅋㅋ

## 고민

이 부분을 떠올리는게 조금 어려웠다. 풀이를 보고 겨우 아! 이렇게 만들면 됐구나! 싶더라구. 나는 앞에 문자랑 비교해서 input이 크면 back()을 pop하고 push 하는 방법을 생각했었는데, 조금 문제가 있더라구. 근데 이렇게 하면 back()이 input보다 작은 동안 계속 pop을 하니깐 문제를 풀 수 있었다.

```cpp
while(K && !numb.empty() && numb.back() < str[i]-'0') {
    numb.pop_back();
    K--;
}
```

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    
    int N, K;
    string str;
    cin >> N >> K;
    cin >> str;
    vector<int> numb;
    
    for(int i = 0; i < N; i++) {
        while(K && !numb.empty() && numb.back() < str[i]-'0') {
            numb.pop_back();
            K--;
        }
        
        numb.push_back(str[i]-'0');
    }
    
    for(int i = 0; i < numb.size()-K; i++) {
        cout << numb[i];
    }
    return 0;
}
```