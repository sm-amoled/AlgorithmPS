# 체스판 다시 칠하기

문제 번호: 1018
알고리즘 분류: 브루트 포스
푼 날짜: 2021년 3월 2일 오후 10:44

## 문제링크

[https://www.acmicpc.net/problem/1018](https://www.acmicpc.net/problem/1018)

## 문제

지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다. 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.

체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.

## 출력

첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

입력된 판에서 만들 수 있는 8X8 체스판의 모양을 모두 살펴보고, 가장 최소한으로 수정할 수 있는 판을 찾으면 된다. 

## 풀이

char 2차원 vector를 선언하여 입력된 board를 받아주었다.

```cpp
int N, M;
cin >> N >> M;

vector<vector<char>> board(N, vector<char>(M));    
for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
        cin >> board[i][j];
    }
}
```

오른쪽/아래로 7개의 칸을 더 선택할 수 있는 칸에 대해서 오른쪽으로 8칸, 아래로 8칸에 대해 수정해야할 칸의 개수를 카운트한다. 각 칸에 대해서 B와 W를 번갈아가면서 비교하고, 이제껏 계산한 count 값 중 작은 값을 minCorrect에 저장한다. 여기에서 63개의 칸이 잘못되었고, 1 개의 칸이 맞다면 1개의 칸이 틀린 것과 같으므로, 64-count의 count 중 작은 값을 count로 선택해준다.

```cpp
int minCorrect = 64;

for(int i = 0; i <= N-8; i++) {
    for(int j = 0; j <= M-8; j++) {
        
        int correct = 0;
        
        for(int p = 0; p < 8; p++) {
            for(int q = 0; q < 8; q++) {
                if(board[i+p][j+q] != (((p+q) % 2 == 0)? 'B':'W')) {
                    correct++;
                }
            }
        }
        
        if(correct > 64-correct) correct = 64-correct;
        minCorrect = (minCorrect < correct)? minCorrect : correct;
    }
}
```

반복문을 모두 수행한 뒤, minCorrect를 출력해주면 원하는 결과를 얻을 수 있다.

```cpp
cout << minCorrect;
```

---

## 코멘트

8x8 체스판을 세로로 8등분 한 다음, 오른쪽으로 이동하면서 체스판을 비교할 때 왼쪽 세로줄의 틀린(맞은)개수를 빼고 새로운 세로줄의 개수를 더해 8개의 칸만 비교한 뒤 개수를 구할 수 있을 것 같다. 

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> board(N, vector<char>(M));    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    int minCorrect = 64;
    
    for(int i = 0; i <= N-8; i++) {
        for(int j = 0; j <= M-8; j++) {
            
            int correct = 0;
            
            for(int p = 0; p < 8; p++) {
                for(int q = 0; q < 8; q++) {
                    if(board[i+p][j+q] != (((p+q) % 2 == 0)? 'B':'W')) {
                        correct++;
                    }
                }
            }
            
            if(correct > 64-correct) correct = 64-correct;
            minCorrect = (minCorrect < correct)? minCorrect : correct;
        }
    }
    
    cout << minCorrect;
		return 0;
}
```