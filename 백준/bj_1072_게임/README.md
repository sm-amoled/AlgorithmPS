# 게임

문제 번호: 1072
알고리즘 분류: 이분 탐색
푼 날짜: 2021년 1월 31일 오후 7:54

### 문제 링크

[https://www.acmicpc.net/problem/1072](https://www.acmicpc.net/problem/1072)

## 문제

김형택은 지금 몰래 Spider Solitaire(스파이더 카드놀이)를 하고 있다. 형택이는 이 게임을 이길 때도 있었지만, 질 때도 있었다. 누군가의 시선이 느껴진 형택이는 게임을 중단하고 코딩을 하기 시작했다. 의심을 피했다고 생각한 형택이는 다시 게임을 켰다. 그 때 형택이는 잠시 코딩을 하는 사이에 자신의 게임 실력이 눈에 띄게 향상된 것을 알았다.

이제 형택이는 앞으로의 모든 게임에서 지지 않는다. 하지만, 형택이는 게임 기록을 삭제 할 수 없기 때문에, 자신의 못하던 예전 기록이 현재 자신의 엄청난 실력을 증명하지 못한다고 생각했다.

게임 기록은 다음과 같이 생겼다.

- 게임 횟수 : X
- 이긴 게임 : Y (Z%)
- Z는 형택이의 승률이고, 소수점은 버린다. 예를 들어, X=53, Y=47이라면, Z=88이다.

X와 Y가 주어졌을 때, 형택이가 게임을 최소 몇 번 더 해야 Z가 변하는지 구하는 프로그램을 작성하시오.

## 입력

각 줄에 정수 X와 Y가 주어진다.

- 1 ≤ X ≤ 1,000,000,000
- 0 ≤ Y ≤ X

## 출력

첫째 줄에 형택이가 게임을 최소 몇 판 더 해야하는지 출력한다. 만약 Z가 절대 변하지 않는다면 -1을 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

Z값이 변하려면 몇 판 더 해야하는지를 기준으로 binary search를 실행하여 최소값을 찾을 수 있다. 

## 풀이

우선 이 문제의 구하고자 하는 값은 Z값을 변하게 하는 최수 게임 판 수이다. 게임 판 수가 증가하면 Z값도 항상 증가하는 함수를 세울 수 있으므로, 이분 탐색을 통해 Z값을 변하게 하는 게임 판 수를 찾으면 된다. 

일단 X의 범위가 10억이기 때문에, XY 모두 long 형으로 자료형을 선언해주었다. 기준 승률 Z는 `winRate()` 함수를 만들어 대입해주었다. 필요한 값이 소수점 아래를 절삭한 백분율이므로, `100 * win / total` 을 반환해주는 함수로 선언하였다. 만약 `win / total` 을 계산한 다음 100을 곱해주었으면 정수형이기에 부적절한 값이 나왔겠지만, 먼저 100을 곱해주고 total로 나누었기 때문에 적절한 값이 나와 따로 부동소수점 자료형으로 형변환해줄 필요가 없다.  

```cpp
long X, Y;
int Z;
cin >> X >> Y;
Z = winRate(Y, X);
```

```cpp
int winRate(long win, long total) {
    return 100 * win / total;
}
```

문제 조건에서 Z가 변하지 않는다면 -1을 출력하라 했는데, Z가 변하지 않는 조건은 1. 100%라서 더 올라갈 곳이 없거나, 2. 99%라 아무리 이겨도 100%를 달성할 수 없는 경우 두 종류이다. 

```cpp
if(Z >= 99) {
    printf("-1");
    return 0;
}

```

찾고자 하는 값이 기존의 winRate보다 값이 커지는 최소한의 게임 판 수 이므로, 기존 winRate인 **Z를 key로 하여 upper bound를 찾는 알고리즘**을 작성해주었다. 아래 알고리즘을 거치고 나면 `right`에는 key보다 큰 최소한의 값을 가리키는 index(여기에서는 게임 판 수의 매개변수)가 저장되어있다.  

```cpp
long left = 0, right = 1000000000;

while(left < right) {
    long mid = (left+right)/2;
    int A = winRate(Y+mid, X+mid);
    
    if(A > Z) {
        right = mid;
    } else {
        left = mid + 1;
    }
}
printf("%ld", right);

```

---

## 코멘트

조만간 이분 탐색에 대한 내용을 정리해야할 것 같다. 범위, 알고리즘의 개형이 사람마다 자꾸 바뀌니 헷갈리는 것 같다. 

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int winRate(long win, long total) {
    return 100 * win / total;
}

int main() {
    
    long X, Y;
		int Z;
    cin >> X >> Y;
    Z = winRate(Y, X);
    
    if(Z >= 99) {
        printf("-1");
        return 0;
    }
    
    long left = 0, right = 1000000000;
    
    while(left < right) {
        long mid = (left+right)/2;
        int A = winRate(Y+mid, X+mid);
        
        if(A > Z) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    printf("%ld", right);
    return 0;
}
```