# 오큰수

문제 번호: 17298
알고리즘 분류: 스택
푼 날짜: 2021년 2월 14일 오후 2:12

## 문제링크

[https://www.acmicpc.net/problem/17298](https://www.acmicpc.net/problem/17298)

## 문제

크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

## 입력

첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

## 출력

총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 512MB

---

## 해설

비교하고자 하는 원소값의 오른쪽에서 구하고자 하는 값을 찾을 수 있기 때문에, 수열의 끝에서부터 시작점으로 거꾸로 스택을 쌓으며 계산하는 방법을 사용한다. 스택에는 내림차순을 유지하면 값을 쌓아나간다.

## 풀이

먼저 스택에 inf 값(1000001)을 push하여, -1을 출력하기 위해 비교할 가장 큰 값을 만들어둔다.

![%E1%84%8B%E1%85%A9%E1%84%8F%E1%85%B3%E1%86%AB%E1%84%89%E1%85%AE%20fd9d10491d254d5ab385280ea1c6778d/CBC41BF6-7E70-472D-B9EA-90CC0965A43B.jpeg](%E1%84%8B%E1%85%A9%E1%84%8F%E1%85%B3%E1%86%AB%E1%84%89%E1%85%AE%20fd9d10491d254d5ab385280ea1c6778d/CBC41BF6-7E70-472D-B9EA-90CC0965A43B.jpeg)

입력값을 뒤에서부터 하나씩 스택에 넣어준다. 만약 `stack.back()`이 해당 원소보다 크다면 answer에 `back()`의 값을 넣고 입력 값을 그대로 push한다. 반대로 해당 원소보다 작다면 원소보다 큰 값이 나올 때 까지 `stack.pop_back()`을 반복한다. 뒤에 나올 원소에서 값을 비교할 때는 작은 값들이 불필요하기 때문에, 이를 pop해주어 시간과 공간을 아낄 수 있다. 그 후 `back()`의 값을 answer에 넣고 입력값을 push한다. 이를 코드로 옮기면 아래와 같다.

```cpp
stack.push_back(1000001);

for(int i = A-1; i >= 0; i--) {
    while(stack.back() <= NGE[i]) {
        stack.pop_back();
    }
    answer[i] = (1000001 == stack.back())? -1:stack.back();
    stack.push_back(NGE[i]);
}
```

answer를 그대로 출력하면 원하는 결과를 얻을 수 있다.

---

## 코멘트

조금 더 시간을 아끼는 방법을 찾았어야 했는데... 필요없는 값을 pop 해야한다는 건 기억했는데, pop하는 대상을 찾는게 쉽지않았던 것 같다.

## 고민

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A;
    cin >> A;
    
    vector<int> NGE(A);
    vector<int> stack;
    vector<int> index;
    
    
    if(A == 1) {
        cin >> NGE[0];
        cout << "-1";
        return 0;
    }
    // initiate Value
    int indexIndex = 0;
    
    for(int i = 0; i < A; i++) {
        cin >> NGE[i];
    }
    
    for(int i = A-1; i >= 1; i--) {
        if(NGE[i-1] < NGE[i]) {
            stack.push_back(NGE[i]);
            index.push_back(i);
        }
    }
    
    if(stack.empty()) {
        for(int i = 0; i < A; i++) {
            NGE[i] = -1;
        }
    } else {
        for(int i = 0; i < A; i++) {
            if(i == index.back()) {
                stack.pop_back();
                index.pop_back();
            }
            
            int temp = -1;
            for(int j = stack.size()-1; j >= 0; j--) {
                if(NGE[i] < stack[j]) {
                    temp = stack[j];
                    break;
                }
            }
            NGE[i] = temp;
        }
    }
    
    for(auto x : NGE) {
        cout << x << " ";
    }
    cout << '\n';
    
    return 0;
}
```

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

    int A;
    cin >> A;
    
    vector<int> NGE(A);
    vector<int> stack;
    vector<int> answer(A);
    
    for(int i = 0; i < A; i++) {
        cin >> NGE[i];
    }
    
    stack.push_back(1000001);
    
    for(int i = A-1; i >= 0; i--) {
        while(stack.back() <= NGE[i]) {
            stack.pop_back();
        }
        answer[i] = (1000001 == stack.back())? -1:stack.back();
        stack.push_back(NGE[i]);
    }
    
    for(auto x : answer) {
        cout << x << " ";
    }
    cout << '\n';
    
    return 0;
}
```