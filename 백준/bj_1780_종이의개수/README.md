# 종이의 개수

문제 번호: 1780
알고리즘 분류: 분할 정복, 재귀
푼 날짜: 2021년 3월 20일 오전 11:40

## 문제링크

[https://www.acmicpc.net/problem/1780](https://www.acmicpc.net/problem/1780)

## 문제

N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다. 우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 규칙에 따라 자르려고 한다.

1. 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
2. (1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.

이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

## 입력

첫째 줄에 N(1 ≤ N ≤ 3^7, N은 3^k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

## 출력

첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 256MB

---

## 해설

구간에 대해 1, 0, -1의 개수를 세어보고, 전체가 같은 값으로 이루어져있으면 해당 구역은 하나의 종이로 헤아린다. 만약 전체가 같은 값이 아니라면 해당 구간을 3x3으로 9등분하여 각각의 구간에 대해 같은 방식으로 종이의 개수를 헤아린다.

## 풀이

여러 구간에 대해 동일한 방법으로 작게 쪼개어 접근하므로 재귀함수를 만들어주었다. 구간의 시작 행, 열, 크기를 받아와 해당 구간에 모든 값이 0, -1, 1 으로 같다면 각 경우에 따라 zeroResult, minusResult, plusResult에 값을 1 추가해준다. 만약 모두 같은 값이 아니라면 구간을 9등분하여 각 구간에 대해 이 함수를 실행해준다. 크기가 1인 경우 더이상 나눌 수 없으므로, 값에 매치되는 result 값에 1을 더해준다.

```cpp
void getPaper(int R, int C, int S) {
    int zero = 0, plus = 0, minus = 0;
    
    for(int row = R; row < R + S; row++) {
        for(int column = C; column < C + S; column++) {
            if(paper[row][column] == 0) {
                zero++;
            } else if (paper[row][column] == 1) {
                plus++;
            } else {
                minus++;
            }
        }
    }
    
    if(plus == 0 && minus == 0) {
        zeroResult++;
    } else if (plus == 0 && zero == 0) {
        minusResult++;
    } else if (minus == 0 && zero == 0) {
        plusResult++;
    } else {
        getPaper(R,           C, S/3);  getPaper(R,           C + S/3, S/3);    getPaper(R,           C + S/3 * 2, S/3);
        getPaper(R + S/3,     C, S/3);  getPaper(R + S/3,     C + S/3, S/3);    getPaper(R + S/3,     C + S/3 * 2, S/3);
        getPaper(R + S/3 * 2, C, S/3);  getPaper(R + S/3 * 2, C + S/3, S/3);    getPaper(R + S/3 * 2, C + S/3 * 2, S/3);
    }
    
    return;
}

```

---

## 코멘트

이런 유형은 이제 간단하게 해결할 수 있을 것 같다. ㅎㅎ

---

## 코드

```cpp
#include <iostream>
#include <math.h>

using namespace std;

int paper[2187][2187];
int minusResult = 0, plusResult = 0, zeroResult = 0;

void getPaper(int R, int C, int S) {
    int zero = 0, plus = 0, minus = 0;
    
    for(int row = R; row < R + S; row++) {
        for(int column = C; column < C + S; column++) {
            if(paper[row][column] == 0) {
                zero++;
            } else if (paper[row][column] == 1) {
                plus++;
            } else {
                minus++;
            }
        }
    }
    
    if(plus == 0 && minus == 0) {
        zeroResult++;
    } else if (plus == 0 && zero == 0) {
        minusResult++;
    } else if (minus == 0 && zero == 0) {
        plusResult++;
    } else {
        getPaper(R,           C, S/3);  getPaper(R,           C + S/3, S/3);    getPaper(R,           C + S/3 * 2, S/3);
        getPaper(R + S/3,     C, S/3);  getPaper(R + S/3,     C + S/3, S/3);    getPaper(R + S/3,     C + S/3 * 2, S/3);
        getPaper(R + S/3 * 2, C, S/3);  getPaper(R + S/3 * 2, C + S/3, S/3);    getPaper(R + S/3 * 2, C + S/3 * 2, S/3);
    }
    
    return;
}

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    
    
    getPaper(0, 0, N);
    
    cout << minusResult << '\n' << zeroResult << '\n' << plusResult;
    return 0;
}
```