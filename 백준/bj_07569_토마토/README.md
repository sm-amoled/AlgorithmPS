# [백준] 7569 - 토마토

Category: 알고리즘
PublishDate: 2022년 3월 8일 오전 1:13
Tag: BFS, DP
Visibility: Public
문제 번호: 7569

## 문제 링크

[https://www.acmicpc.net/problem/7569](https://www.acmicpc.net/problem/7569)

## 문제

철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자모양 상자의 칸에 하나씩 넣은 다음, 상자들을 수직으로 쌓아 올려서 창고에 보관한다.

[https://upload.acmicpc.net/c3f3343d-c291-40a9-9fe3-59f792a8cae9/-/preview/](https://upload.acmicpc.net/c3f3343d-c291-40a9-9fe3-59f792a8cae9/-/preview/)

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

## 입력

첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H가 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다. 둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다. 각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 이러한 N개의 줄이 H번 반복하여 주어진다.

토마토가 하나 이상 있는 경우만 입력으로 주어진다.

## 출력

여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

## 조건

- 시간 제한 : 1초
- 메모리 제한 : 256MB

---

## 해설

이 문제는 **[2D 토마토 문제](https://www.acmicpc.net/problem/7576)**를 3차원으로 쌓은 형태로, 이전 글에서 풀이방법을 응용하여 해결하면 된다.

[🔗 2D 토마토 문제 해설 바로가기](https://etst.tistory.com/328)

이번에는 상하좌우에 위아래가 추가되어 6가지 방향으로 퍼질 수 있는 익은 토마토가 박스 전체에 퍼지기 위해서는 최소 얼마나 기다려야 하는지를 묻는 문제이다. 토마토가 하루에 상하좌우위아래로 주변 한 칸 씩 퍼질 수 있기 때문에 너비 우선 탐색(BFS) 알고리즘을 이용해주고, 익은 토마토가 여러 개에서 시작되므로, 주변 토마토가 익을 때 마다 모두 queue에 담아 익은 순서대로 계산해주었다.

토마토가 모두 익을 때 까지의 시간을 계산하기 위해 box의 토마토가 익었다는 표시로 0을 1로 바꿔주는 대신에, 익은 날짜를 표시(3일차에 익었다면 0→3)하여 계산하였다.

## 풀이

토마토박스 내 좌표계를 위해 `coord` 구조체와 필요한 변수를 선언하였다. 이전 글과 다르게 이번에는 3차원이 되었다는게 가장 큰 차이점이다. M, N, H의 값의 범위는 최대 100까지인데, 박스 주변으로 벽을 치기 위해 양쪽으로 한 칸씩 공간이 필요해 index 101번 까지의 공간을 확보하려고 102로 배열 사이즈를 선언하였다.

```cpp
struct coord {
    int row;
    int column;
    int height;
};

int M, N, H, rawTomato = 0, maxDate = 1;
int box[102][102][102];
queue<coord> ripeTomato;
```

토마토가 익을 때 실행되는 `raw2ripe` 함수에서는 이전과 동일하게 토마토가 익었을 때 처리해야 하는 여러 작업을 수행한다. 

1. 익은 토마토 queue에 좌표 담기
2. 토마토 box에서 익은 날짜 저장하기 (영향을 준 토마토가 익은 날짜 + 1)
3. 익은 날짜가 가장 크다면 (가장 나중에 익었다면) maxDate를 수정하기
4. 안익은 토마토 개수 차감하기

```cpp
void raw2ripe(int row, int column, int height, int date) {
    
    ripeTomato.push({row, column, height});
    
    box[row][column][height] = date + 1;
    maxDate = (maxDate > date + 1)? maxDate : date + 1;
    
    rawTomato--;
}
```

**main** 함수에서는 먼저 모든 박스의 정보를 입력받는다. 범위 계산을 편리하게 하고자 나는 입력된 좌표 주변으로 빈 공간을 삽입해 벽을 만들고자 하였다. 현재 문제에서는 3차원 좌표이므로, 위 아래에 뚜껑과 바닥 공간도 만들어주어야 한다. 벽을 채워넣은 결과는 아래와 같다. 가장 아래와 위에는 -1로 채워진 빈 공간이 생기고, 나머지 박스에도 상하좌우에 -1로 벽이 세워진다. 이를 통해 배열에 잘못된 index로 접근하는 경우를 제거하여 좀 더 편하게 코드를 작성할 수 있다.

```
Input Data
5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
---
box[x][y][0]
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 

box[x][y][1]
-1 -1 -1 -1 -1 -1 -1 
-1 0  0  0  0  0  -1 
-1 0  0  0  0  0  -1 
-1 0  0  0  0  0  -1 
-1 -1 -1 -1 -1 -1 -1 

box[x][y][2]
-1 -1 -1 -1 -1 -1 -1 
-1 0  0  0  0  0  -1 
-1 0  0  1  0  0  -1 
-1 0  0  0  0  0  -1 
-1 -1 -1 -1 -1 -1 -1 

box[x][y][3]
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1
```

추가로, 안익은 토마토를 입력받을 때는 안익은 토마토의 개수를 +1 하고, 익은 토마토를 입력받을 때는 해당 좌표를 queue에 담아준다.

위 과정을 코드로 작성하면 아래와 같다.

```cpp
cin >> M >> N >> H;

// 1번째 층 -1로 채우기
for(int i = 0; i < N+2; i++) {
    for(int j = 0; j < M+2; j++) {
        box[i][j][0] = -1;
    }
}

// 2번째 층부터 쭉 입력받기
for(int k = 1; k < H+1; k++) {
        // 각 층의 첫 줄은 -1 채우고 시작
    for(int j = 0; j < M+2; j++) {
        box[0][j][k] = -1;
    }
    
      // 양 끝에 -1 넣고 한 줄 단위로 입력받기  
    for(int i = 1; i < N+1; i++) {
        box[i][0][k] = -1;
        
        for(int j = 1; j < M+1; j++) {
            int input;
            cin >> input;
            
            box[i][j][k] = input;
            if(input == 0) {
                rawTomato++;
            } else if (input == 1) {
                ripeTomato.push({i, j, k});
            }
        }
       
        box[i][M+1][k] = -1;
    }

        // 각 층의 마지막 줄은 -1을 채우고 끝
    for(int j = 0; j < M+2; j++) {
        box[N+1][j][k] = -1;
    }
}

// 제일 위에 층 -1로 채우기
for(int i = 0; i < N+2; i++) {
    for(int j = 0; j < M+2; j++) {
        box[i][j][H+1] = -1;
    }
}
```

토마토 숙성 과정에서, 주변에 아직 퍼트리지 못한 익은 토마토가 없을 때 까지 다음의 과정을 반복한다. 익은 토마토 queue에서 하나 가져와서, 상하좌우위아래에 아직 안익은 토마토가 있다면 익히는 함수인 `raw2ripe` 함수를 실행해준다.

```cpp
// 토마토 숙성 시작
while(!ripeTomato.empty()) {
    coord current = ripeTomato.front();
    ripeTomato.pop();
    
    for(int i = 0; i < 6; i++) {
        if(box[current.row + X[i]][current.column + Y[i]][current.height + Z[i]] == 0) {
            raw2ripe(current.row + X[i], current.column + Y[i], current.height + Z[i], box[current.row][current.column][current.height]);
        }
    }
}
```

참고로 위 코드의 `X[i], Y[i], Z[i]` 부분은 아래와 같이 작성되어있다. 위와 같이 작성하여 상하좌우위아래를 반복문을 통해 편하게 접근할 수 있다.

```cpp
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};
```

모든 익은 토마토에 대한 처리가 완료되고나면, 아래 코드를 실행한다. 만약 아직 안익은 토마토가 남아있다면 -1을 출력하고(더이상 다른 토마토를 익게 만들 수 있는 토마토가 없음), 그렇지 않다면 가장 마지막에 익은 토마토의 익는데 필요한 날짜를 출력해준다. 이때, 가장 처음 시작할 때 부터 익은 토마토가 1로 저장되어 있었으므로 (원래는 0일차이지만, 1일차에 익었다고 가정하고 작성하였으므로) `maxDate`에서 1을 빼주어야 한다. 아래 코드를 실행하면 원하는 결과를 얻을 수 있다.

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

이전 코드를 조금만 변경하면 쉽게 해결할 수 있는 문제이다! 조금만 더 생각하면 풀 수 있는 문제 🙂

---

## 코드

```cpp
#include <iostream>
#include <queue>
    
using namespace std;

struct coord {
    int row;
    int column;
    int height;
};

int M, N, H, rawTomato = 0, maxDate = 1;
int box[102][102][102];
queue<coord> ripeTomato;

int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

void raw2ripe(int row, int column, int height, int date) {
    
    ripeTomato.push({row, column, height});
    
    box[row][column][height] = date + 1;
    maxDate = (maxDate > date + 1)? maxDate : date + 1;
    
    rawTomato--;
}

int main(int argc, const char * argv[]) {
    cin >> M >> N >> H;
    
    for(int i = 0; i < N+2; i++) {
        for(int j = 0; j < M+2; j++) {
            box[i][j][0] = -1;
        }
    }
    
    for(int k = 1; k < H+1; k++) {
        for(int j = 0; j < M+2; j++) {
            box[0][j][k] = -1;
        }
        
        for(int i = 1; i < N+1; i++) {
            box[i][0][k] = -1;
            
            for(int j = 1; j < M+1; j++) {
                int input;
                cin >> input;
                
                box[i][j][k] = input;
                if(input == 0) {
                    rawTomato++;
                } else if (input == 1) {
                    ripeTomato.push({i, j, k});
                }
            }
            
            box[i][M+1][k] = -1;
        }
    
        for(int j = 0; j < M+2; j++) {
            box[N+1][j][k] = -1;
        }
    }
    
    for(int i = 0; i < N+2; i++) {
        for(int j = 0; j < M+2; j++) {
            box[i][j][H+1] = -1;
        }
    }
    
    // Debug
//    for(int i = 0; i < H+2; i++) {
//        for(int j = 0; j < N+2; j++) {
//            for(int k = 0; k < M+2; k++) {
//                printf("%-3d", box[j][k][i]);
//            }
//            cout << '\n';
//        }
//        cout << '\n';cout << '\n';
//    }

    
    
    // 토마토 숙성 시작
    while(!ripeTomato.empty()) {
        coord current = ripeTomato.front();
        ripeTomato.pop();
        
        for(int i = 0; i < 6; i++) {
            if(box[current.row + X[i]][current.column + Y[i]][current.height + Z[i]] == 0) {
                raw2ripe(current.row + X[i], current.column + Y[i], current.height + Z[i], box[current.row][current.column][current.height]);
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
