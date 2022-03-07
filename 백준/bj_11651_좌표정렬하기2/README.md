# 좌표 정렬하기 2

문제 번호: 11651
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 23일 오후 8:03

### 문제 링크

[https://www.acmicpc.net/problem/11651](https://www.acmicpc.net/problem/11651)

## 문제

2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

## 출력

첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

X, Y position을 함께 갖는 구조체를 선언하고 입력 값을 구조체 배열에 담아둔 뒤, 정렬 알고리즘을 통헤 조건에 맞게 구조체 배열을 정렬한다. 그 뒤, 정렬된 배열의 원소들을 순서대로 출력한다.

## 풀이

정렬할 때 X, Y 좌표가 묶여서 함께 다니게 하기 위해서 구조체를 사용해주었다. Y 좌표가 같을 때는 X 좌표에 대해서, 다를 때는 Y 좌표에 대해서 오름차순으로 정렬을 하면 조건에 맞는 원하는 정렬된 배열을 얻을 수 있다. 정렬된 원소들을 순서대로 출력하면 올바른 결과를 얻을 수 있다.

---

## 코멘트

이정도는 이제 가볍게!

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct position{
    int xPos;
    int yPos;
};

bool compare(position a, position b) {
    if(a.yPos == b.yPos) {
        return a.xPos < b.xPos;
    } else {
        return a.yPos < b.yPos;
    }
}

int main() {
    int count;
    cin >> count;
    position* posArray = new position[count];
    
    for(int i = 0; i < count; i++) {
        scanf("%d %d", &posArray[i].xPos, &posArray[i].yPos);
    }
    
    sort(posArray, posArray+count, compare);
    
    for(int i = 0; i < count; i++) {
        printf("%d %d\n", posArray[i].xPos, posArray[i].yPos);
    }
    return 0;
}
```