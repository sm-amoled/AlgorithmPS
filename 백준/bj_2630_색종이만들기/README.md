# 색종이 만들기

문제 번호: 2630
알고리즘 분류: 분할 정복, 재귀
푼 날짜: 2021년 3월 19일 오후 8:59

## 문제링크

[https://www.acmicpc.net/problem/2630](https://www.acmicpc.net/problem/2630)

## 문제

아래 <그림 1>과 같이 여러개의 정사각형칸들로 이루어진 정사각형 모양의 종이가 주어져 있고, 각 정사각형들은 하얀색으로 칠해져 있거나 파란색으로 칠해져 있다. 주어진 종이를 일정한 규칙에 따라 잘라서 다양한 크기를 가진 정사각형 모양의 하얀색 또는 파란색 색종이를 만들려고 한다.

![https://www.acmicpc.net/upload/images/bwxBxc7ghGOedQfiT3p94KYj1y9aLR.png](https://www.acmicpc.net/upload/images/bwxBxc7ghGOedQfiT3p94KYj1y9aLR.png)

전체 종이의 크기가 N×N(N=2k, k는 1 이상 7 이하의 자연수) 이라면 종이를 자르는 규칙은 다음과 같다.

전체 종이가 모두 같은 색으로 칠해져 있지 않으면 가로와 세로로 중간 부분을 잘라서 <그림 2>의 I, II, III, IV와 같이 똑같은 크기의 네 개의 N/2 × N/2색종이로 나눈다. 나누어진 종이 I, II, III, IV 각각에 대해서도 앞에서와 마찬가지로 모두 같은 색으로 칠해져 있지 않으면 같은 방법으로 똑같은 크기의 네 개의 색종이로 나눈다. 이와 같은 과정을 잘라진 종이가 모두 하얀색 또는 모두 파란색으로 칠해져 있거나, 하나의 정사각형 칸이 되어 더 이상 자를 수 없을 때까지 반복한다.

위와 같은 규칙에 따라 잘랐을 때 <그림 3>은 <그림 1>의 종이를 처음 나눈 후의 상태를, <그림 4>는 두 번째 나눈 후의 상태를, <그림 5>는 최종적으로 만들어진 다양한 크기의 9장의 하얀색 색종이와 7장의 파란색 색종이를 보여주고 있다.

![https://www.acmicpc.net/upload/images/VHJpKWQDv.png](https://www.acmicpc.net/upload/images/VHJpKWQDv.png)

입력으로 주어진 종이의 한 변의 길이 N과 각 정사각형칸의 색(하얀색 또는 파란색)이 주어질 때 잘라진 하얀색 색종이와 파란색 색종이의 개수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에는 전체 종이의 한 변의 길이 N이 주어져 있다. N은 2, 4, 8, 16, 32, 64, 128 중 하나이다. 색종이의 각 가로줄의 정사각형칸들의 색이 윗줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 하얀색으로 칠해진 칸은 0, 파란색으로 칠해진 칸은 1로 주어지며, 각 숫자 사이에는 빈칸이 하나씩 있다.

## 출력

첫째 줄에는 잘라진 햐얀색 색종이의 개수를 출력하고, 둘째 줄에는 파란색 색종이의 개수를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

N이 2의 제곱수이므로, N은 1이 될 때 까지 계속 2로 나눌 수 있다. 특정한 정사각형 모양의 구간을 모두 같은 색인지 확인하고, 아니라면 해당 구역을 4등분 하여 각각의 조각마다 같은 색인지를 확인하는 과정을 반복한다. 만약 해당 구역의 크기가 1x1이라면 더이상 자를 수 없으므로 1칸 짜리 색종이로 헤아린다. 이렇게 구할 수 있는 구간 내의 색이 모두 같은 파란색, 하얀색 색종이의 수를 구하면 된다.

## 풀이

재귀를 이용하는 `getPaper()` 함수를 만들어주었다. 인자로 구역의 시작지점과 size 값을 받아온다. 만약 이 size가 1이라면 더 나눌 수 없으므로 파란색/하얀색 색종이의 개수에 1을 추가해준다. 그렇지 않은 경우에는 해당 구역 내의 파란색의 개수를 모두 세어본다. 모두 파란색이라면 (= size^2 와 개수가 같다면) 파란색 색종이 개수에 1을 추가하고, 모두 하얀색이라면 ( = 0개 있다면) 하얀색 색종이 개수에 1을 추가한다. 하얀색과 파란색이 구간 내에 섞여있다면, 4등분하여 각각의 더 작은 구간에 대해 `getPaper` 함수를 실행해준다.

```cpp
void getPaper(int Rstart, int Cstart, int size) {
    if(size == 1) {
        if(paper[Rstart][Cstart]) {
           blue++;
        //   cout << "blue  : " << Rstart << " " << Cstart << '\n';
       } else {
           white++;
        //   cout << "white : " << Rstart << " " << Cstart << '\n';
       }
       return;
    }
    
    bool cmp = paper[Rstart][Cstart];
    int sum = 0;
    for(int rowIndex = 0; rowIndex < size; rowIndex++) {
        for(int columnIndex = 0; columnIndex < size; columnIndex++) {
            if(paper[Rstart + rowIndex][Cstart + columnIndex]) sum++;
        }
    }
    
    if(sum == size*size) {
      blue++;
    } else if (sum == 0) {
      white++;
    } else {
        getPaper(Rstart, Cstart, size/2);
        getPaper(Rstart + size/2, Cstart, size/2);
        getPaper(Rstart, Cstart + size/2, size/2);
        getPaper(Rstart + size/2, Cstart + size/2, size/2);
    }
    
    return;
}
```

파란색과 하얀색은 2차원 배열에 true, false 로 받아주었다. `getPaper(0, 0, N)` 함수를 실행하면 하얀색/파란색 색종이의 개수가 저장되고, 이를 출력해주면 원하는 결과를 얻을 수 있다. 

```cpp
int N;
cin >> N;

for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
        int input;
        cin >> input;
        
        paper[i][j] = (input == 1)? true:false;
    }
}

getPaper(0, 0, N);

cout << white << '\n' << blue;
```

---

## 코멘트

생각보다 쉬운데 생각보다 어려웠다.

---

## 코드

```cpp
#include <iostream>

using namespace std;

int blue = 0, white = 0;
bool paper[128][128] = {false};

void getPaper(int Rstart, int Cstart, int size) {
    if(size == 1) {
        if(paper[Rstart][Cstart]) {
           blue++;
        //   cout << "blue  : " << Rstart << " " << Cstart << '\n';
       } else {
           white++;
        //   cout << "white : " << Rstart << " " << Cstart << '\n';
       }
       return;
    }
    
    bool cmp = paper[Rstart][Cstart];
    int sum = 0;
    for(int rowIndex = 0; rowIndex < size; rowIndex++) {
        for(int columnIndex = 0; columnIndex < size; columnIndex++) {
            if(paper[Rstart + rowIndex][Cstart + columnIndex]) sum++;
        }
    }
    
    if(sum == size*size) {
      blue++;
    } else if (sum == 0) {
      white++;
    } else {
        getPaper(Rstart, Cstart, size/2);
        getPaper(Rstart + size/2, Cstart, size/2);
        getPaper(Rstart, Cstart + size/2, size/2);
        getPaper(Rstart + size/2, Cstart + size/2, size/2);
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int input;
            cin >> input;
            
            paper[i][j] = (input == 1)? true:false;
        }
    }
    
    getPaper(0, 0, N);
    
    cout << white << '\n' << blue;
    return 0;
}
```

---

## 문제 해결에 대한 고민

시작구간~끝구간 을 인자로 받아와서 해당 구역 내에 모두 비교문을 돌려서 다른게 있으면 4등분하여 함수를 호출하는 방법을 사용했었는데, 개수를 헤아리는 방법이 좀 더 섹시한 방법인 것 같다.

이 아이디어는 아래 블로그에서 풀이 게시글을 읽으면서 이용하게 되었다. [https://developmentdiary.tistory.com/334](https://developmentdiary.tistory.com/334)