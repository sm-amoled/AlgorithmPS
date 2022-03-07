# 가장 큰 증가 부분 수열

문제 번호: 11055
알고리즘 분류: DP
푼 날짜: 2021년 2월 21일 오후 7:51

## 문제링크

[https://www.acmicpc.net/problem/11055](https://www.acmicpc.net/problem/11055)

## 문제

수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {**1**, 100, **2**, **50**, **60**, 3, 5, 6, 7, 8} 이고, 합은 113이다.

## 입력

첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

## 출력

첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

주어진 입력값 중 k 를 다룬다고 할 때, k 보다 먼저 입력된 (앞에 있는)값 들 중 k보다 작은 값들을 찾는다. 해당 값들까지의 합 중에서 가장 큰 값에 k를 더해 k의 합으로 저장한다. 이를 모든 원소에 대해 반복해주면 원하는 결과를 얻을 수 있다.

## 풀이

이를 코드로 옮기면 아래와 같다. 입력값 input[i] 가 이전에 입력받은 값 input[k]보다 크다면 부분수열을 만들 수 있으므로, sum[k]를 가져와 input[i]를 더해 sum[i]로 만든다. 이때, sum[k] 중 가장 큰 값에 input[i]를 더해주어야 가장 큰 합을 구할 수 있다.

```cpp
vector<int> sum(N);

for(int i = 0; i < N; i++) {
    int max = 0;
    for(int k = 0; k < i; k++) {
        if(input[i] > input[k]) {
            max = (max > sum[k])? max:sum[k];
        }
    }
    sum[i] = max + input[i];
}
```

가장 큰 값을 구하기 위해 maxSum 을 추가해, 반복문과 함께 찾아주었다.

```cpp
vector<int> sum(N);
int maxSum = 0;
for(int i = 0; i < N; i++) {
    int max = 0;
    for(int k = 0; k < i; k++) {
        if(input[i] > input[k]) {
            max = (max > sum[k])? max:sum[k];
        }
    }
    sum[i] = max + input[i];
    if(sum[i] > maxSum) {
        maxSum = sum[i];
    }
}
cout << maxSum;
```

---

## 코멘트

EZ!!!!

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
    for(int i = 0; i < N; i++) cin >> input[i];
    
    // DP
    vector<int> sum(N);
    int maxSum = 0;
    for(int i = 0; i < N; i++) {
        int max = 0;
        for(int k = 0; k < i; k++) {
            if(input[i] > input[k]) {
                max = (max > sum[k])? max:sum[k];
            }
        }
        sum[i] = max + input[i];
        if(sum[i] > maxSum) {
            maxSum = sum[i];
        }
    }
    cout << maxSum;
    
    return 0;
}
```