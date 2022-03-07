# LCS

문제 번호: 9251
알고리즘 분류: DP, LCS
푼 날짜: 2021년 2월 27일 오후 1:18

## 문제링크

[https://www.acmicpc.net/problem/9251](https://www.acmicpc.net/problem/9251)

## 문제

LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

## 입력

첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

## 출력

첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

이 문제는 LCS 알고리즘을 이용하면 쉽게 해결이 가능하다. 애초에 그래서 문제 제목도 LCS겠지... ㅋㅋㅋㅋ

2차원 배열(나는 벡터)를 만들어서 해당 문자까지의 최장 공통 부분 수열의 길이를 구하면 해결할 수 있다. 문제에서 예시로 둔 ACAYKP 와 CAPCAK 를 예시로 설명을 해보자면 아래와 같다. 가로 세로가 겹치는 부분의 숫자는 각 문자열의 해당 문자까지만 판단했을 때, LCS의 길이를 말한다.

```
  A C A Y K P
C 0 **1** 1 1 1 1 ← C가 포함되면, 가능한 문자열의 크기는 1 → C가 포함된 문자열에서 LCS는 1
A **1** 1 **2** 2 2 2 ← A가 포함되면, A가 추가되었을 때의 LCS를 구하여 값을 채워준다.  
P 1 1 2 2 2 **3**
C 1 **2** 2 2 2 3
A **1** 2 **3** 3 3 3
K 1 2 3 3 **4** 4
```

위의 표에서 알 수 있는 것은 `dp[i][j]`에 대해 만약 가로/세로의 문자가 다르다면 `dp[i-1][j]`, `dp[i][j-1]` 중 큰 값이 `dp[i][j]`가 된다는 것이고, 같다면 `dp[i-1][j-1]+1`이 `dp[i][j]`가 된다는 것이다. 같은 경우에는 `dp[i-1][j-1]`에서 해당 문자가 추가되면서 값이 만들어지기 때문에, `dp[i][j-1]`이 아닌 `dp[i-1][j-1]`에서 값을 받아와야 한다.

## 풀이

`dp[i-1][j-1]`의 값에 접근해야 하기 때문에, 첫 행과 첫 열에 0을 넣어주었다. 이를 코드로 구현하면 아래와 같다.

```
  0 A C A Y K P
0 0 0 0 0 0 0 0
C 0 0 **1** 1 1 1 1 ← C가 포함되면, 가능한 문자열의 크기는 1 → C가 포함된 문자열에서 LCS는 1
A 0 **1** 1 **2** 2 2 2 ← A가 포함되면, A가 추가되었을 때의 LCS를 구하여 값을 채워준다.  
P 0 1 1 2 2 2 **3**
C 0 1 **2** 2 2 2 3
A 0 **1** 2 **3** 3 3 3
K 0 1 2 3 3 **4** 4
```

```cpp
string A, B;
cin >> A >> B;

A = '0' + A;
B = '0' + B;

vector<vector<int>> dp(A.size(), vector<int> (B.size(), 0));
```

그 다음, 규칙에 따라 DP 벡터를 채우고 마지막 원소를 출력하면 원하는 결과를 얻을 수 있다.

```cpp
for(int i = 1; i < A.size(); i++) {
    for(int j = 1; j < B.size(); j++) {
        if(A[i] == B[j]) {
            dp[i][j] = dp[i-1][j-1] + 1;
        } else {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
}

cout << dp[A.size()-1][B.size()-1];
```

---

## 코멘트

LCS도 이제 쉽게 해결할 수 있겠구만!!

## 고민

난 처음에 1차원 배열에 넣고, 각 원소까지를 반복문으로 돌리면서 비교하려 했는데, 시간 복잡도가 O(m^2 x n)이 되더라구. 따흑... 역시 기본 개념은 공부를 하고 문제를 풀어야하나봐.

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string A, B;
	cin >> A >> B;
	
	A = '0' + A;
	B = '0' + B;
	
	vector<vector<int>> dp(A.size(), vector<int> (B.size(), 0));
	
	for(int i = 1; i < A.size(); i++) {
	    for(int j = 1; j < B.size(); j++) {
	        if(A[i] == B[j]) {
	            dp[i][j] = dp[i-1][j-1] + 1;
	        } else {
	            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	        }
	    }
	}
	
  cout << dp[A.size()-1][B.size()-1];
	return 0;
}
```