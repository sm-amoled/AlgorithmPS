# 사냥꾼

문제 번호: 8983
알고리즘 분류: 이분 탐색, 정렬
푼 날짜: 2021년 2월 4일 오후 10:46

## 문제링크

[https://www.acmicpc.net/problem/8983](https://www.acmicpc.net/problem/8983)

## 문제

KOI 사냥터에는 N 마리의 동물들이 각각 특정한 위치에 살고 있다. 사냥터에 온 사냥꾼은 일직선 상에 위치한 M 개의 사대(총을 쏘는 장소)에서만 사격이 가능하다. 편의상, 일직선을 x-축이라 가정하고, 사대의 위치 x1, x2, ..., xM은 x-좌표 값이라고 하자. 각 동물이 사는 위치는 (a1, b1), (a2, b2), ..., (aN, bN)과 같이 x,y-좌표 값으로 표시하자. 동물의 위치를 나타내는 모든 좌표 값은 양의 정수이다.

사냥꾼이 가지고 있는 총의 사정거리가 L이라고 하면, 사냥꾼은 한 사대에서 거리가 L 보다 작거나 같은 위치의 동물들을 잡을 수 있다고 한다. 단, 사대의 위치 xi와 동물의 위치 (aj, bj) 간의 거리는 |xi-aj| + bj로 계산한다.

예를 들어, 아래의 그림과 같은 사냥터를 생각해 보자. (사대는 작은 사각형으로, 동물의 위치는 작은 원으로 표시되어 있다.) 사정거리 L이 4라고 하면, 점선으로 표시된 영역은 왼쪽에서 세 번째 사대에서 사냥이 가능한 영역이다.

![https://www.acmicpc.net/upload/images/hunter.png](https://www.acmicpc.net/upload/images/hunter.png)

사대의 위치와 동물들의 위치가 주어졌을 때, 잡을 수 있는 동물의 수를 출력하는 프로그램을 작성하시오.

## 입력

입력의 첫 줄에는 사대의 수 M (1 ≤ M ≤ 100,000), 동물의 수 N (1 ≤ N ≤ 100,000), 사정거리 L (1 ≤ L ≤ 1,000,000,000)이 빈칸을 사이에 두고 주어진다. 두 번째 줄에는 사대의 위치를 나타내는 M개의 x-좌표 값이 빈칸을 사이에 두고 양의 정수로 주어진다. 이후 N개의 각 줄에는 각 동물의 사는 위치를 나타내는 좌표 값이 x-좌표 값, y-좌표 값의 순서로 빈칸을 사이에 두고 양의 정수로 주어진다. 사대의 위치가 겹치는 경우는 없으며, 동물들의 위치가 겹치는 경우도 없다. 모든 좌표 값은 1,000,000,000보다 작거나 같은 양의 정수이다.

## 출력

출력은 단 한 줄이며, 잡을 수 있는 동물의 수를 음수가 아닌 정수로 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

각 동물의 위치에서 L범위안에 도달할 수 있는 사수가 있는지 없는지를 파악하여, 해당되는 동물의 수를 헤아리면 된다. 동물의 좌표와 L 값에 따라 사수 위치의 범위를 구할 수 있고, 범위 안에 사수가 있는지는 **binary search**를 이용해 찾는다. 여기에서는 **lower bound**를 활용하면 쉽게 값을 찾을 수 있다. 

## 풀이

동물의 위치가 주어졌을 때, 동물에서 L 거리에 있는 사수 좌표(x축 위)의 범위는 거리를 구하는 식인 `|x-a|+b` 식을 를 이용해 쉽게 구할 수 있다. 우리가 찾고자 하는 범위의 최대거리인 L을 이용하면 `x <= a ± (L-b)` 이다. 이를 절댓값을 풀어 쓰면 `a+b-L ≤ x ≤ a-b+L`이 된다. 이 범위를 만족하는 사수 좌표 m을 찾기 위해, m 값들을 정렬하고 lower bound 알고리즘으로 m의 값들에서 `a+b-L`보다 크거나 같은 첫 좌표를 찾는다. 이 값이 `a-b+L`보다 작으면 범위 안에 사수가 하나 이상 있다는 뜻이므로, `killCount`값을 올릴 수 있다. 

```cpp
for(int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    
// y가 L보다 큰 경우에는 사수가 동물을 잡을 수 없다. 
    if(y > L) continue;
    
// y가 L보다 작거나 같은 경우
    int lower = x+y-L, upper = x-y+L;
    
    int left = 0, right = m.size()-1;
    while(left <= right) {
        int mid = (left+right) / 2;
            
		// 해당되는 값이 있으면 killCount를 올리고 종료
        if(lower <= m[mid] && m[mid] <= upper) {
            killCount++;
            break;
        } else if (m[mid] < lower) {
            left = mid + 1;
        } else if (upper < m[mid]) {
            right = mid - 1;
        }
    }
}

cout << killCount;
```

---

## 코멘트

이분 정렬의 핵심은 뭘 비교의 기준으로 두는가인데, 이걸 찾는게 아직은 나한테 쉽지 않은 것 같다. 흐으음...

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int M, N, L;
    int killCount = 0;
    
    cin >> M >> N >> L;
    
    vector<int> m(M);
    
    for(int i = 0; i < M; i++) {
        cin >> m[i];    
    }
    
    sort(m.begin(), m.end());
    
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        
        if(y > L) continue;
        
        int lower = x+y-L, upper = x-y+L;
        
        int left = 0, right = m.size()-1;
        while(left <= right) {
            int mid = (left+right) / 2;
                
            if(lower <= m[mid] && m[mid] <= upper) {
                killCount++;
                break;
            } else if (m[mid] < lower) {
                left = mid + 1;
            } else if (upper < m[mid]) {
                right = mid - 1;
            }
        }
    }
    
    cout << killCount;
    return 0;
}
```