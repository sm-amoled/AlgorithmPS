# N-Queen

문제 번호: 9663
알고리즘 분류: 백 트래킹
푼 날짜: 2021년 3월 4일 오후 10:51

## 문제링크

[https://www.acmicpc.net/problem/9663](https://www.acmicpc.net/problem/9663)

## 문제

N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N이 주어진다. (1 ≤ N < 15)

## 출력

첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

## 조건

- 시간 제한 : 10s
- 메모리 제한 : 128MB

---

## 해설

가로, 세로, 대각선으로 공격이 가능한 퀸을 NxN 체스판 위에 N개 배치하였을때, 서로 공격하지 않는 경우의 수를 구하는 문제이다. 한 행 / 한 열에는 하나의 퀸만이 들어갈 수 있다는 점을 이용하면 좀 더 쉽게 해결이 가능하다.

각 행에 퀸이 몇 번째 열에 들어가있는지를 저장하는 배열/벡터를 이용해 재귀적으로 퀸의 배치 경우의 수를 헤아리면 문제를 해결할 수 있다.

## 풀이

크기가 N인 벡터 하나를 선언해주었다. 이 벡터에는 0번 부터 시작하는 보드의 각 행에 몇번째 열에 퀸이 들어있는지를 나타낸다. 

```cpp
int N;
cin >> N;

vector<int> board(N);
```

```
Q _ _ _       → board [ 1  3  _  _ ]
_ _ Q _        (현재 4X4 보드에 2개의 Queen을 담은 경우)
_ _ _ _
_ _ _ _
```

문제 해결을 위해 `queen` 함수를 재귀적으로 선언해주었다. `queen` 함수이 인자인 board는 위에서 설명한 queen의 각 행에서의 열 정보를 담는 벡터이고, row는 그 중에서 몇 번째 행을 계산중인지를 나타낸다. 해당 row의 모든 column에 대해서 검사를 하는데, 만약 해당 row 전에 배치해둔 queen이 공격을 할 수 있는 자리인 경우에는 survive를 false로 바꾼다. 어떤 queen도 공격을 할 수 없으면 그대로 survive는 true로 남아있다. 먼저 배치한 queen의 공격 유효 검사를 마친 뒤에 survive가 아직 true라면 (공격받지 않는 자리라면) 해당 row의 i번째 column에 퀸을 놓고(`board[row]=i`) row+1에 대한 처리를 호출한다.(`queen(board, row+1`) 만약 공격받는 자리여서 survive가 false라면 그 다음 column에 queen을 배치하는 검사를 수행하게된다.

```cpp
void queen(vector<int> board, int row) {
    int maxBoard = board.size();
    
    for(int i = 0; i < maxBoard; i++) {
        bool survive = true;
        
        for(int j = 1; j <= row; j++) {
            if(board[row-j] == i || board[row-j] == i-j || board[row-j] == i+j) {
                survive = false;
                break;
            }
        }
        
        if(survive) {
            board[row] = i;
            queen(board, row+1);
        }
    }
}

```

만약에 row가 N과 같아진다면 (board는 N-1번째 행까지밖에 없다!) 모든 퀸이 살아남아 호출된 함수이므로 전역변수로 선언된 count에 1을 더해주고 함수를 종료한다. 

```cpp
if(maxBoard == row) {count++; return;}
```

---

## 코멘트

모든 경우의 수에 대해 검사를 하다보니, 생각보다 코드 실행 속도가 엄청엄청 느려진다. 문제 통과 속도가 5000ms 정도가 나왔다. 그래도 아래에 **고민**보다는 나은 수치! ㅋㅋㅋ

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void queen(vector<int> board, int row) {
    int maxBoard = board.size();
    
    if(maxBoard == row) {count++; return;}
    
    for(int i = 0; i < maxBoard; i++) {
        bool survive = true;
        
        for(int j = 1; j <= row; j++) {
            if(board[row-j] == i || board[row-j] == i-j || board[row-j] == i+j) {
                survive = false;
                break;
            }
        }
        
        if(survive) {
            board[row] = i;
            queen(board, row+1);
        }
    }
    
}

int main() {
    int N;
    cin >> N;
    
    vector<int> board(N);
    
    queen(board, 0);
    
    cout << count;
    
	return 0;
}
```

---

## 문제 해결에 대한 고민

처음에는 2차원 배열을 선언해 board 자체를 만들려고 했었다. 어차피 한 행에 하나의 퀸 밖에 안들어가기 때문에, 불필요한 메모리가 많이 들었고, 무엇보다도 2차원 벡터의 각 원소에 접근하는데 반복해서 소요되는 시간이 커져서 시간 초과가 발생했다. 이를 해결하기 위해 위 풀이처럼 1차원 벡터로 바꾸어줬다.  

```cpp
#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void queen(vector<vector<bool>> board, int N, int row) {
    int temp = 0;
    
    if(row == N) {
        count++;
        return;
    }
    
    for(int column = 0; column < N; column++) {
        int temp = 0;
        bool survive = true;
        while(row - ++temp >= 0) {
            // 세로줄
            if(board[row-temp][column]) {
                survive = false;
                break;
            }
            // 왼쪽 대각선
            else if (column-temp >= 0 && board[row-temp][column-temp]) {
                survive = false;
                break;
            }
            // 오른쪽 대각선
            else if (column+temp < N && board[row-temp][column+temp]) {
                survive = false;
                break;
            }
        }
        
        if(survive) {
            board[row][column] = true;
            queen(board, N, row+1);
            board[row][column] = false;
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    
    vector<vector<bool>> board(N, vector<bool>(N, false));
    
    queen(board, N, 0);
    
    cout << count;
    
	return 0;
}
```