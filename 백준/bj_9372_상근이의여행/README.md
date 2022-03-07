# 상근이의 여행

문제 번호: 9372
알고리즘 분류: 유니온-파인드, 최소 스패닝 트리
푼 날짜: 2021년 5월 3일 오후 10:14

## 문제링크

[https://www.acmicpc.net/problem/9372](https://www.acmicpc.net/problem/9372)

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 문제

상근이는 겨울방학을 맞아 N개국을 여행하면서 자아를 찾기로 마음먹었다.

하지만 상근이는 새로운 비행기를 무서워하기 때문에, 최대한 적은 종류의 비행기를 타고 국가들을 이동하려고 한다.

이번 방학 동안의 비행 스케줄이 주어졌을 때, 상근이가 **가장 적은 종류**의 비행기를 타고 모든 국가들을 여행할 수 있도록 도와주자.

상근이가 한 국가에서 다른 국가로 이동할 때 다른 국가를 거쳐 가도(심지어 이미 방문한 국가라도) 된다.

## 입력

첫 번째 줄에는 테스트 케이스의 수 T(T ≤ 100)가 주어지고,

각 테스트 케이스마다 다음과 같은 정보가 주어진다.

- 첫 번째 줄에는 국가의 수 N(2 ≤ N ≤ 1 000)과 비행기의 종류 M(1 ≤ M ≤ 10 000) 가 주어진다.
- 이후 M개의 줄에 a와 b 쌍들이 입력된다. a와 b를 왕복하는 비행기가 있다는 것을 의미한다. (1 ≤ a, b ≤ n; a ≠ b)
- 주어지는 비행 스케줄은 항상 연결 그래프를 이룬다.

## 출력

테스트 케이스마다 한 줄을 출력한다.

- 상근이가 모든 국가를 여행하기 위해 타야 하는 비행기 종류의 최소 개수를 출력한다.

## 해설

모든 국가를 방문하기 위한 경로를 계산하는 것이 아니라, 비행기의 종류를 최소화하는 것이 문제의 조건이다. 모든 노선의 비행기가 다른 종류이므로, 이 문제의 의미는 **모든 도시를 연결하는 그래프를 만들 때, edge의 개수를 최소한으로 이용**하여 만들라는 것이다. 

## 풀이

그래프가 최소한의 간선으로만 모든 노드를 이으려면 사이클이 존재하지 않아야 하므로 (낭비하는 edge가 없도록 해야하므로)  **유니온-파인드** 알고리즘을 통해 이으려고 하는 두 도시가 이미 연결된 상태인지를 검사하였다. 유니온-파인드 알고리즘을 위한 구조체 `Union_Find`는 아래의 코드를 사용했다.

```cpp
struct Union_Find {
    int parent[1001];
    int size[1001];

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
```

입력받은 국가의 수 N을 이용해 `Union_Find`를 생성해주었다. 비행기 종류의 개수를 의미하는 M은 앞으로 주어질 간선의 수이다. 여기에서 필요한 최소한의 개수의 간선만을 골라서 그래프를 구성하면 된다.  이를 위해 노선에서 출발지와 도착지를 A, B 두 개의 변수에 받아와 현재 서로 같은 그래프에 속해있는지를 검사하였다. 만약 아직 다른 그래프에 속해있다면 (두 도시가 아직 이어진 경로가 없다면) `result`에 1을 더하고(간선의 개수 count) 두 노드를 이어준다. 모든 비행기 종류(간선)에 대해 검사를 마친 뒤 result를 출력하면 원하는 결과를 얻을 수 있다.

```cpp
int N, M;
cin >> N >> M;

int result = 0;

Union_Find UF = Union_Find(N);

for(int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;

    if(UF.find(A) != UF.find(B)) {
        UF.unite(A, B);
        result++;
    }
}

cout << result << '\n';
```

---

## 코멘트

MST 문제를 풀려고 했는데, 유니온 파인드 문제가 등장해버렸네?

---

## 코드

```cpp
#include <iostream>
#include <stack>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

struct Union_Find {
    int parent[1001];
    int size[1001];

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
    
    int T;
    cin >> T;

    while(T--) {
        int N, M;
        cin >> N >> M;
        
        int result = 0;

        Union_Find UF = Union_Find(N);

        for(int i = 0; i < M; i++) {
            int A, B;
            cin >> A >> B;
        
            if(UF.find(A) != UF.find(B)) {
                UF.unite(A, B);
                result++;
            }
        }

        cout << result << '\n';
    }

    return 0;
}
```