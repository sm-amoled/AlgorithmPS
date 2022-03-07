# 좌표 정렬하기

문제 번호: 11650
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 23일 오전 10:41

### 문제 링크

[https://www.acmicpc.net/problem/11650](https://www.acmicpc.net/problem/11650)

## 문제

2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

## 출력

첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

x, y 좌표를 담는 구조체 position을 선언하고 input되는 좌표들을 position 배열에 담아준다. `sort()`함수로 구조체들을 조건에 맞게 정렬하여 출력한다. 

## 풀이

`sort()` 함수는 `algorithm` 헤더파일에 내장되어있다. 눈여겨 볼 점은, 인자로 정렬할 데이터의 시작 메모리 위치, 끝 메모리 위치, 비교 함수를 받는다는 점이다. 아래의 코드에서 posArray가 pointer 값이므로, 배열의 시작 위치, 종료 위치, 비교함수를 인자로 넣어주었다. 주의할 점은, sort 함수의 정렬 범위는 **[startAddress, endAddress)**라는 점이다. 따라서, 0~number-1 까지 정렬하기에 종료 메모리 주소는 posArray+number 을 넣어주어야 한다. 

```cpp
sort(posArray, posArray+number, compare);
```

비교 함수는 조건에 맞게 아래와 같이 작성해주었다. xPos가 같을 경우 yPos를 비교하고, xPos가 다를 경우에는 xPos끼리 비교한다. 

```cpp
bool compare(position a, position b) {
    if(a.xPos == b.xPos) {
        return a.yPos < b.yPos;
    } else {
        return a.xPos < b.xPos;
    }
}
```

---

## 코멘트

이전에 나온 정렬 문제를 풀면서 3시간 넘게 고민한 것 같은데, 블로그에 올라오는 백준 알고리즘 풀이들은 다 `sort`함수를 사용하고 있었다. 예진이도 원래 이런거 풀 때 sort 함수를 사용해도 괜찮다고 했다. 나만 손해보면서 어렵게 풀었나 싶기도 했지만, 덕분에 pointer 개념을 다시 다잡았다고 생각한다. 그래도 sort 함수가 어떻게 사용하는 건지는 알아둬야 하기 때문에 한 번 다뤄보았다.

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct position {
    int xPos;
    int yPos;
};

bool compare(position a, position b) {
    if(a.xPos == b.xPos) {
        return a.yPos < b.yPos;
    } else {
        return a.xPos < b.xPos;
    }
}

int main() {
    int number, xPos, yPos;
    cin >> number;
    
    position* posArray = new position[number];
    
    for(int i = 0; i < number; i++) {
        scanf("%d %d", &xPos, &yPos);
        posArray[i].xPos = xPos;
        posArray[i].yPos = yPos;
    }
    
    sort(posArray, posArray + (number), compare);
    
    for(int i = 0; i < number; i++) {
        printf("%d %d\n", posArray[i].xPos, posArray[i].yPos);
    }
    
    return 0;
}
```