# 최소 스패닝 트리

문제 번호: 1197
알고리즘 분류: 최소 스패닝 트리
푼 날짜: 2021년 5월 3일 오후 10:36

## 문제링크

[https://www.acmicpc.net/problem/1197](https://www.acmicpc.net/problem/1197)

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 문제

그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

## 입력

첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

## 출력

첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.

## 해설

주어진 정보에 대한 최소 스패닝 트리의 가중치를 구하는 문제이다. 나는 **크루스칼 알고리즘**을 통해 문제를 해결하였다. 또는 프림 알고리즘 등으로 문제를 해결해도 된다.

주어진 간선을 가중치에 대해 오름차순으로 정렬하고, 가중치가 가장 낮은 간선부터 선택하여 그래프를 구성해나간다. 간선이 추가되었을 때 아직 연결되지 않은 두 그래프가 연결될 수 있다면 선택하고, 이미 연결되어있는 그래프의 두 노드를 연결하는 간선이라면 선택하지 않는다. 선택한 간선의 총 가중치의 합을 출력해준다.

## 풀이

문제 해결을 위해 두 그래프가 현재 연결된 상태인지 파악하기 위해서 유니온-파인드 알고리즘을 이용해주었다. 

간선을 가중치에 대해 오름차순으로 정렬하기 위해 `priority_queue`를 이용하여 코드를 작성했다. 큐의 원소로 `pair<int, pair<int, int>>` 자료형을 사용하며, pair 의 첫번째 값을 가중치, 두번째 값의 pair 에는 해당 간선이 연결하는 두 노드의 번호를 담고있다. 입력받은 값을 그대로 `edges` 큐에 넣으면 자동으로 가중치에 대해 내림차순으로 정렬해주므로, 가중치에 `-`를 붙여서 작은 가중치가 제일 앞으로 오게 만들어주었다.

```cpp
int V, E;
cin >> V >> E;

int selectedEdges = 0;
int result = 0;

Union_Find UF = Union_Find(V);
priority_queue<pair<int, pair<int, int>>> edges;

for(int i = 0; i < E; i++) {
    int A, B, W;
    cin >> A >> B >> W;
    edges.push(make_pair(-W, make_pair(A, B)));
}
```

간선이 `V-1`개일 때 최소한의 간선 수로 스패닝 트리를 만들 수 있으므로, `V-1`개의 간선을 찾았을 때 반복문을 종료하는 코드를 작성해주었다. 반복문에서는 `edges`에 들어있는 간선을 차례대로 `pop`하면서 해당 간선을 선택하면 분리된 두 그래프가 연결되는지를 확인한다. 만약 그렇다면 `result`에 가중치를 더하고, `selectedEdges`에 +1을 하여 간선을 찾았다고 표시하고, 두 노드를 연결해준다. 

반복문이 종료되었을때 (`V-1`개의 간선을 다 찾았을 때) 가중치의 총 합인 `result`를 출력하면 원하는 결과를 얻을 수 있다.

```cpp
while(selectedEdges != V-1) {
    int A = edges.top().second.first;
    int B = edges.top().second.second;
    int W = edges.top().first;
    edges.pop();

    if(UF.find(A) != UF.find(B)) {
        result += -W;
        selectedEdges++;
        UF.unite(A, B);
    }
}

cout << result << '\n';
```

---

## 코멘트

문제 이름부터 최소 스패닝 트리..!!!

---

## 코드

```cpp
#include <iostream>
#include <queue>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

struct Union_Find {
    int parent[10001];
    int size[10001];

    Union_Find(int n) {
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        int temp = node;
        while(parent[node] != node) {
            node = parent[node];
        }
        parent[temp] = node;
        return node;
    }

    void unite(int A, int B) {
        A = find(A);
        B = find(B);

        if(size[A] > size[B]) {
            swap(A, B);
        }

        parent[A] = B;
        size[B] += size[A];
    }
};

int main() {
    FAST;
    
    int V, E;
    cin >> V >> E;
    
    int selectedEdges = 0;
    int result = 0;

    Union_Find UF = Union_Find(V);
    priority_queue<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < E; i++) {
        int A, B, W;
        cin >> A >> B >> W;
        edges.push(make_pair(-W, make_pair(A, B)));
    }

    while(selectedEdges != V-1) {
        int A = edges.top().second.first;
        int B = edges.top().second.second;
        int W = edges.top().first;
        edges.pop();

        if(UF.find(A) != UF.find(B)) {
            result += -W;
            selectedEdges++;
            UF.unite(A, B);
        }
    }

    cout << result << '\n';

    return 0;
}
```