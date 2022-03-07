# 여행 가자

문제 번호: 1976
알고리즘 분류: 유니온-파인드
푼 날짜: 2021년 4월 28일 오후 4:39

## 문제링크

[https://www.acmicpc.net/problem/1976](https://www.acmicpc.net/problem/1976)

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 문제

동혁이는 친구들과 함께 여행을 가려고 한다. 한국에는 도시가 N개 있고 임의의 두 도시 사이에 길이 있을 수도, 없을 수도 있다. 동혁이의 여행 일정이 주어졌을 때, 이 여행 경로가 가능한 것인지 알아보자. 물론 중간에 다른 도시를 경유해서 여행을 할 수도 있다. 예를 들어 도시가 5개 있고, A-B, B-C, A-D, B-D, E-A의 길이 있고, 동혁이의 여행 계획이 E C B C D 라면 E-A-B-C-B-C-B-D라는 여행경로를 통해 목적을 달성할 수 있다.

도시들의 개수와 도시들 간의 연결 여부가 주어져 있고, 동혁이의 여행 계획에 속한 도시들이 순서대로 주어졌을 때 가능한지 여부를 판별하는 프로그램을 작성하시오. 같은 도시를 여러 번 방문하는 것도 가능하다.

## 입력

첫 줄에 도시의 수 N이 주어진다. N은 200이하이다. 둘째 줄에 여행 계획에 속한 도시들의 수 M이 주어진다. M은 1000이하이다. 다음 N개의 줄에는 N개의 정수가 주어진다. i번째 줄의 j번째 수는 i번 도시와 j번 도시의 연결 정보를 의미한다. 1이면 연결된 것이고 0이면 연결이 되지 않은 것이다. A와 B가 연결되었으면 B와 A도 연결되어 있다. 마지막 줄에는 여행 계획이 주어진다. 도시의 번호는 1부터 N까지 차례대로 매겨져 있다.

## 출력

첫 줄에 가능하면 YES 불가능하면 NO를 출력한다.

## 해설

처음에는 분리되어있는 도시들을 지도에 따라 연결하여 root 노드를 일치시켜준다. 

이후 여행 계획이 주어지면 모든 노드(도시)가 연결된 상태인지를 파악하는 것이 문제이므로, **첫번째 노드의 root 노드와 뒤에 주어지는 노드들의 root 노드가 같은지를 확인**하여 적절한 결과를 출력한다. 이때 유니온-파인드 구조의 `find` 함수를 활용해준다.

## 풀이

문제 해결을 위해 유니온-파인드 알고리즘을 사용해주었다. 사실 이 문제는 유니온-파인드 알고리즘을 연습하기 위한 문제라서 이걸 쓰는게 제일 간편한 방법이라고 생각된다.

주어진 값 만큼의 도시를 set하여 구조를 만들어주고, 입력받은 연결 형태를 따라 그래프를 `unite`해주어 도시의 연결 상태를 구현해주면 된다. 주어진 NxN 형태의 입력에 대해서 왼쪽 위에서 시작하는 대각선에 대해 선대칭 구조이므로 (양방향으로 이동이 가능하니까) 이 점을 이용해 입력의 절반만 처리해주면 된다.

```cpp
union_find UF = union_find(n);

for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
        int connect;
        cin >> connect;

				// i>j <- 대각선 아래만 처리한다. i==j 인 경우에는 어차피 0이므로 생략했다.
        if(i > j && connect) {
            UF.unite(i, j);
        }
    }
}
```

첫번째로 방문할 도시의 root 노드를 기준으로 잡고, 뒤에 나오는 다른 도시들을 입력받으면 현재 입력받은 도시의 root 노드와 첫 번째 도시의 root 노드가 같은지를 비교한다. (**root 노드가 같다 = 같은 연결된 그래프 상에 있다**) 만약 다른 경우 (연결되어있지 않은 경우) `isSameSet` flag를 false 처리하고, 반복문을 탈출한다. 

```cpp
bool isSameSet = true;
int root;

// 첫번째 방문할 도시 <- 비교 기준으로 삼음
cin >> root;
root = UF.find(root);

for(int i = 1; i < m; i++) {
    int node;
    cin >> node;

    if(root != UF.find(node)) {
        isSameSet = false;
        break;
    }   
}

```

`isSameSet` flag가 true라면 모든 도시가 연결되어있는 상태이기에 YES를 출력해주고, 그렇지 않다면 최소 하나의 도시가 연결되어있지 않은 상태이기에 NO를 출력해준다.

```cpp
if(isSameSet) cout << "YES";
else cout << "NO";
```

---

## 코멘트

유니온 파인드는 이제 기본적으로 어떻게 동작하는지 알 것 같다. 물론 꼬이면 어렵겠지만... ㅋㅋㅋㅋ 그래프 문제에서는 node의 번호가 0부터 시작하는지 1부터 시작하는지를 잘 봐야 헛발 짚고 오래 고생하지 않을 수 있는 것 같다. 잘 보자!

---

## 코드

```cpp
#include <iostream>
#include <vector>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

const int SIZE = 202;

struct union_find {
    int parent[SIZE];
    int size[SIZE] = {0,};

    union_find(int n) {
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(node == parent[node]) return node;
        
        int temp = find(parent[node]);
        parent[node] = temp;
        return temp;
    }

    void unite(int A, int B) {
        A = find(A);
        B = find(B);

        if(size[A] < size[B]) swap(A, B);

        parent[B] = A;
        size[A] += size[B];
    }
};

int main() {
    FAST;
    
    int n, m;
    cin >> n >> m;

    union_find UF = union_find(n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int connect;
            cin >> connect;

            if(i > j && connect) {
                UF.unite(i, j);
            }
        }
    }

    bool isSameSet = true;
    int root;

// 첫번째 방문할 도시 <- 비교 기준으로 삼음
    cin >> root;
    root = UF.find(root);

    for(int i = 1; i < m; i++) {
        int node;
        cin >> node;

        if(root != UF.find(node)) {
            isSameSet = false;
            break;
        }   
    }

    if(isSameSet) cout << "YES";
    else cout << "NO";

    return 0;
}
```