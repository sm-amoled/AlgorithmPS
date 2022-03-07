# 쿼드트리

문제 번호: 1992
알고리즘 분류: 분할 정복, 재귀
푼 날짜: 2021년 3월 19일 오후 10:49

## 문제링크

[https://www.acmicpc.net/problem/1992](https://www.acmicpc.net/problem/1992)

## 문제

흑백 영상을 압축하여 표현하는 데이터 구조로 쿼드 트리(Quad Tree)라는 방법이 있다. 흰 점을 나타내는 0과 검은 점을 나타내는 1로만 이루어진 영상(2차원 배열)에서 같은 숫자의 점들이 한 곳에 많이 몰려있으면, 쿼드 트리에서는 이를 압축하여 간단히 표현할 수 있다.

주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이 되고, 모두 1로만 되어 있으면 압축 결과는 "1"이 된다. 만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현한다

![https://www.acmicpc.net/JudgeOnline/upload/201007/qq.png](https://www.acmicpc.net/JudgeOnline/upload/201007/qq.png)

위 그림에서 왼쪽의 영상은 오른쪽의 배열과 같이 숫자로 주어지며, 이 영상을 쿼드 트리 구조를 이용하여 압축하면 "`(0(0011)(0(0111)01)1)`"로 표현된다.  N ×N 크기의 영상이 주어질 때, 이 영상을 압축한 결과를 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에는 영상의 크기를 나타내는 숫자 N 이 주어진다. N 은 언제나 2의 제곱수로 주어지며, 1 ≤ N ≤ 64의 범위를 가진다. 두 번째 줄부터는 길이 N의 문자열이 N개 들어온다. 각 문자열은 0 또는 1의 숫자로 이루어져 있으며, 영상의 각 점들을 나타낸다.

## 출력

영상을 압축한 결과를 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

주어진 사각형의 영상을 2차원 배열에 저장한 뒤, 구간을 나눠 하나의 값으로 표현이 가능한지를 확인한다. 해당 구간을 하나의 값으로 표현하는 것이 불가능하다면 해당 구간을 4등분하여 순서에 맞게 압축을 표현한다.

## 풀이

compress라는 함수를 선언해주었다. 인자로 현재 구간의 시작 행, 시작 열, 구간의 크기를 받아온다. 만약 구간의 크기가 1이라면 영상이 1인지 0인지에 따라 출력을 해주고, 구간의 크기가 1보다 크다면 해당 구간의 영상이 모두 1이거나 0인 경우에는 출력을, 그 외의 경우에는 세부 구간으로 나누어 출력해준다. 세부 구간을 나눌 때는 ‘(‘을 출력하고 4등분 한 구간에 대해 좌상, 우상, 좌하, 우하 순으로 compress 함수를 재귀 호출해준 뒤 ‘)’을 출력한다. 구간 내부에서 compress 함수가 구간에 대한 출력을 마치면 하위 구간에 대해서는 출력이 완성된다.

```cpp
void compress(int R, int C, int S) {
    
    if(S == 1) {
        if(image[R][C]) {
            cout << "1";
        } else {
            cout << "0";
        }
        return;
    }
    
    int count = 0;
    
    for(int row = R; row < R + S; row++) {
        for(int column = C; column < C + S; column++) {
            if(image[row][column]) count++;
        }
    }
    
    if(count == S*S) {
        cout << "1";
    } else if(count == 0) {
        cout << "0";
    } else {
        cout << "(";
        compress(R, C, S/2);
        compress(R, C + S/2, S/2);
        compress(R + S/2, C, S/2);
        compress(R + S/2, C + S/2, S/2);
        cout << ")";
    }
}

```

---

## 코멘트

크게 어렵지는 않은 문제!

---

## 코드

```cpp
#include <iostream>

using namespace std;

bool image[64][64];

void compress(int R, int C, int S) {
    
    if(S == 1) {
        if(image[R][C]) {
            cout << "1";
        } else {
            cout << "0";
        }
        return;
    }
    
    int count = 0;
    
    for(int row = R; row < R + S; row++) {
        for(int column = C; column < C + S; column++) {
            if(image[row][column]) count++;
        }
    }
    
    if(count == S*S) {
        cout << "1";
    } else if(count == 0) {
        cout << "0";
    } else {
        cout << "(";
        compress(R, C, S/2);
        compress(R, C + S/2, S/2);
        compress(R + S/2, C, S/2);
        compress(R + S/2, C + S/2, S/2);
        cout << ")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < N; j++) {
            image[i][j] = (input[j] == '1')? true:false;
        }   
    }
    
    compress(0, 0, N);
    
    return 0;
}
```