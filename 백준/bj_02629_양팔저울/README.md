# [백준] 2629 - 양팔저울

Category: 알고리즘
PublishDate: 2022년 3월 6일 오후 9:17
Tag: DP, 배낭
Visibility: Public
문제 번호: 2629

## 문제 링크

[https://www.acmicpc.net/problem/2629](https://www.acmicpc.net/problem/2629)

## 문제

양팔 저울과 몇 개의 추가 주어졌을 때, 이를 이용하여 입력으로 주어진 구슬의 무게를 확인할 수 있는지를 결정하려고 한다.

무게가 각각 1g과 4g인 두 개의 추가 있을 경우, 주어진 구슬과 1g 추 하나를 양팔 저울의 양쪽에 각각 올려놓아 수평을 이루면 구슬의 무게는 1g이다. 또 다른 구슬이 4g인지를 확인하려면 1g 추 대신 4g 추를 올려놓으면 된다.

구슬이 3g인 경우 아래 <그림 1>과 같이 구슬과 추를 올려놓으면 양팔 저울이 수평을 이루게 된다. 따라서 각각 1g과 4g인 추가 하나씩 있을 경우 주어진 구슬이 3g인지도 확인해 볼 수 있다.

[https://upload.acmicpc.net/ce5b29f5-9e03-473b-97db-ce9fd740fde2/-/preview/](https://upload.acmicpc.net/ce5b29f5-9e03-473b-97db-ce9fd740fde2/-/preview/)

<그림 1> 구슬이 3g인지 확인하는 방법 (1은 1g인 추, 4는 4g인 추, ●은 무게를 확인할 구슬)

<그림 2>와 같은 방법을 사용하면 구슬이 5g인지도 확인할 수 있다. 구슬이 2g이면 주어진 추를 가지고는 확인할 수 없다.

추들의 무게와 확인할 구슬들의 무게가 입력되었을 때, 주어진 추만을 사용하여 구슬의 무게를 확인 할 수 있는지를 결정하는 프로그램을 작성하시오.

[https://upload.acmicpc.net/883fb22a-7516-46e1-937d-2ddc4df94572/-/preview/](https://upload.acmicpc.net/883fb22a-7516-46e1-937d-2ddc4df94572/-/preview/)

<그림 2> 구슬이 5g인지 확인하는 방법

## 입력

첫째 줄에는 추의 개수가 자연수로 주어진다. 추의 개수는 30 이하이다. 둘째 줄에는 추의 무게들이 자연수로 가벼운 것부터 차례로 주어진다. 같은 무게의 추가 여러 개 있을 수도 있다. 추의 무게는 500g이하이며, 입력되는 무게들 사이에는 빈칸이 하나씩 있 다. 세 번째 줄에는 무게를 확인하고자 하는 구슬들의 개수가 주어진다. 확인할 구슬의 개수는 7이하이다. 네 번째 줄에는 확인하고자 하는 구슬들의 무게가 자연수로 주어지며, 입력되는 무게들 사이에는 빈 칸이 하나씩 있다. 확인하고자 하는 구슬의 무게는 40,000보다 작거나 같은 자연수이다.

## 출력

주어진 각 구슬의 무게에 대하여 확인이 가능하면 Y, 아니면 N 을 차례로 출력한다. 출력은 한 개의 줄로 이루어지며, 각 구슬에 대한 답 사이에는 빈칸을 하나씩 둔다.

## 조건

- 시간 제한 : 1초
- 메모리 제한 : 128MB

---

## 해설

추가 하나 추가로 입력될 때 마다 기존의 추들로 만들 수 있는 선택지에서 추가된 추를 통해 선택지가 늘어나므로, 다이나믹 프로그래밍을 통해 해결하면 적절한 문제이다. 

입력 과정에서 추의 무게를 vector에 순서대로 담아두고, 하나씩 뽑아서 만들 수 있는 경우를 확인해나간다. 
W라는 무게를 만들 수 있는 상황에서 A 무게의 추가 추가된다면, 만들 수 있는 경우는 아래와 같다.

1. W+A
2. W-A 또는 A-W (A > W 인 경우) ... W와 A의 차이
3. A (W는 빼고, A만 올리기)

만약 A 추를 추가하여 W+A 라는 무게를 만들었다면, 다음 번 입력인 B 무게의 추에 대해 동일하게 경우를 확인할 수 있다.

1. W+A+B
2. W+A-B 또는 B-(W+A) ... W+A와 B의 차이
3. B

모든 가능한 경우를 체크하여 DP 배열에 기록한 뒤, 확인하고자 하는 무게에 대해 만들 수 있었다면 Y, 없었다면 N을 출력하게 만들면 된다.

## 풀이

추의 무게를 저장할 벡터 `weight`와, 해당 무게를 만들 수 있는지를 기록할 2차원 배열 `dp`를 선언한다. 배열을 dp[X][Y]라 할 때, X번째 추가 추가되었을 때 Y라는 무게를 만들 수 있다면 true, 없다면 false를 저장한다. 즉, X번째 행은 1번째 ~ X번째 추를 활용하여 만들 수 있는 모든 무게에 대한 경우를 저장한다.

```cpp
int N, M, val;
vector<int> weight;
bool dp[31][40001]; // 가능하다면 true
```

해설에서 언급한 3가지 경우를 체크하기 위해 재귀함수 `available()` 을 정의하였다. 함수는 `idx`번째 추를 추가했을 때 `wgh`라는 무게를 만들 수 있는지 물어보는 것이며, 가능하다면 `dp[idx][wgh]`에 true를 저장해준다. 이때, `idx`가 추의 개수보다 커서(추 8개 중 9번째) 만들기 불가능하다면, 또는 이미 만들 수 있었던 무게라면 true를 저장하기 전에 return을 통해 함수를 종료한다.
이후, 현재 무게와 다음 추를 가지고 3가지 경우에 대해 `available()`함수를 호출해 무게를 구성할 수 있는지 확인한다.

```cpp
void available(int idx, int wgh) {
    if(idx > N || dp[idx][wgh]) return;
    
    dp[idx][wgh] = true;
    available(idx + 1, wgh + weight[idx]);
    available(idx + 1, abs(wgh - weight[idx]));
    available(idx + 1, wgh);
}
```

main 함수에서는 N개 만큼의 추의 무게를 순서대로 입력받아 weight 벡터에 저장한 뒤, `available(0, 0)`을 호출해 dp 배열을 채운다. 

```cpp
cin >> N;

for(int i = 0; i < N; i++) {
    cin >> val;
    weight.push_back(val);
}

available(0, 0);
```

dp배열을 모두 채운 뒤, 물어보는 무게에 대해 N번째 추를 추가한 경우에 해당 무게를 만들 수 있는지를 dp[N][weight]에서의 bool 값을 확인하여 출력한다.

```cpp
cin >> M;

for(int i = 0; i < M; i++) {
    cin >> val;
    
    if(dp[N][val]) cout << "Y ";
    else cout << "N ";
}
```

---

## 코멘트

오랜만에 알고리즘 문제풀이를 다시 하려나 되게 헷갈린다. 특히 DP를 생각해내는게 좀 어려웠던 것 같다. 역시 알고리즘은 꾸준히 열심히 해야해!

---

## 코드

```cpp
#include <iostream>
#include <vector>
    
using namespace std;

int N, M, val;
vector<int> weight;
bool dp[31][40001]; // 가능하다면 true

void available(int idx, int wgh) {
    if(idx > N || dp[idx][wgh]) return;
    
    dp[idx][wgh] = true;
    available(idx + 1, wgh + weight[idx]);
    available(idx + 1, abs(wgh - weight[idx]));
    available(idx + 1, wgh);
}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> val;
        weight.push_back(val);
    }
    available(0, 0);
    
    cin >> M;
    
    for(int i = 0; i < M; i++) {
        cin >> val;
        
        if(dp[N][val]) cout << "Y ";
        else cout << "N ";
    }
    
    return 0;
}
```

---

## 문제풀이를 위한 고민

처음에는 재귀 대신 현재 만들 수 있는 무게를 queue에 담아두는 방식으로 코드를 작성했다. 현재 추들에 대해 다음 추가 추가됐을 때 queue에서 값을 차례로 뽑아서 3개의 조건에 대해 계산하고, 만들 수 있는 무게를 다시 다른queue에 쭉 담아 그 다음 추에게 넘기는 방식을 사용하고자 했다. 그러나, 추 무게의 중복이나 기타 연산 처리에서 자꾸 꼬여서 DP를 이용해 푸는 방식으로 넘어왔다. 

DP 풀이에서 참고했습니다! 

[https://cocoon1787.tistory.com/360](https://cocoon1787.tistory.com/360)