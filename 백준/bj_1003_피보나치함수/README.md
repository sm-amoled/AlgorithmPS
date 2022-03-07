# 피보나치 함수

문제 번호: 1003
알고리즘 분류: DP
푼 날짜: 2021년 2월 6일 오후 12:01

## 문제링크

[https://www.acmicpc.net/problem/1003](https://www.acmicpc.net/problem/1003)

## 문제

다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.

```cpp
int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}
```

`fibonacci(3)`을 호출하면 다음과 같은 일이 일어난다.

- `fibonacci(3)`은 `fibonacci(2)`와 `fibonacci(1)` (첫 번째 호출)을 호출한다.
- `fibonacci(2)`는 `fibonacci(1)` (두 번째 호출)과 `fibonacci(0)`을 호출한다.
- 두 번째 호출한 `fibonacci(1)`은 1을 출력하고 1을 리턴한다.
- `fibonacci(0)`은 0을 출력하고, 0을 리턴한다.
- `fibonacci(2)`는 `fibonacci(1)`과 `fibonacci(0)`의 결과를 얻고, 1을 리턴한다.
- 첫 번째 호출한 `fibonacci(1)`은 1을 출력하고, 1을 리턴한다.
- `fibonacci(3)`은 `fibonacci(2)`와 `fibonacci(1)`의 결과를 얻고, 2를 리턴한다.

1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, `fibonacci(N)`을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 테스트 케이스의 개수 T가 주어진다.

각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

## 출력

각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.

## 조건

- 시간 제한 : 0.25s
- 메모리 제한 : 128MB

---

## 해설

다이나믹 프로그래밍을 이용해 해결 가능한 문제이다. 적당히 작은 N번째 피보나치 수에 대해 0과 1의 출력 횟수가 어떻게 움직이는지 살펴보면 일반항을 쉽게 구할 수 있다.

## 풀이

N이 작은 수일 때 fibo(0), fibo(1)을 출력하는 횟수에 대해 간단하게 카운트를 해보자.

```
왼쪽이 fibo(0)의 출력횟수, 오른쪽이 fibo(1)의 출력횟수
fibo(0) : 1 / 0
fibo(1) : 0 / 1
fibo(2) : 1 / 1
fibo(3) : 1 / 2 ← fibo(2) + fibo(1)
fibo(4) : 2 / 3 ← fibo(3) + fibo(2)
fibo(5) : 3 / 5 ← fibo(4) + fibo(3)
			...
```

여기에서 찾을 수 있는 규칙은 fibo(N)의 0과 1의 출력 횟수는 fibo(N-1), fibo(N-2)의 각 숫자의 출력 횟수의 합과 같으며, 이는 피보나치 수열의 증가형태와 똑같다는 것이다. 즉, **fibo(1)의 출력 횟수는 fibo(N)의 값과 같고, fibo(0)의 출력 횟수는 fibo(N-1)과 같다.** 이를 코드로 옮기면 아래와 같다.

```cpp
for(int k = 0; k < n+1; k++) {
    if(k > 1) {
        arr[k] = arr[k-1] + arr[k-2];
    } else {
        arr[k] = k;
    }
}

printf("%d %d\n", arr[n-1], arr[n]);
```

0, 1에 대해서는 고정값으로 0, 1을 넣어주었고, 2부터 일반항을 통해 값을 채워넣을 수 있게 만들었다. 이때 n이 0인 경우 출력에서 arr[-1]의 값에 접근하려 하여 OutOfBound로 에러가 발생하기 때문에, 0에 대해서는 따로 출력을 만들어주었다.

```cpp
if(n == 0) {
    printf("1 0\n");
    continue;
}
```

---

## 코멘트

이 정도는 이제 군생활만큼 쉽다!

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        if(n == 0) {
            printf("1 0\n");
            continue;
        }
        
        vector<int> arr(n+1);
        
        for(int k = 0; k < n+1; k++) {
            if(k > 1) {
                arr[k] = arr[k-1] + arr[k-2];
            } else {
                arr[k] = k;
            }
        }
        
        printf("%d %d\n", arr[n-1], arr[n]);
    }
    return 0;
}
```