# 좌표 압축

문제 번호: 18870
알고리즘 분류: 정렬, 좌표 압축
푼 날짜: 2021년 7월 17일 오후 6:16

## 문제링크

[https://www.acmicpc.net/problem/18870](https://www.acmicpc.net/problem/18870)

## 문제

수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

## 입력

첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

## 출력

첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

## 제한

- 1 ≤ N ≤ 1,000,000
- -10^9 ≤ X'i ≤ 10^9

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 512MB

---

## 해설

입력받은 값들을 벡터에 저장해두고, 이 벡터를 복사하여 압축을 위한 벡터를 하나 만들어준다.

압축을 하는 과정은 아래와 같다.

1. 0, 1, 2 ... 와 같은 정수로 치환하기 위해 값들을 오름차순으로 정렬해준다.
2. 중복되는 값은 중복되는 값으로 치환해주게되므로, 중복값을 제거해준다.

압축된 벡터에는 입력받은 값들이 중복이 제거된 상태로 오름차순으로 정렬되어있다. 원하는 원소의 index 값을 출력하면 해당 값이 압축된 좌표값이다.

## 풀이

값들을 입력받아준다.

```cpp
int N;
cin >> N;

vector<int> values(N);
vector<int> ordered;
for(int i = 0; i < N; i++) {
    cin >> values[i];
}
```

`values` 벡터에서 `ordered` 벡터로 값을 복사해오고, 오름차순으로 정렬해준 뒤 중복되는 값을 제거해준다. `resize()`를 사용해주는 이유는, unique 함수가 중복값을 삭제하는게 아니라, 뒤로 보내버리기 때문에 size를 조절해주어야 중복을 제거한 값들만 갖는 벡터로 만들 수 있다.

```cpp
ordered.assign(values.begin(), values.end());
sort(ordered.begin(), ordered.end());
ordered.resize(unique(ordered.begin(), ordered.end())-ordered.begin());
```

현재 `ordered` 벡터가 정렬된 상태이기 때문에, 이진탐색(binary search)를 통해 해당 값의 index를 출력해주면 시간을 아낄 수 있다. index를 출력할 때는, `lower_bound` 함수가 iterator를 반환하기 때문에, 아래와 같이 `begin()` iterator를 빼주어야 index를 구할 수 있다.

```cpp
for(auto v : values) {
    cout << lower_bound(ordered.begin(), ordered.end(), v) - ordered.begin() << ' ';
}
```

---

## 코멘트

좌표 압축... 나중에 써먹을 데가 있겠지..? ㅋㅋㅋ

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> values(N);
    vector<int> ordered;
    for(int i = 0; i < N; i++) {
        cin >> values[i];
    }
    
    ordered.assign(values.begin(), values.end());
    sort(ordered.begin(), ordered.end());
    ordered.resize(unique(ordered.begin(), ordered.end())-ordered.begin());

    
    for(auto v : values) {
        cout << lower_bound(ordered.begin(), ordered.end(), v) - ordered.begin() << ' ';
    }
}
```