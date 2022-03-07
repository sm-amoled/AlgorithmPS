# 가장 긴 증가하는 바이토닉 부분 수열

문제 번호: 11054
알고리즘 분류: DP, 문자열
푼 날짜: 2021년 2월 21일 오후 7:17

## 문제링크

[https://www.acmicpc.net/problem/11054](https://www.acmicpc.net/problem/11054)

## 문제

수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, **30**, 25, 20}과 {10, 20, 30, **40**}, {**50**, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

## 출력

첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

수 하나를 기준으로 좌우로 수를 뽑았을 때, index 순서대로 오름차순 / 내림차순을 만들 수 있는 뽑은 수열의 길이의 최댓값을 묻는 문제이다. 예를 들어, 다음과 같이 바이토닉 수열을 만들 수 있다.

- **1** 5 **2** 1 4 **3 4 5** **2 1** → 바이토닉 수열의 최대 길이 : 7
- **1** 5 **2** 1 4 **3 4 5** → 바이토닉 수열의 최대 길이 : 5 ← 오름치순 또는 내림차순이 없을 수도 있음!
- **1 2 3 2 1** 7 → 바이토닉 수열의 최대 길이 : 5 ← 최대 숫자가 기준이 아님!

주어진 수열에서 왼쪽에서 오른쪽으로 갈 때 오름차순으로 만들 수 있는 조건을 따져 처음부터 해당 index까지에서 만들 수 있는 최대 오름차순 수열의 길이를 구하고, 왼쪽에서 오른쪽으로 갈 때 오름차순으로 만들 수 있는 조건을 따져 끝부터 해당 index까지에서 만들 수 있는 최대 오름차순 수열의 길이를 구하여 합치면 쉽게 해결할 수 있다.

## 풀이

아래 수열을 예시로 하여 해설에서의 해결 방법을 적용해보자.

```
input : 1 5 2 1 4 3 4 5 2 1

incre : 1 2 2 1 3 3 4 5 2 1
decre : 1 5 2 1 4 3 3 3 2 1
lengt : 1 6 3 1 6 5 6 7 3 1
```

좌→우 방향으로 오름차순인 increase와 좌←우 방향으로 오름차순(좌→우 내림차순)인 decrease의 합에서 1을 뺀 length는 해당 index를 좌우를 나누는 기준으로 선택했을 때 만들 수 있는 바이토닉 수열의 길이이다. 1을 빼는 이유는 자신이 2번 수열에 포함되기 때문!

각 i번째 원소 / N-1-i 번째 원소가 좌→우 / 우→좌 방향으로 오름차순 수열에 포함되면 최대 몇 번째 원소가 될 수 있는지를 구하여 increase / decrease에 저장한다. 뒤에서 앞으로 오는 decrease는 역순으로 저장해야 좌→우 방향으로 읽었을 때 내림차순으로 만들 수 있으므로 index가 뒤에서부터 온다. 이를 코드로 구현하면 아래와 같다. 

```cpp
for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) {
        if(input[j] < input[i]) {
            if(increase[i] < increase[j]+1) {
                increase[i] = increase[j] + 1;
            }
        }
        if(input[N-1-j] < input[N-1-i]) {
            if(decrease[N-1-i] < decrease[N-1-j] + 1) { 
                decrease[N-1-i] = decrease[N-1-j] + 1;
            }
        }
    }
}
```

increase와 decrease의 같은 index간의 합 중 가장 큰 값에서 1을 뺀 값이 원하는 가장 긴 바이토닉 수열의 길이이다. 이 값을 출력하면 원하는 결과를 얻을 수 있다.

```cpp
int max = 0;
for(int i = 0; i < N; i++) {
    increase[i] = increase[i]+decrease[i];
    max = (max > increase[i])? max : increase[i];
}

cout << max - 1;
```

---

## 코멘트

[https://sihyungyou.github.io/baekjoon-11054/](https://sihyungyou.github.io/baekjoon-11054/) 여기에서 도움을 얻었다. 어렵군... 어려워...

## 고민

처음에는 가장 큰 값을 잡고 좌우로 오름/내림차순을 돌리려고 했는데, 이 방법은 해결책이 아니더라. 위에 예시를 든 것 처럼 가장 큰 값이 선택의 기준이 되면 최댓값을 못갖는 경우가 생겼었다.

그 다음에는 좌/우로 LDS 알고리즘을 따로 적용해서 각 길이를 구하려고 시도했었다. 이 방법의 문제는, 어떤 원소를 좌우로 나누는 기준점으로 골라야 LDS를 적용했을 때 정확한 원소 길이를 구할 수 있는지를 알 수 없다는 것이였다. 

그래서 검색에서 위 블로그의 도움을 받아 문제를 해결할 수 있었다. 고통스러웠다. ㅋㅋㅋ. 자꾸 검색을 너무 쉽게 하는 것 같은 느낌이 들기도 하는데, LDS 알고리즘의 시간 복잡도가 오래 걸리는 버전을 사용해야 한다는 것을 놓쳤던 것 같다. 나는 O(n log n) 방법밖에 모른단 말야... ㅋㅋㅋㅋ

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    // 입력    
    vector<int> input(N);
    int temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        input[i] = temp;
    }
    
    // DP
    vector<int> increase(N, 1);
    vector<int> decrease(N, 1);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(input[j] < input[i]) {
                if(increase[i] < increase[j]+1) {
                    increase[i] = increase[j] + 1;
                }
            }
            if(input[N-1-j] < input[N-1-i]) {
                if(decrease[N-1-i] < decrease[N-1-j] + 1) { 
                    decrease[N-1-i] = decrease[N-1-j] + 1;
                }
            }
        }
    }
    
    int max = 0;
    for(int i = 0; i < N; i++) {
        increase[i] = increase[i]+decrease[i];
        max = (max > increase[i])? max : increase[i];
    }
    
    cout << max - 1;
    return 0;
}
```