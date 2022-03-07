# 스도쿠

문제 번호: 2580
알고리즘 분류: 백 트래킹
푼 날짜: 2021년 3월 6일 오후 7:55

## 문제링크

[https://www.acmicpc.net/problem/2580](https://www.acmicpc.net/problem/2580)

## 문제

스도쿠는 18세기 스위스 수학자가 만든 '라틴 사각형'이랑 퍼즐에서 유래한 것으로 현재 많은 인기를 누리고 있다. 이 게임은 아래 그림과 같이 가로, 세로 각각 9개씩 총 81개의 작은 칸으로 이루어진 정사각형 판 위에서 이뤄지는데, 게임 시작 전 일부 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.

![https://www.acmicpc.net/upload/images/jF1kwmQaGGRM3t9ESvpTvW34kCnB2.png](https://www.acmicpc.net/upload/images/jF1kwmQaGGRM3t9ESvpTvW34kCnB2.png)

나머지 빈 칸을 채우는 방식은 다음과 같다.

1. 각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
2. 굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.

위의 예의 경우, 첫째 줄에는 1을 제외한 나머지 2부터 9까지의 숫자들이 이미 나타나 있으므로 첫째 줄 빈칸에는 1이 들어가야 한다.

![https://www.acmicpc.net/upload/images/iWqN5AZPf4h.png](https://www.acmicpc.net/upload/images/iWqN5AZPf4h.png)

또한 위쪽 가운데 위치한 3x3 정사각형의 경우에는 3을 제외한 나머지 숫자들이 이미 쓰여있으므로 가운데 빈 칸에는 3이 들어가야 한다.

![https://www.acmicpc.net/upload/images/A9FWbU92T9v2Fjr9U6Qsg.png](https://www.acmicpc.net/upload/images/A9FWbU92T9v2Fjr9U6Qsg.png)

이와 같이 빈 칸을 차례로 채워 가면 다음과 같은 최종 결과를 얻을 수 있다.

![https://www.acmicpc.net/upload/images/fjCQBE3QI9BMGeiClrtwkHy3jeGPNi.png](https://www.acmicpc.net/upload/images/fjCQBE3QI9BMGeiClrtwkHy3jeGPNi.png)

게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.

## 입력

아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다. 스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.

## 출력

모든 빈 칸이 채워진 스도쿠 판의 최종 모습을 아홉 줄에 걸쳐 한 줄에 9개씩 한 칸씩 띄워서 출력한다.

스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력한다.

## 제한

- baekjoon의 백트래킹 알고리즘으로 풀 수 있는 입력만 주어진다. 다음은 그 알고리즘의 수행 시간이다.
    - C++14: 80ms
    - Java: 292ms
    - PyPy3: 1172ms

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

스도쿠를 백트래킹으로 완전히 채워넣는 방법을 구현하면 된다. 빈 칸에 대해서만 값을 찾아서 넣으면 되므로, 빈 칸에 대한 정보를 가진 blank와 스도쿠 판의 숫자들을 저장하는 sudoku를 선언하고, 재귀 함수를 만들어서 백트래킹으로 모든 경우의 수에 대해 검사해주었다.

## 풀이

아래와 같이 값들을 입력받아주었다.  9x9 배열을 선언하여 스도쿠 숫자들을 관리하고, pair 벡터에 빈 칸의 row, column 값을 담아 관리해준다.

```cpp
int sudoku[9][9];
vector<pair<int, int>> blank;

for(int row = 0; row < 9; row++) {
    for(int column = 0; column < 9; column++) {
        cin >> sudoku[row][column];
        
        if(sudoku[row][column] == 0) {
            blank.push_back(make_pair(row, column));
        }
    }
}
```

스도쿠를 채우는 재귀함수 `findValue`를 만들어주었다.  index번째 빈 칸의 row, column에 대해 1~9까지의 값을 순서대로 집어넣는다. 만약에 같은 행, 열, 3x3칸에 같은 숫자가 있다면 값을 대입할 수 없고, 없는 경우에만 대입해준다. 이를 위해 `checkValue`라는 함수를 선언해주었다. 각 값을 넣고나서 그 다음 차례의 빈 칸에 숫자를 넣어본다. (재귀 호출) 만약 다음 차례의 값에서 1~9 중 넣을 수 있는 숫자가 없는 경우 (숫자를 잘못 넣은 것이므로 = findAnswer가 false) 다음 숫자를 넣고 다시 다음 차례의 빈 칸에 수를 대입해본다.  숫자를 다 넣어봤는데 여기에서 답을 찾지 못한 경우에는 0을 넣어 다시 빈 칸으로 만들고 이전 빈 칸의 수를 바꾸기 위해 이번 함수를 종료해준다. 

```cpp
void findValue(int sudoku[][9], vector<pair<int, int>> blank, int index) {    
    int row = blank[index].first;
    int column = blank[index].second;
    
    for(int select = 1; select <= 9; select++) { 
        if(checkValue(sudoku, row, column, select)) {
            sudoku[row][column] = select;
            findValue(sudoku, blank, index+1);
        }
    }
    sudoku[row][column] = 0;
}
```

`findValue`의 함수의 종료 조건은 빈 칸을 모두 채우는 것이므로, 빈 칸의 호출 index가 빈 칸의 개수와 같을 때 (모두 처리했을 때) 스도쿠 판을 모두 출력해주고, findAnswer bool 값을 true로 만들어 return하면서 이전의 재귀적으로 호출된 함수들의 반복문들을 모두 종료시킨다. 이를 위해 findAnswer는 전역변수로 선언해준다.

```cpp
bool findAnswer = false;

void findValue(int sudoku[][9], vector<pair<int, int>> blank, int index) {
    if(index == blank.size()) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }cout <<'\n';
        }

        findAnswer = true;
        return;
    }
    
    int row = blank[index].first;
    int column = blank[index].second;
    
    for(int select = 1; select <= 9; select++) { 
        if(checkValue(sudoku, row, column, select)) {
            sudoku[row][column] = select;
            findValue(sudoku, blank, index+1);
        }
        
        if(findAnswer) return;
    }
    sudoku[row][column] = 0;
}
```

`checkValue` 함수에서는 같은 행, 열, 3x3 칸에 같은 숫자가 있는지를 검사해준다. 만약에 있으면 false, 없으면 true를 반환해준다.

```cpp
bool checkValue(int sudoku[][9], int row, int column, int value) {
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][column] == value || sudoku[row][i] == value) return false;
    }
    
    int rowIndex = row/3 * 3;
    int columnIndex = column/3 * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(sudoku[rowIndex+i][columnIndex+j] == value) return false;
        }
    }
    
    return true;
}
```

입력을 모두 받고난 main 함수에서 아래 코드 한 줄을 실행해주면, 원하는 결과를 얻을 수 있다. 함수의 인자로 전달되는 0은 0번째 index의 빈 칸부터 순서대로 처리해달라는 뜻이다.

```cpp
findValue(sudoku, blank, 0);
```

---

## 코멘트

vector가 배열보다 확실히 성능 면에 있어서 오버헤드가 큰 것을 느꼈다. 이것때문에 문제 통과를 못하는 일이 일어난 걸 보니... 

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

bool findAnswer = false;

bool checkValue(int sudoku[][9], int row, int column, int value) {
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][column] == value || sudoku[row][i] == value) return false;
    }
    
    int rowIndex = row/3 * 3;
    int columnIndex = column/3 * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(sudoku[rowIndex+i][columnIndex+j] == value) return false;
        }
    }
    
    return true;
}

