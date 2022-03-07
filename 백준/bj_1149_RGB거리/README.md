# RGB거리

문제 번호: 1149
알고리즘 분류: DP
푼 날짜: 2021년 2월 6일 오후 5:15

## 문제링크

[https://www.acmicpc.net/problem/1149](https://www.acmicpc.net/problem/1149)

## 문제

RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

- 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
- N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
- i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

## 입력

첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

## 출력

첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

## 조건

- 시간 제한 : 0.5s
- 메모리 제한 : 128MB

---

## 해설

문제의 조건을 단순하게 말하자면, 이웃한 집의 색은 달라야 하며, 금액은 최소한으로 만들어라! 가 된다. 나는 다음과 같은 방식으로 문제를 해결하였다. k번째 집을 R로 칠하는 경우, k-1번째 집의 색이 R이 아니면서 k-1번째 집까지의 비용이 최소인 경우를 선택한다. 이때의 금액에 R을 칠하는 비용을 더하면 k번째 집을 R로 칠하고 k번째 집까지 칠하는 비용이 최소인 방법이 된다. 가장 마지막에 n번째 집을 R, G, B로 칠하는 경우 중에서 최솟값을 출력한다.

## 풀이

k번째 집까지의 색을 선택했을 때의 총 금액을 저장할 벡터인 costR, costG, costB 벡터를 선언하였다. 빨간색(R)을 선택했다면 costG[k-1], costB[k-1]의 값 중에서 작은 값에 빨간색을 칠하는 비용을 더해 costR[k]에 저장한다. 다른 색도 마찬가지. 이런 방식으로 값을 저장하면 해당 집은 항상 이전 집과 다른 색에 칠해지게 된다. (k번째 R 집은 G나 B를 칠한 k-1번째 집 뒤에 오니까 항상 다르다. 다른 색도 마찬가지)

```cpp
int n;
cin >> n;
vector<int> costR(n+1);
vector<int> costG(n+1);
vector<int> costB(n+1);
```

1번째 집부터 n번째 집까지 R을 선택한 경우, G를 선택한 경우, B를 선택한 경우에 대해 각각 costR, costG, costB에 저장한다. 단, 이전 집의 색깔이 이번에 선택한 집과 달라야 한다. 

```cpp
int R, G, B;
for(int k = 1; k < n+1; k++) {
    cin >> R >> G >> B;
    
    // costX[k]는 k번째 집에 해당 색을 골랐을 때 최소 비용
    costR[k] = min(costG[k-1], costB[k-1]) + R;
    costG[k] = min(costR[k-1], costB[k-1]) + G;
    costB[k] = min(costG[k-1], costR[k-1]) + B;
}
```

3가지 경우 중에서 가장 작은 값을 출력한다.

```cpp
cout << min(min(costR[n], costG[n]), costB[n]);
```

---

## 코멘트

내가 짠 코드가 다른사람들이 짠 코드보다 훨씬 깔끔한 것 같아. 진짜로... ㅋㅋㅋ

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> costR(n+1);
    vector<int> costG(n+1);
    vector<int> costB(n+1);
    
    int R, G, B;
    for(int k = 1; k < n+1; k++) {
        cin >> R >> G >> B;
        
        // costX[k]는 k번째 집에 해당 색을 골랐을 때 최소 비용
        costR[k] = min(costG[k-1], costB[k-1]) + R;
        costG[k] = min(costR[k-1], costB[k-1]) + G;
        costB[k] = min(costG[k-1], costR[k-1]) + B;
    }
    
    cout << min(min(costR[n], costG[n]), costB[n]);

    return 0;
}
```