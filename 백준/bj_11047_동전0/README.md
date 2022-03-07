# 동전 0

문제 번호: 11047
알고리즘 분류: 그리디
푼 날짜: 2021년 3월 7일 오후 9:06

## 문제링크

[https://www.acmicpc.net/problem/11047](https://www.acmicpc.net/problem/11047)

## 문제

준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

## 출력

첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

입력받는 동전의 값들 중 가장 큰 값부터 차례대로 주어진 총 금액에서 최대한 많이 활용하면 필요한 동전의 개수를 줄일 수 있다.

## 풀이

우선 값들을 입력받는다. 값이 오름차순으로 주어지기 때문에, 뒤에서부터 값을 채워서 내림차순으로 값을 벡터에 저장해준다.

```cpp
int N, K;
cin >> N >> K;

vector<int> value(N);
for(int i = 1; i <= N; i++) {
    cin >> value[N-i];
}
```

`coinCount`에는 필요한 동전의 개수를 저장한다. for 반복문을 돌리면서 주어진 동전 중 가장 큰 값부터 가장 작은 값까지 현재 남은 총 금액(K)과 비교하면서 같거나 크면 `coinCount`에 1을 더하고, K의 값에서 해당 동전의 값만큼 빼주고 이 동전을 다시 한 번 비교해준다 (i에 1을 빼서 한 번 더 조건문 돌리기) 반복문을 모두 돌려주면 `coinCount`에 최소값이 들어있으므로, 이 값을 출력해주면 원하는 결과를 얻을 수 있다.

```cpp
int coinCount = 0;
for(int i = 0; i < N; i++) {
    if(K >= value[i]) {
        K -= value[i];
        coinCount++;
        i--;
    }
}

cout << coinCount;
```

---

## 코멘트

EG

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> value(N);
    for(int i = 1; i <= N; i++) {
        cin >> value[N-i];
    }
    
    int coinCount = 0;
    for(int i = 0; i < N; i++) {
        if(K >= value[i]) {
            K -= value[i];
            coinCount++;
            i--;
        }
    }
    
    cout << coinCount;
    
	return 0;
}
```