# 2xn 타일링

문제 번호: 11726
알고리즘 분류: DP
푼 날짜: 2021년 2월 6일 오후 12:12

## 문제링크

[https://www.acmicpc.net/problem/11726](https://www.acmicpc.net/problem/11726)

## 문제

2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

![https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11726/1.png](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11726/1.png)

## 입력

첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

## 출력

첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

크기가 2xN인 직사각형을 채울 때 가장 마지막에 붙인 블럭이 1x2 인지 2x1인지에 따라 붙이기 전 블록의 크기를 2xN-2 / 2xN-1로 볼 수 있다. 이를 이용해 다이나믹 프로그래밍으로 블록을 채우는 방법의 수를 구할 수 있다.  

## 풀이

1x2 블럭을 붙이는 경우를 = 로(가로로 붙이려면 2개가 들어가니깐), 2x1 블럭을 붙이는 경우를 | 로 보자. 아래의 예시처럼 블록을 채울 수 있다.

```
n=1 : 1개 |
n=2 : 2개 || , =
n=3 : 3개 ||| , |= , =|
n=4 : 5개 |||| , ||= , |=| , =|| , ==
```

위 예시에서 잘 보면 n=4의 방법들은 모두 n=2 또는 n=3의 방법의 맨 마지막에 | 또는 =을 추가한 것임을 알 수 있다. 즉, `n=4의 방법의 수`는 `n=2의 방법의 수 + n=3의 방법이 수`이다. 이를 코드로 옮기면 아래와 같다.

```cpp
for(int k = 0; k < n+1; k++) {
    if(k > 1) {
        arr[k] = arr[k-1] + arr[k-2];
    } else {
        arr[k] = 1;
    }
}
```

문제에서 방법의 수를 10007로 나눈 나머지를 구해달라고 하였으므로, 코드를 아래와 같이 수정한다. 어차피 나머지 값을 이용하는 것이기 때문에, 값 자체를 미리 나머지로 만들어놔도 값을 뽑아내는데에는 지장이 없다.

```cpp
for(int k = 0; k < n+1; k++) {
    if(k > 1) {
        arr[k] = arr[k-1] + arr[k-2];
        arr[k] %= 10007;
    } else {
        arr[k] = 1;
    }
}
```

---

## 코멘트

훗

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    
    for(int k = 0; k < n+1; k++) {
        if(k > 1) {
            arr[k] = arr[k-1] + arr[k-2];
            arr[k] %= 10007;
        } else {
            arr[k] = 1;
        }
    }
    cout << arr[n];

    return 0;
}
```