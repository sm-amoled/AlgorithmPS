# N과 M (2)

문제 번호: 15650
알고리즘 분류: 백 트래킹
푼 날짜: 2021년 3월 3일 오후 11:03

## 문제링크

[https://www.acmicpc.net/problem/15650](https://www.acmicpc.net/problem/15650)

## 문제

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
- 고른 수열은 오름차순이어야 한다.

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

15649번 문제인 N과 M(1)에서 조건이 하나 추가된 문제이다. 여기에서 만든 수열들 중에서 오름차순으로 증가하는 수열만을 출력해야한다. 이를 위해 15649번 문제의 해설에 담아둔 코드에서 일부를 변경해주었다.

## 풀이

> 코드에 대한 자세한 설명은 N과 M (1)에 실어뒀습니다 ㅎㅎ

sequence 함수에 인자로 before를 추가하였다. 이전에 선택한 값이 before을 통해 인자로 전달되면, 사용하지 않은 숫자를 1부터 찾는 것이 아니라 before+1 값부터 찾아서 수열에 집어넣으면 오름차순의 수열만 만들 수 있다.

```cpp
void sequence(vector<bool> used, vector<int> arr, int before, int depth) {
    if(depth == 0) {
        for(auto x : arr) {
            cout << x << " ";
        } cout << '\n';
        return;
    }
    
    for(int i = before+1; i < used.size(); i++) {
        if(used[i] == false) {
            arr.push_back(i);
            used[i] = true;
            sequence(used, arr, i, depth-1);
            arr.pop_back();
            used[i] = false;
        }
    }
}
```

---

## 코멘트

코드에 대한 자세한 설명은 N과 M (1)에 실어뒀습니다 ㅎㅎ

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

void sequence(vector<bool> used, vector<int> arr, int before, int depth) {
    if(depth == 0) {
        for(auto x : arr) {
            cout << x << " ";
        } cout << '\n';
        return;
    }
    
    for(int i = before+1; i < used.size(); i++) {
        if(used[i] == false) {
            arr.push_back(i);
            used[i] = true;
            sequence(used, arr, i, depth-1);
            arr.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> used(N+1, false);
    vector<int> arr;
    
    sequence(used, arr, 0, M);

	return 0;
}
```