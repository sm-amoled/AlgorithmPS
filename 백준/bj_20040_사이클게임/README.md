# 사이클 게임

문제 번호: 20040
알고리즘 분류: 유니온-파인드
푼 날짜: 2021년 4월 29일 오후 8:52

## 문제링크

[https://www.acmicpc.net/problem/20040](https://www.acmicpc.net/problem/20040)

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 512MB

---

## 문제

사이클 게임은 두 명의 플레이어가 차례대로 돌아가며 진행하는 게임으로, 선 플레이어가 홀수 번째 차례를, 후 플레이어가 짝수 번째 차례를 진행한다. 게임 시작 시 0 부터 *n* − 1 까지 고유한 번호가 부여된 평면 상의 점 *n* 개가 주어지며, 이 중 어느 세 점도 일직선 위에 놓이지 않는다. 매 차례 마다 플레이어는 두 점을 선택해서 이를 연결하는 선분을 긋는데, 이전에 그린 선분을 다시 그을 수는 없지만 이미 그린 다른 선분과 교차하는 것은 가능하다. 게임을 진행하다가 처음으로 사이클을 완성하는 순간 게임이 종료된다. 사이클 *C*는 플레이어가 그린 선분들의 부분집합으로, 다음 조건을 만족한다.

> C에 속한 임의의 선분의 한 끝점에서 출발하여 모든 선분을 한 번씩만 지나서 출발점으로 되돌아올 수 있다.

문제는 선분을 여러 개 그리다 보면 사이클이 완성 되었는지의 여부를 판단하기 어려워 이미 사이클이 완성되었음에도 불구하고 게임을 계속 진행하게 될 수 있다는 것이다. 이 문제를 해결하기 위해서 게임의 진행 상황이 주어지면 몇 번째 차례에서 사이클이 완성되었는지, 혹은 아직 게임이 진행 중인지를 판단하는 프로그램을 작성하려 한다.

입력으로 점의 개수 *n*과 *m* 번째 차례까지의 게임 진행 상황이 주어지면 사이클이 완성 되었는지를 판단하고, 완성되었다면 몇 번째 차례에서 처음으로 사이클이 완성된 것인지를 출력하는 프로그램을 작성하시오.

## 입력

입력은 표준입력을 사용한다. 입력의 첫 번째 줄에는 점의 개수를 나타내는 정수 3 ≤ *n* ≤ 500,000 과 진행된 차례의 수를 나타내는 정수 3 ≤ *m* ≤ 1,000,000 이 주어진다. 게임에서 사용하는 *n*개의 점에는 0 부터 *n* − 1 까지 고유한 번호가 부여되어 있으며, 이 중 어느 세 점도 일직선 위에 놓이지 않는다. 이어지는 *m* 개의 입력 줄에는 각각 *i*번째 차례에 해당 플레이어가 선택한 두 점의 번호가 주어진다 (1 ≤ *i* ≤ *m*).

## 출력

출력은 표준출력을 사용한다. 입력으로 주어진 케이스에 대해, *m* 번째 차례까지 게임을 진행한 상황에서 이미 게임이 종료되었다면 사이클이 처음으로 만들어진 차례의 번호를 양의 정수로 출력하고, *m* 번의 차례를 모두 처리한 이후에도 종료되지 않았다면 0을 출력한다.

## 해설

문제를 간단하게 요약하면, 입력 받는 값들을 가지고 노드를 연결하는데, 처음으로 cycle이 만들어진 반복문이 k 번째 반복문이라면, k를 출력하면 된다.

사이클은 다른 두 집합을 이을 때 나타나지 않고 같은 집합에서 아직 연결되지 않은 node 사이를 이을 때 나타난다. 즉, **서로 다른 두 노드의 root 노드가 같을 때 두 노드를 이으면** 해당 노드를 포함하는 그래프는 **사이클을 포함**하게 된다.

## 풀이

유니온-파인드 알고리즘을 이용하면 주어진 노드를 포함하는 그래프의 root node를 쉽게 파악할 수 있고, 이를 통해 해당 edge를 이었을때 cycle이 생기는지를 쉽게 파악할 수 있다.

`union_find` 구조체는 늘 사용하던 기본적인 방식으로 선언해주었다. 

```cpp
const int SIZE = 1000000;

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

    bool isSameSet(int A, int B) {
        return find(A) == find(B);
    }
};
```

main 함수에서는 두 수 n (node 의 수), m (edge의 수)를 입력받는다. 반복문에서는 1 ≤ i++ ≤ m 에 대해서 아래 과정을 수행해준다. 두 수 A, B를 입력받고 A와 B의 root 노드를 비교한다. 만약에 두 root 노드가 다르다면 두 노드가 속한 집합이 다르므로 사이클이 생길 수 없어서 그대로 unite를 수행해준다. 만약 **A와 B의 root 노드가 같다**면 이번에 입력받은 간선을 이으면 **cycle이 발생**하게 되므로 `cycle` 변수에 `true` 를 넣어주고, `min_m` 변수에는 이번이 몇 번째 반복문인지를 저장한다. 

첫 번째 사이클을 찾았으므로 나머지 입력에 대해서는 연산을 수행할 필요가 없으므로 입력이 끝날 때 까지 아무것도 하지 않고 있다가 `min_m` 값을 출력해준다. 만약에 cycle이 발생하지 않았다면 0을 출력해준다.

```cpp
int n, m;
cin >> n >> m;

union_find UF = union_find(n);

int min_m;
bool cycle = false;

for(int i = 1; i <= m; i++) {
    int A, B;
    cin >> A >> B;

    if(UF.find(A) == UF.find(B) && !cycle) {
        cycle = true;
        min_m = i;
    } else if (!cycle) {
		    UF.unite(A, B);
		}
}

cout << ((cycle)? min_m : 0);
```

---

## 코멘트

휴, 이정도는 손코딩으로 쉽게 해결할 수 있는 난이도였다. ㅎㅎ

---

## 코드

```cpp
#include <iostream>
~~#~~define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

const int SIZE = 1000000;

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

    bool isSameSet(int A, int B) {
        return find(A) == find(B);
    }
};

int main() {
    FAST;

    int n, m;
    cin >> n >> m;

    union_find UF = union_find(n);

    int min_m;
    bool cycle = false;

    for(int i = 1; i <= m; i++) {
        int A, B;
        cin >> A >> B;

        if(UF.find(A) == UF.find(B) && !cycle) {
            cycle = true;
            min_m = i;
        }

        UF.unite(A, B);
    }

    cout << ((cycle)? min_m : 0);

    return 0;
}
```