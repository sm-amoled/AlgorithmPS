# N과 M (3)

문제 번호: 15651
알고리즘 분류: 백 트래킹
푼 날짜: 2021년 3월 3일 오후 11:14

## 문제링크

[https://www.acmicpc.net/problem/15651](https://www.acmicpc.net/problem/15651)

## 문제

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.

## 입력

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

## 출력

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 512MB

---

## 해설

15649번 N과 M (1)을 변형한 문제이다. 이 문제도 해당 문제의 코드를 조금만 수정해주면 쉽게 해결할 수 있다. 여기에서 중복이 가능하도록 used 검사하는 항목을 빼면 된다.

## 풀이

N과 M (1) 코드에서 중복을 제거하기 위해서 사용했던 used 벡터를 제거하고, 대신 총 수의 개수를 전달하기 위한 N을 인자로 함께 전달해주었다.

```cpp
void sequence(vector<int> arr, int N, int depth) {
    if(depth == 0) {
        for(auto x : arr) {
            cout << x << " ";
        } cout << '\n';
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        arr.push_back(i);
        sequence(arr, N, depth-1);
        arr.pop_back();
    }
}
```

---

## 코멘트

코드에 대한 자세한 풀이는 N과 M (1)에 잘 적혀있습니다!

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

void sequence(vector<int> arr, int N, int depth) {
    if(depth == 0) {
        for(auto x : arr) {
            cout << x << " ";
        } cout << '\n';
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        arr.push_back(i);
        sequence(arr, N, depth-1);
        arr.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> arr;
    
    sequence(arr, N, M);

	return 0;
}
```