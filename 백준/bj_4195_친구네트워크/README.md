# 친구 네트워크

문제 번호: 4195
알고리즘 분류: 맵, 유니온-파인드
푼 날짜: 2021년 4월 28일 오후 4:53

## 문제링크

[https://www.acmicpc.net/problem/4195](https://www.acmicpc.net/problem/4195)

## 조건

- 시간 제한 : 3s
- 메모리 제한 : 256MB

---

## 문제

민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.

어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.

## 입력

첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스의 첫째 줄에는 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다. 다음 F개의 줄에는 친구 관계가 생긴 순서대로 주어진다. 친구 관계는 두 사용자의 아이디로 이루어져 있으며, 알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 문자열이다.

## 출력

친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

## 해설

이 문제의 헤맬만한 부분은 입력이 정수형의 node 번호가 아니라 문자열로 주어졌다는 점이다. 주어지는 문자열들을 배열이나 벡터로 관리하면서 그에 따른 index 번호를 node 번호로 사용할 수도 있었지만, 나는 `unordered_map` 자료구조를 사용해주었다. 기본적인 틀 자체는 유니온-파인드 알고리즘을 사용하여 문제를 해결했다.

두 사람의 이름이 입력으로 들어와 서로 친구가 된 뒤, 둘의 친구 네트워크에 몇 명이 있는지를 출력하면 되므로, 유니온-파인드의 `unite` 함수를 통해 이를 구현하였다. 두 사람이 같은 네트워크에 포함되어있지 않은 상태였다면 `unite`를 통해 두 사람을 연결하고, root node 의 `size`를 출력하여 현재 네트워크 상의 크기를 출력해준다. 만약 두 사람이 이미 친구 네트워크에 포함되어 있는 경우에는 따로 연결 없이 root node 의 `size`를 출력하여 크기를 출력한다.

사람 이름을 구분하기 위해 map 구조의 key로 이름을 사용해준다. `find` 함수를 만들 때, 만약 map에 입력받은 이름을 key로 사용하는 원소가 없는 경우에는 해당 이름을 key로 사용하는 node를 새로 `insert` 해주고, 있는 경우에는 해당 노드의 root 노드를 반환해준다. 

## 풀이

`unordered_map` 구조는 key를 내가 지정한 data type으로 사용한다. 여기에서 입력받은 사람 이름을 node의 이름으로 사용하고 있으므로, node와 이름을 연결해주기 위해 `unordered_map<string, pair<string, int>>` 의 형태로 map을 선언해주었다. 이때, `pair<string, int>`는 <parent, size> 를 의미한다.

해당 노드의 root 노드를 찾는 `find` 함수는 이미 입력이 되었던 이름이라면 (`map.find(name) ≠ map.end()`) 해당 노드의 부모 노드(`parent`)를 출력해준다. 기존의 코드였다면 root 노드가 될 때 까지 반복문을 돌렸겠지만, 거리 단축 코드를 사용해 `find` 함수를 거치면 root 노드를 가리키도록 만들었다. 입력이 처음 되는 이름이라면 map 에 `parent`는 자기 자신을, `size` 는 1이 되도록 set 하여 `insert`해준다. 

`unite` 함수가 실행되면, 두 노드의 root 노드를 비교하여 같은 경우에는 root 노드의 `size`를 출력하고, 다른 경우에는 두 집합을 연결한 다음 합쳐진 집합의 `size`를 출력해준다.

```cpp
struct union_find {
    unordered_map<string, pair<string, int>> map;

    string find(string name) {
        if(map.find(name) != map.end()) {
            if(name == map[name].first) return name;
            
            string temp = find(map[name].first);
            map[name].first = temp;
            return temp;
        } else {
            map.insert(make_pair(name, make_pair(name, 1)));
            return name;
        }
    }

    void unite(string A, string B) {
        A = find(A);
        B = find(B);

        if(A==B) {
            cout << max(map[A].second, map[B].second) << '\n';
            return;
        }

        if(map[A].second < map[B].second) swap(A, B);

        map[B].first = A;
        map[A].second += map[B].second;
        
        cout << map[A].second <<'\n';
    }
};
```

T 번의 test_case에 대해 F번의 두 이름이 들어오면 `unite` 함수를 실행해주면 원하는 결과를 얻을 수 있다.

```cpp
int T;
cin >> T;

while(T--) {
    
    int F;
    cin >> F;

    union_find UF;

    while(F--) {
        string firstName, secondName;
        cin >> firstName >> secondName;

        UF.unite(firstName, secondName);
    }
}
```

---

## 코멘트

map 자료구조를 처음 써봐서 헷갈렸다. 그래도 내부적으로 key를 연결해서 알아서 저렇게 맞춰준다는건 좋은 일이네. 사실 이 문제를 해결하는 데에 있어서 시간의 90%를 잡아먹은 부분은 이 부분이긴 하지만 ㅋㅋㅋ 두 친구가 이미 같은 네트워크 상에 있는 경우에 대해서는 아무런 조치를 취해주지 않았어서 계속 틀렸다고 나왔었다. 

```cpp
if(A==B) {
    cout << max(map[A].second, map[B].second) << '\n';
    return;
}
```

---

## 코드

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

struct union_find {
    unordered_map<string, pair<string, int>> map;

    string find(string name) {
        if(map.find(name) != map.end()) {
            if(name == map[name].first) return name;
            
            string temp = find(map[name].first);
            map[name].first = temp;
            return temp;
        } else {
            map.insert(make_pair(name, make_pair(name, 1)));
            return name;
        }
    }

    void unite(string A, string B) {
        A = find(A);
        B = find(B);

        if(A==B) {
            cout << max(map[A].second, map[B].second) << '\n';
            return;
        }

        if(map[A].second < map[B].second) swap(A, B);

        map[B].first = A;
        map[A].second += map[B].second;
        
        cout << map[A].second <<'\n';
    }
};

int main() {
    FAST;
    
    int T;
    cin >> T;

    while(T--) {
        
        int F;
        cin >> F;

        union_find UF;

        while(F--) {
            string firstName, secondName;
            cin >> firstName >> secondName;

            UF.unite(firstName, secondName);
        }
    }

    return 0;
}
```