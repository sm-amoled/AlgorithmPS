# [백준] 7562 - 나이트의 이동

Category: 알고리즘
PublishDate: 2022년 3월 19일 오후 11:43
Tag: BFS, 그래프
Visibility: Public
문제 번호: 7562

## 문제 링크

[https://www.acmicpc.net/problem/7562](https://www.acmicpc.net/problem/7562)

## 문제

체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?

![https://www.acmicpc.net/upload/images/knight.png](https://www.acmicpc.net/upload/images/knight.png)

## 입력

입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

## 출력

각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지 출력한다.

## 조건

- 시간 제한 : 1초
- 메모리 제한 : 256MB

---

## 해설

체스판 위에서 나이트가 몇 번 이동해야 목적지까지 도달할 수 있을지를 계산하는 문제이다. 상하좌우로 움직이는 평범한 방식과 달리, 나이트는 대각선+1 방향으로 이동하므로, 이를 적용하여 문제를 해결하면 된다.

체스판에서 아직 방문하지 못한 칸은 0의 값을 갖고 시작한다. N번째 이동으로 갈 수 있는 칸에는 N이라는 값을 갖는다. 이미 N번째 이동으로 방문했던 칸에 N보다 큰 M번째에 방문한 경우에는 무시한다. (이미 N번째에 방문할 수 있는 칸이므로 굳이 M으로 갱신할 필요 X)

N번째에 방문할 수 있는 칸을 모두 처리한 뒤 N+1번째에 방문할 수 있는 칸을 모두 처리하는 식으로, 각 번째의 이동을 한 번에 처리하는 방식으로 문제를 해결하면 비교적 간단하게 해결가능하다.

## 풀이

필요한 변수와 배열, 큐를 우선 선언하였다. 좌표를 표현하기 위해 구조체 `pos`를 사용하였고, 나이트의 움직임을 표현하기 위한 배열 `moveX`와 `moveY`를 선언하였다. 

```cpp
typedef struct currentPos {
    int x;
    int y;
} pos;

int boardSize;
int board[301][301];
pos start;
pos target;
queue<pos> Q;

int moveX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int moveY[8] = {2, 1, -1, -2, -2, -1, 1, 2};
```

나이트는 대각선으로 이동하거나 2칸씩 이동하면서 범위 검사가 비교적 까다로운 편이라고 판단하여, 나이트가 이동한 경우에 보드 밖으로 나가는지를 검사하는 함수 `sizeCheck`를 따로 정의해주었다. x, y 좌표에 대해 0~boardSize-1 의 범위를 만족한다면 `true`를 반환하고, 아니라면 `false`를 반환한다.

```cpp
bool sizeCheck(int x, int y) {
    if(x >= 0 && x < boardSize && y >= 0 && y < boardSize) return true;
    return false;
}
```

현재 나이트가 도착한 칸이 목적지인지를 검사하는 함수이다. 아래 main 함수에서 if 문으로 덕지덕지 되는 것을 최대한 방지하기 위해 정의해주었다. 단순히 x, y 좌표가 목적지라면 `true`를 반환한다.

```cpp
bool isTarget(int x, int y) {
    if(target.x == x && target.y == y) return true;
    return false;
}
```

빠르게 목적지에 도달할 수 있는 경로를 찾아야하므로, 너비 우선 탐색 - BFS를 사용해 문제를 해결하였다. 만약 시작지점과 목표지점이 동일하다면 우선 함수를 종료한다. 함수의 구조를 간단하게 설명하자면 아래와 같다.

- 1 - (앞서 반복문이 N-1회 진행되었다고 가정하고) 현재 큐가 비어있지 않다면 N번째 나이트의 이동을 준비한다. (`stage + 1`)
- 2 - 현재 큐에 들어있는 칸의 좌표 (N-1번째에 나이트가 도착할 수 있었던 칸들의 좌표) 에 대해 하나씩 꺼내 나이트를 이동시킨다. 이때, 큐가 빌 때 까지 이동한다면 이후 추가될 N번째 나이트의 이동을 통해 도착한 칸에 대해서도 적용하게 되므로, 반복문이 시작되는 시점에서의 큐에 들어있는 원소의 개수만큼만 반복시킨다.

```
●●●  N-1번째에서 도착한 좌표 3개로 시작 → 해당 좌표에 대해서만 처리
●●○○ N번째에서 도착한 좌표 계속 추가
●○○○○○
○○○○○○○ N번째에 도착한 좌표만 남고, 다음 번째(N+1번째) 이동을 위해 반복문으로 전달
```

- 3 - 큐에서 꺼내 나이트를 8개의 방향으로 이동시켰을 때, 체스판을 벗어나지 않고 아직 방문하지 않은 칸이라면 N 번째 이동으로 해당 칸을 방문할 수 있음을 기록하고 큐에 해당 칸의 좌표를 담는다.
만약 이 칸이 목적지라면 BFS 함수를 종료하고 해당 위치를 출력하면 된다.

```cpp
void BFS() {
    if(isTarget(start.x, start.y)) return;
    
    int stage = 0;
    while(!Q.empty()) {
        stage++;
        
        for(int i = Q.size(); i > 0; i--) {
            pos curr = Q.front();
            Q.pop();
            
            for(int moves = 0; moves < 8; moves++) {
                pos next = {curr.x + moveX[moves], curr.y + moveY[moves]};
                
                if(sizeCheck(next.x, next.y) && board[next.x][next.y] == 0) {
                    board[next.x][next.y] = stage;
                    if(isTarget(next.x, next.y)) return;
                    
                    Q.push({curr.x + moveX[moves], curr.y + moveY[moves]});
                }
            }
        }
    }
}
```

메인 함수에서는 크게 어려운 내용은 없다. 몇 번 반복할 지에 대해 `count` 변수에 담고, 반복문을 통해 해당 횟수만큼 반복문을 실행해준다. 반복문 내에서는 체스판의 크기와 시작, 목적지 좌표를 입력받는다. 그리고 큐를 초기화시켜준다. 반복문이기 때문에, 이전 이동을 계산하는 과정에서 큐에 push 된 원소들을 제거해 빈 큐로 만들어줘야 한다. 보드 또한 이전 이동을 계산하는 과정에서 값이 채워졌기 때문에, 다시 0으로 초기화시켜준다. `sizeCheck` 함수를 통해 보드를 벗어나는지를 검사하기 때문에, boardSize 만큼만 0으로 초기화시켜줘도 된다. 초기화가 완료된 뒤, 큐에 시작지점을 담고 앞서 정의한 `BFS` 함수를 실행시켜준다. 함수가 종료된 이후 체스판의 목표지점이 몇 번째에 이동가능한 지를 출력하면 원하는 결과를 얻을 수 있다.

```cpp
int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count;
    cin >> count;
    
    while(count-- > 0) {
        cin >> boardSize;
        cin >> start.x >> start.y;
        cin >> target.x >> target.y;
        Q = queue<pos>(); // element가 들어있는 Queue 비우기
        
        for(int row = 0; row < boardSize; row++) {
            for(int column = 0; column < boardSize; column++) {
                board[row][column] = 0;
            }
        }
        
        Q.push(start);
        BFS();
        cout << board[target.x][target.y] << '\n';
    }
    
    return 0;
}
```

---

## 코멘트

`for(int i = Q.size(); i > 0; i--) {` 코드를 작성하면서 이 부분을 헷갈려서 10분 정도 시간을 뺏긴 것 같다. 큐 사이즈를 저런 방식으로 처리해아지 라고 생각하고 코드를 작성했으면서도 그냥 int = 0; 으로 작성해버렸다. 

---

## 코드

```cpp
#include <iostream>
#include <queue>
    
using namespace std;

typedef struct currentPos {
    int x;
    int y;
} pos;

int boardSize;
int board[301][301];
pos start;
pos target;
queue<pos> Q;

int moveX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int moveY[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool sizeCheck(int x, int y) {
    if(x >= 0 && x < boardSize && y >= 0 && y < boardSize) return true;
    return false;
}

bool isTarget(int x, int y) {
    if(target.x == x && target.y == y) return true;
    return false;
}

void BFS() {
    if(isTarget(start.x, start.y)) return;
    
    int stage = 0;
    while(!Q.empty()) {
        stage++;
        
        for(int i = Q.size(); i > 0; i--) {
            pos curr = Q.front();
            Q.pop();
            
            for(int moves = 0; moves < 8; moves++) {
                pos next = {curr.x + moveX[moves], curr.y + moveY[moves]};
                
                if(sizeCheck(next.x, next.y) && board[next.x][next.y] == 0) {
                    board[next.x][next.y] = stage;
                    if(isTarget(next.x, next.y)) return;
                    
                    Q.push({curr.x + moveX[moves], curr.y + moveY[moves]});
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count;
    cin >> count;
    
    while(count-- > 0) {
        cin >> boardSize;
        cin >> start.x >> start.y;
        cin >> target.x >> target.y;
        Q = queue<pos>(); // element가 들어있는 Queue 비우기
        
        for(int row = 0; row < boardSize; row++) {
            for(int column = 0; column < boardSize; column++) {
                board[row][column] = 0;
            }
        }
        
        Q.push(start);
        BFS();
        cout << board[target.x][target.y] << '\n';
    }
    
    return 0;
}
```
