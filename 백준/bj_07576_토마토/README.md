# [백준] 7576 - 토마토

Category: 알고리즘
PublishDate: 2022년 3월 7일 오전 1:53
Tag: BFS, 그래프
Visibility: Public
문제 번호: 7576

## 문제 링크

[https://www.acmicpc.net/problem/7576](https://www.acmicpc.net/problem/7576)

## 문제

철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.

[https://upload.acmicpc.net/de29c64f-dee7-4fe0-afa9-afd6fc4aad3a/-/preview/](https://upload.acmicpc.net/de29c64f-dee7-4fe0-afa9-afd6fc4aad3a/-/preview/)

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

## 입력

첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

토마토가 하나 이상 있는 경우만 입력으로 주어진다.

## 출력

여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

## 조건

- 시간 제한 : 1초
- 메모리 제한 : 256MB

---

## 해설

하루에 상하좌우로 퍼질 수 있는 익은 토마토가 박스 전체에 퍼지기 위해서는 최소 얼마나 기다려야 하는지를 묻는 문제이다. 

토마토가 하루에 상하좌우로 주변 한 칸 씩 퍼질 수 있기 때문에 너비 우선 탐색(BFS) 알고리즘을 이용해주고, 익은 토마토가 여러 개에서 시작되므로, 주변 토마토가 익을 때 마다 모두 queue에 담아 익은 순서대로 계산해주었다. 

이 문제에서는 모두 익을 때 까지의 날짜를 계산해야한다. 이를 위해 2가지 방법이 있다.

1. box의 토마토를 익을 때 0→1 로 표시하지 않고, 익은 날짜로 표시하기. 예를 들어 3번째 날에 익었다면 0→3
2. 하루 하루에 대해 queue에 따로 담아 처리하기. 예를 들어, 1일차 queue에 있는 익은 토마토를 다 퍼트렸다면, 2일차 queue의 토마토를 퍼트리기.

위 방법 중에서 나는 1번 방법으로 문제를 해결하였다.

## 풀이

토마토박스 내 좌표계를 위한  `coord` 구조체와 여러 필요한 변수를 선언하였다. 

- rawTomato : 아직 안익은 토마토의 개수. 토마토가 모두 익으면 rawTomato가 0이 된다.
- maxDate : 현재까지 가장 나중에 익은 토마토가 익은 날짜.
- ripeTomato: 익었지만 아직 주변 토마토를 익히지 않은 토마토를 담는 queue. 익히기 후보 토마토.

```cpp
struct coord {
    int row;
    int column;
};

int M, N, rawTomato = 0, maxDate = 1;
int box[1002][1002];
queue<coord> ripeTomato;
```

토마토가 익을 때의 처리를 위해 `raw2ripe`라는 함수를 정의하였다. 이 함수가 실행되면 box[row][column]에 들어있는 안익은 토마토가 익게된다. 토마토가 익을 때는 아래 3개의 항목을 처리한다.

- ripeTomato queue에 해당 토마토 좌표 담기 → 후에 주변 토마토를 익힐 때 사용된다.
- parameter의 date는 이전 토마토가 익은 날짜로, 이 토마토가 익은 날짜인 date+1을 저장하기 위해 box[row][column]에 date+1을 대입한다. 이를 통해 box에는 0(안익은 토마토) 대신 토마토가 익은 날짜가 표시된다.
참고로, 0일차부터 이미 익어있던 토마토가 1로 시작하였으므로, 날짜에 대해 저장되는 값은 1씩 밀려있다. (0일차 - 1 / 1일차 - 2 / ...)
- 안익은 토마토의 개수를 한 개 빼준다.

```cpp
void raw2ripe(int row, int column, int date) {
    
    ripeTomato.push({row, column});
    
    box[row][column] = date + 1;
    maxDate = (maxDate > date + 1)? maxDate : date + 1;
    
    rawTomato--;
}
```

main 함수에서 토마토 박스의 정보를 입력받는다. 함수 및 코드를 깔끔하게 정의하기 위해 박스 주변을 -1로 테두리 쳐서 비어있다고 표시하였다. 토마토의 정보를 입력받을 때, 안익은 토마토는 개수를 카운트 하였고, 익은 토마토는 좌표를 `ripeTomato`에 push하였다. 

```cpp
cin >> M >> N;

for(int j = 0; j < M+2; j++) {
    box[0][j] = -1;
}

for(int i = 1; i < N+1; i++) {
    box[i][0] = -1;
    
		// 실제 토마토 정보 입력받기
    for(int j = 1; j < M+1; j++) {
        int input;
        cin >> input;
        
        box[i][j] = input;
        if(input == 0) {
            rawTomato++;
        } else if (input == 1) {
            ripeTomato.push({i, j});
        }
    }
    
    box[i][M+1] = -1;
}

for(int j = 0; j < M+2; j++) {
    box[N+1][j] = -1;
}
```

input 이후에는 `ripeTomato` 큐가 빌 때 까지(현재 익었지만 주변에 아직 못 퍼트린 토마토가 없을 때 까지) 아래를 반복한다.

1. `ripeTomato`에서 가장 앞 원소를 pop하고, 좌표를 가져온다.
2. 동서남북에 대해 아직 익지 않았다면 `raw2ripe()` 함수를 호출해 토마토를 익힌다.

```cpp
// 토마토 숙성 시작
while(!ripeTomato.empty()) {
    coord current = ripeTomato.front();
    ripeTomato.pop();
    
    for(int i = 0; i < 4; i++) {
        if(box[current.row + X[i]][current.column + Y[i]] == 0) {
            raw2ripe(current.row + X[i], current.column + Y[i], box[current.row][current.column]);
        }
    }
}
```

이후 모든 토마토가 다 주변에 퍼트렸다면 아래를 실행해주면 원하는 결과를 얻을 수 있다.

- 만약 안익은 토마토가 하나라도 있다면 모든 토마토를 익힐 수 없는 형태이므로 -1을 출력한다.
- 토마토가 모두 익었다면 익는데 걸린 날짜를 출력한다. 앞에서 언급했듯이, 처음부터 익어있던 토마토의 값이 1에서 시작했으므로, 토마토가 익었다고 저장된 날짜 모두 하루씩 밀려있다. 따라서 maxDate-1을 출력해주면 정확한 날짜를 출력할 수 있다.

```cpp
// 토마토 숙성 완료
if(rawTomato > 0) {
    cout << "-1";
} else {
    cout << maxDate-1;
}
```

---

## 코멘트

오랜만에 푸는 BFS 문제라 걱정했는데, 그래도 무난하게 풀리는 문제였다. 🙂

---

## 코드

```cpp
#include <iostream>
#include <queue>
    
using namespace std;

struct coord {
    int row;
    int column;
};

int M, N, rawTomato = 0, maxDate = 1;
int box[1002][1002];
queue<coord> ripeTomato;

int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

void raw2ripe(int row, int column, int date) {
    
    ripeTomato.push({row, column});
    
    box[row][column] = date + 1;
    maxDate = (maxDate > date + 1)? maxDate : date + 1;
    
    rawTomato--;
}

int main(int argc, const char * argv[]) {
    cin >> M >> N;
    
    for(int j = 0; j < M+2; j++) {
        box[0][j] = -1;
    }
    
    for(int i = 1; i < N+1; i++) {
        box[i][0] = -1;
        
        for(int j = 1; j < M+1; j++) {
            int input;
            cin >> input;
            
            box[i][j] = input;
            if(input == 0) {
                rawTomato++;
            } else if (input == 1) {
                ripeTomato.push({i, j});
            }
        }
        
        box[i][M+1] = -1;
    }
    
    for(int j = 0; j < M+2; j++) {
        box[N+1][j] = -1;
    }
    
    // 토마토 숙성 시작
    while(!ripeTomato.empty()) {
        coord current = ripeTomato.front();
        ripeTomato.pop();
        
        for(int i = 0; i < 4; i++) {
            if(box[current.row + X[i]][current.column + Y[i]] == 0) {
                raw2ripe(current.row + X[i], current.column + Y[i], box[current.row][current.column]);
            }
        }
    }
    
    // 토마토 숙성 완료
    if(rawTomato > 0) {
        cout << "-1";
    } else {
        cout << maxDate-1;
    }
    
    return 0;
}
```