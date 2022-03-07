# 파도반 수열

문제 번호: 9461
알고리즘 분류: DP
푼 날짜: 2021년 2월 7일 오후 4:13

## 문제링크

[https://www.acmicpc.net/problem/9461](https://www.acmicpc.net/problem/9461)

## 문제

![https://www.acmicpc.net/upload/images/pandovan.png](https://www.acmicpc.net/upload/images/pandovan.png)

오른쪽 그림과 같이 삼각형이 나선 모양으로 놓여져 있다. 첫 삼각형은 정삼각형으로 변의 길이는 1이다. 그 다음에는 다음과 같은 과정으로 정삼각형을 계속 추가한다. 나선에서 가장 긴 변의 길이를 k라 했을 때, 그 변에 길이가 k인 정삼각형을 추가한다.

파도반 수열 P(N)은 나선에 있는 정삼각형의 변의 길이이다. P(1)부터 P(10)까지 첫 10개 숫자는 1, 1, 1, 2, 2, 3, 4, 5, 7, 9이다.

N이 주어졌을 때, P(N)을 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. (1 ≤ N ≤ 100)

## 출력

각 테스트 케이스마다 P(N)을 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

삼각형에 번호를 붙여보면, K번째 삼각형을 만드는 두 변은 K-1번째 삼각형과 K-5번째 삼각형의 변이다.

## 풀이

그림에서 삼각형에 번호를 붙여보면 K번째 삼각형을 만드는 두 변은 K-1번째 삼각형과 K-5번째 삼각형의 변이다.이를 수식으로 만들면 아래와 같다.

```cpp
spiral[i] = spiral[i-1] + spiral[i-5];
```

여기에서는 i가 5 이상일때 만 커버가 가능하므로, 그 전의 값들은 직접 초기화해주었고, 4이하의 값이 들어왔을 때는 직접 해당 값들을 출력해준다.

```cpp
if(n < 5) {
    cout << ((n-1)/3)+1 << "\n";
    return 0;
}

for(int i = 0; i<5; i++) {
    spiral[i] = i/3 + 1;
}
// 위 처럼 쓰면 배열에는 순서대로 1 1 1 2 2 가 들어가게 된다.
```

`spiral[n-1]`에는 원하는 변의 최대 길이가 들어있다. 이 값의 크기가 N이 최대인 경우 int로 담을 수 없으므로, spiral의 자료형은 long으로 선언해주어야 한다. 

```cpp
cout << spiral[n-1] << "\n";
```

---

## 코멘트

예전에는 이걸 DP를 안쓰고 어떻게 풀려고 시도했을까... 비록 시간초과는 났었지만 일반항을 찾으려고 노력하다니... 대단한 과거의 나였군... ㅋㅋㅋㅋ

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int k = 0; k < t; k++) {
        int n;
        cin >> n;
        vector<long> spiral(n);
        
        if(n < 5) {
            cout << ((n-1)/3)+1 << "\n";
            continue;
        }
        
        for(int i = 0; i<5; i++) {
            spiral[i] = i/3 + 1;
        }
        
        for(int i = 5; i < n; i++) {
            spiral[i] = spiral[i-1] + spiral[i-5];
        }
        
        cout << spiral[n-1] << "\n";
    }
    return 0;
}
```