# N과 M (4)

문제 번호: 15652
알고리즘 분류: 백 트래킹
푼 날짜: 2021년 3월 4일 오후 9:48

## 문제링크

[https://www.acmicpc.net/problem/15652](https://www.acmicpc.net/problem/15652)

## 문제

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.
- 고른 수열은 비내림차순이어야 한다.
    - 길이가 K인 수열 A가 A(1) ≤ A(2) ≤ ... ≤ A(k-1) ≤ A(k)를 만족하면, 비내림차순이라고 한다.

## 입력

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

## 출력

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 512MB

---

## 해설

이 문제는 N과 M 문제의 해답 코드를 조금 수정해서 풀면 쉽게 문제를 해결할 수 있다. 

## 풀이

재귀함수인 sequence에 현재 수열에 넣은 값을 인자로 전달한다. 다음 sequence에서는 해당 값에서부터 차례대로 수열에 수를 집어넣으면서 수열을 채워나간다. 

```cpp
void sequence(vector<int> arr, int N, int before, int depth) {
    if(depth == 0) {
        for(auto x : arr) {
            cout << x << " ";
        } cout << '\n';
        return;
    }
    
    for(int i = before; i <= N; i++) {
        arr.push_back(i);
        sequence(arr, N, i, depth-1);
        arr.pop_back();
    }
}
```

---

## 코멘트

N과 M 시리즈는 다 비슷해서 조금만 수정해주면 쉽게 해결이 되는 것 같다.

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

void sequence(vector<int> arr, int N, int before, int depth) {
    if(depth == 0) {
        for(auto x : arr) {
            cout << x << " ";
        } cout << '\n';
        return;
    }
    
    for(int i = before; i <= N; i++) {
        arr.push_back(i);
        sequence(arr, N, i, depth-1);
        arr.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> arr;
    
    sequence(arr, N, 1, M);

	return 0;
}
```