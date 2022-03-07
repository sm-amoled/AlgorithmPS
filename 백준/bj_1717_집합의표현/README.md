# 집합의 표현

문제 번호: 1717
알고리즘 분류: 유니온-파인드
푼 날짜: 2021년 4월 26일 오후 9:12

## 문제링크

[https://www.acmicpc.net/problem/1717](https://www.acmicpc.net/problem/1717)

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 문제

초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다. 여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.

집합을 표현하는 프로그램을 작성하시오.

## 입력

첫째 줄에 n(1 ≤ n ≤ 1,000,000), m(1 ≤ m ≤ 100,000)이 주어진다. m은 입력으로 주어지는 연산의 개수이다. 다음 m개의 줄에는 각각의 연산이 주어진다. 합집합은 0 a b의 형태로 입력이 주어진다. 이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다. 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다. 이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다. a와 b는 n 이하의 자연수 또는 0이며 같을 수도 있다.

## 출력

1로 시작하는 입력에 대해서 한 줄에 하나씩 YES/NO로 결과를 출력한다. (yes/no 를 출력해도 된다)

## 해설

유니온-파인드 알고리즘을 이용하면 쉽게 해결할 수 있는 문제. 애초에 유니온 파인드를 연습하기 위해 출제된 문제이다!

문제에서 주어진 0 연산 (합집합 연산) 은 유니온-파인드 알고리즘에서 `unite` 연산에 해당하고, 1 연산(두 원소가 같은 집합에 포함되었는지 확인하는 연산)은 `find` 연산으로 구한 두 최상위 부모 노드를 비교하는 연산에 해당한다.

## 풀이

union_find 구조를 작성해주어 쉽게 해결이 가능하다. 

합집한 연산(`unite`)은 두 원소가 포함된 그룹을 합치는 함수를 이용해 해결할 수 있다. `find` 연산으로 구한 두 최상위 부모 노드가 같은지를 비교하는 함수인 `isSameSet` 함수를 새로 만들어 1 연산에서 사용해주었다. 

이 문제를 단순한 `find` 함수로 해결하기에는 시간이 부족하여, 모든 노드를 최상위 부모 노드로 연결하는 경로 단축 `find` 함수를 작성해주어 시간을 절약하였다.

```cpp
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

## 코멘트

---

값의 범위를 잘 보자! node 의 개수는 n개가 아니라, node의 번호가 0~n 까지였다!

---

## 코드

```cpp
#include <iostream>

const int SIZE = 1000001;
using namespace std;

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    union_find UF = union_find(n);

    while(m--) {
        int type, a, b;
        cin >> type >> a >> b;

        if(!type) UF.unite(a, b);
        else {
            cout << ((UF.isSameSet(a, b))? "YES\n":"NO\n");
        }
    }

    return 0;
}
```