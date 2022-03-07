# 선 긋기

문제 번호: 2170
알고리즘 분류: 스위핑
푼 날짜: 2021년 4월 24일 오후 12:46

## 문제링크

[https://www.acmicpc.net/problem/2170](https://www.acmicpc.net/problem/2170)

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 192MB

---

## 문제

매우 큰 도화지에 자를 대고 선을 그으려고 한다. 선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다. 선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별할 수 없다고 하자.

이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 선이 여러 번 그려진 곳은 한 번씩만 계산한다.

## 입력

첫째 줄에 선을 그은 횟수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 다음 N개의 줄에는 선을 그을 때 선택한 두 점의 위치 x, y(-1,000,000,000 ≤ x < y ≤ 1,000,000,000)가 주어진다.

## 출력

첫째 줄에 그은 선의 총 길이를 출력한다.

## 해설

선을 그었을 때 겹쳐지는 경우는 하나의 선으로 합쳐주고 겹치지 않으면 새로운 선분이 만들어지는 것으로 생각하면 된다. 

```
1 2 3 4 5 6 7 8 9 10 
--------- (1 ~ 5)
    -------- (3 ~ 6)
              --- (8 ~ 9)

------------  --- Result : 1~6 + 8~9
```

## 풀이

위의 방식대로 선을 그으면서 겹쳐지는지 안겹쳐지는지를 확인하기 위해서는 시작점을 기준으로 정렬을 하여 차례대로 쭉 훑는 방법이 편리하다. 만약에 정렬이 되어있지 않으면 선분의 앞뒤로 확장이 될 수 있기 때문에 계산하기 불편하다. 입력은 `pair<int, int>` 자료형으로 값들을 받아와 `lines` 배열에 저장해주었다.

```cpp
// Input
int N;
cin >> N;

pair<int, int> lines[1000000];
for(int i = 0; i < N; i++) {
    int down, up;
    cin >> down >> up;

    lines[i] = pair<int, int> (down, up);
}

sort(lines, lines+N);
```

위 정렬 코드를 통해 시작점을 기준으로 입력받은 선들이 정렬되어 있으면, 가장 시작점이 작은 선부터 가져와서 확장을 시킨다. 

이를 위해 현재 이어붙이는 선분의 처음과 끝을 나타내는 `left`, `right`를 사용한다. right보다 선분의 시작점이 크다면 현재 선분이 더 이어붙일 수 있는 선분이 없으므로 `result`에 현재 선분의 길이를 더하고 새로운 선분을 만든다. 선분을 더 이어붙일 수 있다면 right 값을 갱신하여 선분을 연장한다.

```cpp
int result = 0;
int left = -1000000000,  right = -1000000000;
for(int i = 0; i < N; i++) {
    if(right < lines[i].first) {
        result += right - left;

        left = lines[i].first;
        right = lines[i].second;
    } else {
        right = max(right, lines[i].second);
    }
}

result += right-left;
cout << result;
```

마지막 선분까지 다 적용을 했으면 현재 만들고 있던 선분까지 result에 길이를 더한 뒤 값을 출력하면 원하는 결과를 얻을 수 있다.

---

## 코멘트

스위핑 알고리즘의 기본! 개념적으로 다 맞게 만들었는데 시간 초과가 계속 나서 괜히 시간을 뺏긴 기분이야. 그 비교문 몇 개의 차이가 시간초과를 만들었을까..?

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int N;
    cin >> N;

    pair<int, int> lines[1000000];
    for(int i = 0; i < N; i++) {
        int down, up;
        cin >> down >> up;

        lines[i] = pair<int, int> (down, up);
    }

    // Calculate
    sort(lines, lines+N);

    int result = 0;
    int left = -1000000000,  right = -1000000000;
    for(int i = 0; i < N; i++) {
        if(right < lines[i].first) {
            result += right - left;

            left = lines[i].first;
            right = lines[i].second;
        } else {
            right = max(right, lines[i].second);
        }
    }

    result += right-left;
    cout << result;

    return 0;
}
```

---

## 문제 해결에 대한 고민

아래 코드를 사용했을 때 시간초과가 발생하였다. 내가 보기에 위에 코드나 밑에 코드나 시간복잡도 차이가 그렇게 클 것 같지는 않은데...  시간이 왜 많이 뺏기는 걸까..? 단순히 조건문의 개수 차이라면 4N개 정도의 명령어 차이일 것 같은데.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> A, pair<int, int> B) {
    return A.first < B.first;
}

int main() {
    // Input
    int N;
    cin >> N;

    pair<int, int> lines[1000000];
    for(int i = 0; i < N; i++) {
        int down, up;
        cin >> down >> up;

        lines[i] = make_pair(down, up);
    }

    // Calculate
    sort(lines, lines+N, cmp);

    int down = lines[0].first;
    int up = lines[0].second;
    int result = up-down;

    for(int i = 0; i < N; i++) {
        if(up >= lines[i].first && lines[i].second > up) {
            result += (lines[i].second - up);
        } 
        else if (up < lines[i].first) {
            result += lines[i].second-lines[i].first;
        }

        up = lines[i].second;
    }

    cout << result;

    return 0;
}
```