# 동전 2

문제 번호: 2294
알고리즘 분류: DP
푼 날짜: 2021년 2월 22일 오후 10:55

## 문제링크

[https://www.acmicpc.net/problem/2294](https://www.acmicpc.net/problem/2294)

## 문제

n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

## 입력

첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

## 출력

첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

dp[i] 에는 주어진 coin 값들을 이용해 i 값을 만들 때 동전을 최소한으로 사용하는 개수가 저장된다. k에 해당하는 동전 값에 대해서 d[i]는 d[i-k]+1의 값을 저장하게 되고, 이 k 값들로 접근할 수 있는 d[i-k] 중에서 가장 작은 값을 저장하면 최소한으로 사용하는 값을 갖고갈 수 있다. 

## 풀이

중복 입력과 무작위 순서의 입력을 유일한 오름차순으로 만들어 주기 위해 `sort`와 `unique`를 사용해주었다.

```cpp
for (int i = 0; i < N; i++) {
	cin >> coin[i];
}

sort(coin.begin(), coin.end());
unique(coin.begin(), coin.end());
```

K까지의 값에 대해 최소한의 동전 개수를 저장할 dp 벡터를 선언해주었다. 크기는 0~K까지의 index를 가질 수 있도록 K+1로 만들었고, 최소값을 비교하기 때문에 가장 작은 1로도 만들 수 없는 개수 중 가장 작은 값인 K+1을 초기값으로 지정하였다. 그리고, 중간 값인 i와 동전의 값이 같은 경우 1로 만들어줄 수 있도록 하기위해 dp[0]을 0으로 지정해주었다.  

```cpp
vector<int> dp(K+1, K+1);
dp[0] = 0;
```

1~K의 값 i에 대해, dp[i]를 순차적으로 구한다. coin 값들 중에서 i보다 작거나 같은 값에 대해 `dp[i]`는 `dp[i-k]+1`을 저장한다. 그러나, `dp[i-k]+1`중 가장 작은 값을 선택하여야 하기 때문에, for문을 돌며 가능한 모든 동전의 값을 비교해준다.

```cpp
for (int i = 1; i < K+1; i++) {
      for(auto x : coin) {
          if(x <= i) {
              dp[i] = (dp[i] < dp[i-x]+1)? dp[i] : dp[i-x] + 1;
          } else {
              break;
          }
      }
}
```

만약 만들기 불가능한 수라면 dp[K]의 값이 변하지 않았으므로 K+1로 남아있다. 만약 dp[K]의 값이 K+1이라면 -1을 출력하고, 아니라면 dp[K]를 출력한다.

```cpp
cout << ((dp.back() == K+1)? -1:dp.back());
```

---

## 코멘트

-1을 출력해야한다는 말을 못봐서 고생했다... ㅋㅋㅋㅋ

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	vector<int> coin(N);
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	
	sort(coin.begin(), coin.end());
	unique(coin.begin(), coin.end());
    
	vector<int> dp(K+1, K+1);
	dp[0] = 0;
	for (int i = 1; i < K+1; i++) {
        for(auto x : coin) {
            if(x <= i) {
                dp[i] = (dp[i] < dp[i-x]+1)? dp[i] : dp[i-x] + 1;
            } else {
                break;
            }
        }
	}
    
	cout << ((dp.back() == K+1)? -1:dp.back());
	return 0;
}
```