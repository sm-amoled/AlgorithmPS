# 외계인의 기타 연주

문제 번호: 2841
알고리즘 분류: 스택
푼 날짜: 2021년 2월 16일 오후 9:08

## 문제링크

[https://www.acmicpc.net/problem/2841](https://www.acmicpc.net/problem/2841)

## 문제

상근이의 상상의 친구 외계인은 손가락을 수십억개 가지고 있다. 어느 날 외계인은 기타가 치고 싶었고, 인터넷에서 간단한 멜로디를 검색했다. 이제 이 기타를 치려고 한다.

보통 기타는 1번 줄부터 6번 줄까지 총 6개의 줄이 있고, 각 줄은 P개의 프렛으로 나누어져 있다. 프렛의 번호도 1번부터 P번까지 나누어져 있다.

멜로디는 음의 연속이고, 각 음은 줄에서 해당하는 프렛을 누르고 줄을 튕기면 연주할 수 있다. 예를 들면, 4번 줄의 8번 프렛을 누르고 튕길 수 있다. 만약, 어떤 줄의 프렛을 여러 개 누르고 있다면, 가장 높은 프렛의 음이 발생한다.

예를 들어, 3번 줄의 5번 프렛을 이미 누르고 있다고 하자. 이때, 7번 프렛을 누른 음을 연주하려면, 5번 프렛을 누르는 손을 떼지 않고 다른 손가락으로 7번 프렛을 누르고 줄을 튕기면 된다. 여기서 2번 프렛의 음을 연주하려고 한다면, 5번과 7번을 누르던 손가락을 뗀 다음에 2번 프렛을 누르고 연주해야 한다.

이렇게 손가락으로 프렛을 한 번 누르거나 떼는 것을 손가락을 한 번 움직였다고 한다. 어떤 멜로디가 주어졌을 때, 손가락의 가장 적게 움직이는 회수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 멜로디에 포함되어 있는 음의 수 N과 한 줄에 있는 프렛의 수 P가 주어진다. (N ≤ 500,000, 2 ≤ P ≤ 300,000)

다음 N개 줄에는 멜로디의 한 음을 나타내는 두 정수가 주어진다. 첫 번째 정수는 줄의 번호이고 두 번째 정수는 그 줄에서 눌러야 하는 프렛의 번호이다. 입력으로 주어진 음의 순서대로 기타를 연주해야 한다.

## 출력

첫째 줄에 멜로디를 연주하는데 필요한 최소 손가락 움직임을 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

각 줄의 입력받은 프렛을 오름차순으로 벡터에 쌓아올린다. 만약에 입력하고자 하는 프렛의 값이 벡터에 있는 원소보다 작다면, 벡터에서 원소를 pop하여 오름차순을 유지한다.

## 풀이

N개의 줄에 P개의 프랫이 있을 수 있으므로, 이를 나타내기 위해 2차원 벡터를 사용하였다. 

줄의 번호와 프렛 번호를 받아오는 입력을 N번 처리해야 한다. 만약 줄의 번호를 line이라 한다면, index 번호가 0부터 시작하므로 line-1으로 접근해주어야 한다. 해당 줄에서 pret은 누르고 있으면 벡터에 값이 담겨있고, 떼고 있으면 벡터에서 값을 pop하는 방식으로 처리하였다. 누르기/떼기를 수행하면 각 count에 1을 더해주어 손가락 움직임을 헤아린다.

```cpp
vector<vector<int>>melody (N,vector<int>(0));
int count = 0;
for(int i = 0; i < N; i++) {
    int line, pret;
    cin >> line >> pret;
    
    while(!melody[line-1].empty()) {
        if(melody[line-1].back() > pret) {
            melody[line-1].pop_back();
            count++;
        } else {
            break;
        }
    }

    melody[line-1].push_back(pret);
    count++;
}
```

여기에서 이제 연주하고자 하는 음이 현재 누르고 있는 프렛과 동일하다면 손가락을 움직이지 않아도 되므로, 같은 경우에는 count를 더하지 않는 분기문을 추가한다.

```cpp
if(!melody[line-1].empty()) {
    if(melody[line-1].back() != pret) {
        melody[line-1].push_back(pret);
        count++;
    }
} else {
    melody[line-1].push_back(pret);
    count++;
}
```

그 다음 count를 출력하면, 원하는 결과를 얻을 수 있다. 

---

## 코멘트

나도 기타 쳐보고싶다. 베이스가 좋아 나는 ㅎㅎ

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, P;
    cin >> N >> P;
    vector<vector<int>>melody (N,vector<int>(0));
    int count = 0;
    for(int i = 0; i < N; i++) {
        int line, pret;
        cin >> line >> pret;
        
        while(!melody[line-1].empty()) {
            if(melody[line-1].back() > pret) {
                melody[line-1].pop_back();
                count++;
            } else {
                break;
            }
        }
        
        if(!melody[line-1].empty()) {
            if(melody[line-1].back() != pret) {
                melody[line-1].push_back(pret);
                count++;
            }
        } else {
            melody[line-1].push_back(pret);
            count++;
        }
    }
    
    cout << count;
    return 0;
}
```