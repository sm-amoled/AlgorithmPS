# 문제집

문제 번호: 1766
알고리즘 분류: 우선순위 큐, 위상 정렬
푼 날짜: 2021년 5월 1일 오후 5:38

## 문제링크

[https://www.acmicpc.net/problem/1766](https://www.acmicpc.net/problem/1766)

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 문제

민오는 1번부터 N번까지 총 N개의 문제로 되어 있는 문제집을 풀려고 한다. 문제는 난이도 순서로 출제되어 있다. 즉 1번 문제가 가장 쉬운 문제이고 N번 문제가 가장 어려운 문제가 된다.

어떤 문제부터 풀까 고민하면서 문제를 훑어보던 민오는, 몇몇 문제들 사이에는 '먼저 푸는 것이 좋은 문제'가 있다는 것을 알게 되었다. 예를 들어 1번 문제를 풀고 나면 4번 문제가 쉽게 풀린다거나 하는 식이다. 민오는 다음의 세 가지 조건에 따라 문제를 풀 순서를 정하기로 하였다.

1. N개의 문제는 모두 풀어야 한다.
2. 먼저 푸는 것이 좋은 문제가 있는 문제는, 먼저 푸는 것이 좋은 문제를 반드시 먼저 풀어야 한다.
3. 가능하면 쉬운 문제부터 풀어야 한다.

예를 들어서 네 개의 문제가 있다고 하자. 4번 문제는 2번 문제보다 먼저 푸는 것이 좋고, 3번 문제는 1번 문제보다 먼저 푸는 것이 좋다고 하자. 만일 4-3-2-1의 순서로 문제를 풀게 되면 조건 1과 조건 2를 만족한다. 하지만 조건 3을 만족하지 않는다. 4보다 3을 충분히 먼저 풀 수 있기 때문이다. 따라서 조건 3을 만족하는 문제를 풀 순서는 3-1-4-2가 된다.

문제의 개수와 먼저 푸는 것이 좋은 문제에 대한 정보가 주어졌을 때, 주어진 조건을 만족하면서 민오가 풀 문제의 순서를 결정해 주는 프로그램을 작성하시오.

## 입력

첫째 줄에 문제의 수 N(1 ≤ N ≤ 32,000)과 먼저 푸는 것이 좋은 문제에 대한 정보의 개수 M(1 ≤ M ≤ 100,000)이 주어진다. 둘째 줄부터 M개의 줄에 걸쳐 두 정수의 순서쌍 A,B가 빈칸을 사이에 두고 주어진다. 이는 A번 문제는 B번 문제보다 먼저 푸는 것이 좋다는 의미이다.

항상 문제를 모두 풀 수 있는 경우만 입력으로 주어진다.

## 출력

첫째 줄에 문제 번호를 나타내는 1 이상 N 이하의 정수들을 민오가 풀어야 하는 순서대로 빈칸을 사이에 두고 출력한다.

## 해설

할 일의 순서를 만드는 문제이므로, **위상 정렬** 문제와 같다. 일반적인 위상 정렬과 다른 점은 **번호가 낮은 문제를 먼저 해결**해야한다는 점이다. 이는 내부적으로 값을 내림차순으로 정렬하는 **우선순위 큐** (priority_queue) 를 이용하면 쉽게 해결할 수 있다. 

## 풀이

일반적인 위상 정렬 알고리즘을 이용하듯이, `indegree`, `nextQ` 벡터를 N+1의 크기만큼 선언해주었다. `indegree` 벡터에는 각 문제를 풀기 위해 먼저 풀어야 하는 남은 문제의 수가 저장되고, `nextQ`에는 각 문제를 선행문제로 삼는 문제 번호가 저장된다. 값을 받아올 때, 해당 양식에 맞게 `indegree` 값과 `nextQ` 에 데이터를 넣어준다.

```cpp
vector<int> indegree(N+1);
vector<vector<int>> nextQ(N+1, vector<int>(0));

for(int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    indegree[to]++;
    nextQ[from].push_back(to);
}

```

문제풀이 순서를 정하기 위해 우선순위 큐 `sequence`를 선언해주고, 현재 `indegree` 값이 0인 문제 번호를 넣어준다. 여기에서 우선순위 큐는 기본적으로 값을 내림차순으로 정렬해주기 때문에, `-1`을 곱하여 음수로 입력을 넣어준다. 원래 값이 작을수록 앞으로 자리잡기 때문에, 사용할 때 다시 `-1`을 곱해주면 오름차순으로 정렬된 효과를 누릴 수 있다.

이제 일반적인 위상 정렬 문제를 풀듯이 `sequence`가 빌 때 까지 아래 과정을 반복하면 된다.

1. `top()` 값을 가져오고 출력한 뒤, `pop()`한다. (← 값이 음수로 저장되어 있으므로, `-1`을 곱해야 한다)
2. 해당 문제를 선행문제로 삼는 문제들의 `indegree` 값에서 1을 뺀다. 만약 그 문제의 `indegree` 값이 0이 되었다면 `sequence`에 `push()`해준다. 

```cpp
priority_queue<int> sequence;
for(int i = 1; i <= N; i++) {
    if(indegree[i] == 0)
        sequence.push(-i);
}

while(!sequence.empty()) {
    int node = -sequence.top();
		cout << node << ' ';
    sequence.pop();
    
    for(auto x : nextQ[node]) {
        indegree[x]--;
        if(indegree[x] == 0) {
            sequence.push(-x);
        }
    }
}
```

## 코멘트

---

priority_queue를 사용하면 쉽게 해결되겠다는 생각을 못했다. 생각보다 유용한 자료구조인 것 같네.

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <queue>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

int main() {
    FAST;

    int N, M;
    cin >> N >> M;

    vector<int> indegree(N+1);
    vector<vector<int>> nextQ(N+1, vector<int>(0));

    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        indegree[to]++;
        nextQ[from].push_back(to);
    }

    priority_queue<int> sequence;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0)
            sequence.push(-i);
    }

    while(!sequence.empty()) {
        int node = -sequence.top();
        sequence.pop();

        cout << node << ' ';
        for(auto x : nextQ[node]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                sequence.push(-x);
            }
        }
    }

    return 0;
}
```