void findValue(int sudoku[][9], vector<pair<int, int>> blank, int index) {
    if(index == blank.size()) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }cout <<'\n';
        }

        findAnswer = true;
        return;
    }
    
    int row = blank[index].first;
    int column = blank[index].second;
    
    for(int select = 1; select <= 9; select++) { 
        if(checkValue(sudoku, row, column, select)) {
            sudoku[row][column] = select;
            findValue(sudoku, blank, index+1);
        }
        
        if(findAnswer) return;
    }
    sudoku[row][column] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int sudoku[9][9];
    vector<pair<int, int>> blank;
    
    for(int row = 0; row < 9; row++) {
        for(int column = 0; column < 9; column++) {
            cin >> sudoku[row][column];
            
            if(sudoku[row][column] == 0) {
                blank.push_back(make_pair(row, column));
            }
        }
    }
    
    findValue(sudoku, blank, 0);

		return 0;
}
```

---

## 문제 해결에 대한 고민

처음에는 스도쿠 판 자체를 2차원 벡터 `vector<vector<int>> sudoku`로 만들었었는데, 자꾸 시간 초과가 발생해서 2차원 벡터로 변경해주었더니 바로 통과가 되었다. 사람들이 문제풀이를 하면서 최대 크기가 주어진 문제 풀이에 대해서는 크기 N 값을 입력받아도 vector가 아니라 배열을 사용하는 이유가 궁금했는데 (최대 크기가 10000x10000이라도 입력 받는 값이 MxN이면 MxN크기만큼의 벡터를 동적으로 선언하는게 더 효율적이라고 생각해서) 시간 처리에 있어서 vector가 오버헤드가 확실히 크다는 것을 느꼈다.