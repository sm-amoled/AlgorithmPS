# 2xn 타일링 2

문제 번호: 11727
알고리즘 분류: DP
푼 날짜: 2021년 2월 7일 오후 3:42

## 문제링크

[https://www.acmicpc.net/problem/11727](https://www.acmicpc.net/problem/11727)

## 문제

2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×17 직사각형을 채운 한가지 예이다.

![https://www.acmicpc.net/upload/images/t2n2122.gif](https://www.acmicpc.net/upload/images/t2n2122.gif)

## 입력

첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

## 출력

첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

K칸의 직사각형을 채울 때는 K-1칸의 직사각형에 1x2 블럭을 붙이는 방법, k-2칸의 작사각형에 2x1 블럭 2개를 붙이는 방법, 2x2 블럭 1개를 붙이는 방법이 있다. 

## 풀이

다이나믹 프로그래밍 방법으로 풀면 쉽게 풀리는 문제이다.

K칸의 직사각형을 채울 때는 K-1칸의 직사각형에 1x2 블럭을 붙이는 방법, k-2칸의 작사각형에 2x1 블럭 2개를 붙이는 방법, 2x2 블럭 1개를 붙이는 방법이 있다. 즉 K 직사각형을 채우는 방법의 수 = (K-1) + (K-2)x2 이다. 이를 코드로 작성하면 아래와 같다.

```cpp
tile[i] = tile[i-1] + tile[i-2]*2;
```

여기에서는 N이 1이거나 2인 경우를 커버하지 못하므로, 따로 초깃값 설정으로 예외를 주었다. 

```cpp
if(n < 3) {
    printf("%d\n", (n==1)? 1:3);
    return 0;
}
tile[0] = 1;
tile[1] = 3;
```

문제 조건에 따라 10007로 나눈 나머지를 tile[i]에 넣어주어야 한다. 해당 반복문을 돌리고 나면 `tile[n-1]`에 원하는 결과값이 들어있다. 

```cpp
for(int i = 2; i < n; i++) {
    tile[i] = tile[i-1] + tile[i-2]*2;
    tile[i] %= 10007;
}

cout << tile[n-1];
```

---

## 코멘트

이정도는 쉽지~ 점점 연습되는 기분이 난다 ㅎㅎ 

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tile(n);
    
    if(n < 3) {
        printf("%d\n", (n==1)? 1:3);
        return 0;
    }
    tile[0] = 1;
    tile[1] = 3;
    
    for(int i = 2; i < n; i++) {
        tile[i] = tile[i-1] + tile[i-2]*2;
        tile[i] %= 10007;
    }
    
    cout << tile[n-1];
    return 0;
}
```