# 신나는 함수 실행

문제 번호: 9184
알고리즘 분류: DP
푼 날짜: 2021년 2월 26일 오후 10:30

## 문제링크

[https://www.acmicpc.net/problem/9184](https://www.acmicpc.net/problem/9184)

## 문제

재귀 호출만 생각하면 신이 난다! 아닌가요?

다음과 같은 재귀함수 w(a, b, c)가 있다.

```
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

```

위의 함수를 구현하는 것은 매우 쉽다. 하지만, 그대로 구현하면 값을 구하는데 매우 오랜 시간이 걸린다. (예를 들면, a=15, b=15, c=15)

a, b, c가 주어졌을 때, w(a, b, c)를 출력하는 프로그램을 작성하시오.

## 입력

입력은 세 정수 a, b, c로 이루어져 있으며, 한 줄에 하나씩 주어진다. 입력의 마지막은 -1 -1 -1로 나타내며, 세 정수가 모두 -1인 경우는 입력의 마지막을 제외하면 없다.

## 출력

입력으로 주어진 각각의 a, b, c에 대해서, w(a, b, c)를 출력한다.

## 제한

- 50 ≤ a, b, c ≤ 50

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

규칙은 아래와 같다.

```
a, b, c 중 하나라도 0 이하 → 1
a, b, c 중 하나라도 20 초과 → w(20, 20, 20)
a < b < c → w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
그 외 → w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
```

간단한 경우인 w(2, 2, 2)에 대해 살펴보자. 편의상 w를 제외하였다.

```
(2, 2, 2) = (1, 2, 2) + (1, 1, 2) + (1, 2, 1) - (1, 1, 1)
          = (0, 2, 2) + (0, 1, 2) + (0, 2, 1) - (0, 1, 1)
					+ (0, 1, 2) + (0, 0, 2) + (0, 1, 1) - (0, 0, 1)
          + (0, 2, 1) + (0, 1, 1) + (0, 2, 0) - (0, 1, 0)
          -{(0, 1, 1) + (0, 0, 1) + (0, 1, 0) - (0, 0, 0)}
```

규칙에 따라서 세 항 중에서 0이 하나라도 포함되어있으면 1의 값을 갖게된다. 이를 출발점으로 하여 3차원 배열(벡터)를 쌓아올려 vector[a][b][c]까지 값을 만들면 원하는 결과를 얻을 수 있다.

## 풀이

a, b, c 세 값을 받아온 다음 세 수 중 하나라도 0보다 작으면 1을 출력하고, 20을 초과하면 a, b, c의 값을 20으로 만들어준다. 이때, a, b, c 값 자체가 변하므로, 출력 프롬프터(원래 a, b, c 값)을 미리 출력해준다. 그 후, a, b, c 값에 따라 3차원 벡터를 선언해준다.

```cpp
int a, b, c;
cin >> a >> b >> c;

if(a == -1 && b == -1 && c == -1) return 0;

cout << "w(" << a << ", " << b << ", " << c << ") = ";

if(a <= 0 || b <= 0 || c <= 0) {
    cout << 1 << '\n';
    continue;
}

if(a > 20 || b > 20 || c > 20) {
  a = 20;
  b = 20;
  c = 20;
}

vector<vector<vector<int>>> dp(a+1, vector<vector<int>>(b+1, vector<int>(c+1, 0)));
```

규칙에 따라서 3차원 벡터를 채워준다. 0이 포함되면 값에 1을 넣어주어 초깃값으로 삼고, 규칙에 따라 값을 쌓아올린다. 반복문을 다 돌고 나면 dp[a][b][c]에 원하는 결과가 들어있다.

```cpp
for(int i = 0; i <= a; i++) {
    for(int j = 0; j <= b; j++) {
        for(int k = 0; k <= c; k++) {
            if(i == 0 || j == 0 || k == 0) {
                dp[i][j][k] = 1;
            } else {
                if(i<j && j<k) {
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
                } else {
                dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
                }
            }
        }
    }
}
cout << dp[a][b][c] << '\n';

```

---

## 코멘트

`if(i<j && j<k)` 조건이 없어도 통과가 되더라... ㅋㅋㅋ 실수로 안넣고 통과됐는데, 문제 해설 작성하면서 알아차렸다. ㅋㅋㅋㅋㅋ 이게 ‘그외’ 규칙에 의해서 정의해주지 않더라도 어쩔 수 없이 통과되는 조건인가?

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
	
	while(true) {
    	int a, b, c;
        cin >> a >> b >> c;
	
	    if(a == -1 && b == -1 && c == -1) return 0;
	    
	    cout << "w(" << a << ", " << b << ", " << c << ") = ";
	    
	    if(a <= 0 || b <= 0 || c <= 0) {
            cout << 1 << '\n';
            continue;
	    }
	    
	    
	    if(a > 20 || b > 20 || c > 20) {
	        a = 20;
	        b = 20;
	        c = 20;
	    }
	    
	    vector<vector<vector<int>>> dp(a+1, vector<vector<int>>(b+1, vector<int>(c+1, 0)));
	    
	    for(int i = 0; i <= a; i++) {
	        for(int j = 0; j <= b; j++) {
	            for(int k = 0; k <= c; k++) {
	                if(i == 0 || j == 0 || k == 0) {
	                    dp[i][j][k] = 1;
	                } else {
	                    if(i<j && j<k) {
	                        dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
	                    } else {
	                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
	                    }
	                }
	            }
	        }
	    }
	    cout << dp[a][b][c] << '\n';
	}
	
	
	return 0;
}
```