# 덩치

문제 번호: 7568
알고리즘 분류: 브루트 포스
푼 날짜: 2021년 3월 1일 오후 10:41

## 문제링크

[https://www.acmicpc.net/problem/7568](https://www.acmicpc.net/problem/7568)

## 문제

우리는 사람의 덩치를 키와 몸무게, 이 두 개의 값으로 표현하여 그 등수를 매겨보려고 한다. 어떤 사람의 몸무게가 x kg이고 키가 y cm라면 이 사람의 덩치는 (x, y)로 표시된다. 두 사람 A 와 B의 덩치가 각각 (x, y), (p, q)라고 할 때 x > p 그리고 y > q 이라면 우리는 A의 덩치가 B의 덩치보다 "더 크다"고 말한다. 예를 들어 어떤 A, B 두 사람의 덩치가 각각 (56, 177), (45, 165) 라고 한다면 A의 덩치가 B보다 큰 셈이 된다. 그런데 서로 다른 덩치끼리 크기를 정할 수 없는 경우도 있다. 예를 들어 두 사람 C와 D의 덩치가 각각 (45, 181), (55, 173)이라면 몸무게는 D가 C보다 더 무겁고, 키는 C가 더 크므로, "덩치"로만 볼 때 C와 D는 누구도 상대방보다 더 크다고 말할 수 없다.

N명의 집단에서 각 사람의 덩치 등수는 자신보다 더 "큰 덩치"의 사람의 수로 정해진다. 만일 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k+1이 된다. 이렇게 등수를 결정하면 같은 덩치 등수를 가진 사람은 여러 명도 가능하다. 아래는 5명으로 이루어진 집단에서 각 사람의 덩치와 그 등수가 표시된 표이다.

이름 - (몸무게, 키) - 덩치 등수

A - (55, 185) - 2

B - (58, 183) - 2

C - (88, 186) - 1

D - (60, 175) - 2

E - (46, 155) - 5

위 표에서 C보다 더 큰 덩치의 사람이 없으므로 C는 1등이 된다. 그리고 A, B, D 각각의 덩치보다 큰 사람은 C뿐이므로 이들은 모두 2등이 된다. 그리고 E보다 큰 덩치는 A, B, C, D 이렇게 4명이므로 E의 덩치는 5등이 된다. 위 경우에 3등과 4등은 존재하지 않는다. 여러분은 학생 N명의 몸무게와 키가 담긴 입력을 읽어서 각 사람의 덩치 등수를 계산하여 출력해야 한다.

## 입력

첫 줄에는 전체 사람의 수 N이 주어진다. 그리고 이어지는 N개의 줄에는 각 사람의 몸무게와 키를 나타내는 양의 정수 x와 y가 하나의 공백을 두고 각각 나타난다.

## 출력

여러분은 입력에 나열된 사람의 덩치 등수를 구해서 그 순서대로 첫 줄에 출력해야 한다. 단, 각 덩치 등수는 공백문자로 분리되어야 한다.

## 제한

- 2 ≤ N ≤ 50
- 10 ≤ x, y ≤ 200

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

사람들의 정보를 입력받고, 각 사람들끼리 비교하여 더 작은 사람의 등수를 내리면 된다.

## 풀이

사람들의 정보를 한 번에 묶어서 관리하기 위해 struct를 정의해주었다. rank는 초기값을 1로 주고 덩치가 큰 사람을 만날 때마다 등수를 떨어트린다.

```cpp
struct bulk {
    int weight;
    int height;
    int rank = 1;
};
```

두 사람을 비교하는 함수를 새로 만들어주었다. 두 사람을 비교할 때, weight와 height를 모두 비교하여 둘 다 크거나 작을 때 유의미한 등수 조정을 해주면 된다. 여기에서 나올 수 있는 경우가 3가지 (a가 큰 경우 / b가 큰 경우 / 비교 불가) 이므로 반환 자료형을 bool이 아닌 int로 해주었다.

```cpp
int compare(bulk a, bulk b) {
    if(a.weight > b.weight && a.height > b.height) {
        return 1;
    } else if (a.weight < b.weight && a.height < b.height) {
        return 2;
    } else {
        return 0;
    }
}
```

bulk 벡터에 입력을 받아 차례대로 저장해준다.

```cpp
int N;
cin >> N;

bulk input;
vector<bulk> people(N);

for(int i = 0; i < N; i++) {
    cin >> input.weight >> input.height;
    people[i] = input;
}
```

2중 for문을 이용해 모든 사람들을 쌍으로 비교해주면 된다. A와 B를 비교했을 때, A가 크다면 반환값이 1이고 이때 B의 등수가 내려가야 하고, B가 크다면 반환값이 2이며 A의 등수가 내려가야 한다. 이를 switch 문으로 구현해주었다.

모든 사람들을 비교하여 등수값을 설정한 뒤, 사람들의 등수를 차례로 출력하면 원하는 결과를 얻을 수 있다. 

```cpp
for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
        switch(compare(people[i], people[j])) {
            case 1 : 
                people[j].rank++;
                break;
            case 2 :
                people[i].rank++;
                break;
            default :
                break;
        } 
    }
}

for(int i = 0; i < N; i++) {
    cout << people[i].rank << " ";
}
```

---

## 코멘트

처음에는 sort함수를 쓰는건가? 아니면 이분 탐색을 사용하는건가 싶었는데, 결과를 출력할 때는 순서가 정해져있어서 놓고 그냥 모두 비교해버렸다.

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

struct bulk {
    int weight;
    int height;
    int rank = 1;
};

int compare(bulk a, bulk b) {
    if(a.weight > b.weight && a.height > b.height) {
        return 1;
    } else if (a.weight < b.weight && a.height < b.height) {
        return 2;
    } else {
        return 0;
    }
}

int main() {
    int N;
    cin >> N;
    
    bulk input;
    vector<bulk> people(N);
    
    for(int i = 0; i < N; i++) {
        cin >> input.weight >> input.height;
        people[i] = input;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            switch(compare(people[i], people[j])) {
                case 1 : 
                    people[j].rank++;
                    break;
                case 2 :
                    people[i].rank++;
                    break;
                default :
                    break;
            } 
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << people[i].rank << " ";
    }
    
	return 0;
}
```