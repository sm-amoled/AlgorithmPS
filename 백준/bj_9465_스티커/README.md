# 스티커

문제 번호: 9465
알고리즘 분류: DP
푼 날짜: 2021년 2월 8일 오후 8:55

## 문제링크

[https://www.acmicpc.net/problem/9465](https://www.acmicpc.net/problem/9465)

## 문제

상근이의 여동생 상냥이는 문방구에서 스티커 2n개를 구매했다. 스티커는 그림 (a)와 같이 2행 n열로 배치되어 있다. 상냥이는 스티커를 이용해 책상을 꾸미려고 한다.

상냥이가 구매한 스티커의 품질은 매우 좋지 않다. 스티커 한 장을 떼면, 그 스티커와 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없게 된다. 즉, 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없게 된다.

![https://www.acmicpc.net/upload/images/sticker.png](https://www.acmicpc.net/upload/images/sticker.png)

모든 스티커를 붙일 수 없게된 상냥이는 각 스티커에 점수를 매기고, 점수의 합이 최대가 되게 스티커를 떼어내려고 한다. 먼저, 그림 (b)와 같이 각 스티커에 점수를 매겼다. 상냥이가 뗄 수 있는 스티커의 점수의 최댓값을 구하는 프로그램을 작성하시오. 즉, 2n개의 스티커 중에서 점수의 합이 최대가 되면서 서로 변을 공유 하지 않는 스티커 집합을 구해야 한다.

위의 그림의 경우에 점수가 50, 50, 100, 60인 스티커를 고르면, 점수는 260이 되고 이 것이 최대 점수이다. 가장 높은 점수를 가지는 두 스티커 (100과 70)은 변을 공유하기 때문에, 동시에 뗄 수 없다.

## 입력

첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 n (1 ≤ n ≤ 100,000)이 주어진다. 다음 두 줄에는 n개의 정수가 주어지며, 각 정수는 그 위치에 해당하는 스티커의 점수이다. 연속하는 두 정수 사이에는 빈 칸이 하나 있다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

## 출력

각 테스트 케이스 마다, 2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최댓값을 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

2차원 벡터를 DP로 두고, dp의 각 원소에 대해 해당 행과 열을 갖는 스티커가 무조건 선택될 때, 해당 열까지 선택할 수 있는 방법 중 가장 최대점수를 받는 방법을 DP에 저장한다. 각 테스트 케이스에 대해 Max값을 비교, 저장하여 Max를 출력한다.

## 풀이

각 스티커를 선택했을 때의 최댓값을 각각 구하기 위해서 DP를 위한 벡터를 2차원 백터로 선언해준다. 

K번째 스티커를 뽑는다고 했을 때, 최대로 되는 방법을 선택하는 경우는 2가지 방법이 있다. 여기에서 A, B까지의 방법이 각각이 뽑힌 경우에서 최대라는 가정을 하면,

1. A를 뽑은 다음에 K-1열을 뛰어넘고 K를 뽑기
2. B를 뽑은 다음에 k를 뽑기

```
... ] 0 0 K
... ] A B 0
```

이를 코드로 옮기면 아래와 같다. 두 경우 중에서 최댓값이 되는 경우를 선택하면 된다. 

```cpp
dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
dp[1][i] = sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
maxValue = (maxValue > max(dp[0][i], dp[1][i]))? maxValue:max(dp[0][i], dp[1][i]);
```

i번째 열에서 i-2번째 열까지 참조를 하므로, i는 2보다 커야한다. N이 2보다 작은 경우에 대해서는 예외처리를 해주면 된다. 

끝까지 DP를 채운 뒤에 maxValue를 출력해주면 원하는 결과를 얻을 수 있다.

---

## 코멘트

이건 고민을 좀 많이 했는데, 어거지로 되는 코드보다는 깔끔한 DP 코드로 풀리는 풀이가 맞는 것 같아서 1차원 DP를 쓰는 방법을 그만두고 2차원 DP를 사용하여 해결하였다. 

## 고민

처음에는 1차원 벡터 dp를 쓰면서 i번째 열에서의 최댓값만을 이용해 구하려고 했는데, 그렇게 할 경우에는 아래의 반례를 통과하지 못하더라. 이게 통과할 수 없는 이유는 내가 선택하지 않은 경로에 최댓값이 숨어있을 수 있다는거야.  그래서 이걸 없애는 시도를 해봤는데, 그래도 자꾸 결과는 틀리다고 나오네. 흚... 이렇게 짜다보니 내 코드가 섹시하지 않다는 생각이 들어서 다른 사람들이 푼 코드에서 힌트를 얻으려고 다녀보니, dp도 2차원 벡터를 사용하더라고. 

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T; 
    cin >> T;
    for(int k = 0; k < T; k++) {
        
        int N;
        cin >> N;
        vector<vector<int>> sticker(2,vector<int>(N, 0));
        vector<int> dp(N);
        
        for(int i = 0; i < N; i++) {
            cin >> sticker[0][i];
        }
        for(int i = 0; i < N; i++) {
            cin >> sticker[1][i];
        }
        
        if(N == 1) {
            cout << max(sticker[0][0], sticker[1][0]);  
            continue;
        } else if (N == 2) {
            cout << max(sticker[0][0] + sticker[1][1], sticker[1][0] + sticker[0][1]);  
            continue;
        }
        
        // DP
        bool selectT;
        dp[0] = (sticker[0][0] > sticker[1][0])? sticker[0][0]:sticker[1][0];
        
        if(sticker[0][0]+sticker[1][1] > sticker[0][1]+sticker[1][0]) {
            dp[1] = sticker[0][0] + sticker[1][1];
            selectT = false;
        } else {
            dp[1] = sticker[0][1] + sticker[1][0];
            selectT = true;
        }
        
        int a, b;
        bool jump = false;
        for(int i = 2; i < N; i++) {
            
            a = (selectT)? 0:1;
            b = (selectT)? 1:0;
        
            if(jump) {
                if(sticker[a][i-1]+sticker[b][i] > sticker[b][i-1]+sticker[a][i]) {
                    dp[i] = dp[i-3] + sticker[a][i-1]+sticker[b][i];
                    selectT = (b == 0)? true:false;
                } else {
                    dp[i] = dp[i-3] + sticker[b][i-1]+sticker[a][i];
                    selectT = (a == 0)? true:false;
                }
                
                jump = false;
                continue;
            }
            
            if(sticker[a][i-1]+sticker[b][i] < sticker[a][i]) {
                dp[i] = dp[i-2] + sticker[a][i];
                jump = true;
            } else {
                dp[i] = dp[i-1] + sticker[b][i];
                selectT = !selectT;
            }
            
            
        }
        
        cout << dp[N-1] << "\n";
    }   
    return 0;
}
```

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T; 
    cin >> T;
    for(int k = 0; k < T; k++) {
        
        int N;
        cin >> N;
        vector<vector<int>> sticker(2,vector<int>(N, 0));
        vector<vector<int>> dp(2,vector<int>(N));

        for(int i = 0; i < N; i++) {
            cin >> sticker[0][i];
        }
        for(int i = 0; i < N; i++) {
            cin >> sticker[1][i];
        }
        
        if(N == 1) {
            cout << max(sticker[0][0], sticker[1][0]);  
            continue;
        } else if (N == 2) {
            cout << max(sticker[0][0] + sticker[1][1], sticker[1][0] + sticker[0][1]);  
            continue;
        }

        // DP
        int maxValue = 0;
        
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        maxValue = (maxValue > max(dp[0][0], dp[1][0]))? maxValue:max(dp[0][0], dp[1][0]);
        
        dp[0][1] = dp[1][0] + sticker[0][1];
        dp[1][1] = dp[0][0] + sticker[1][1];
        maxValue = (maxValue > max(dp[0][1], dp[1][1]))? maxValue:max(dp[0][1], dp[1][1]);
        
        for(int i = 2; i < N; i++) {
            dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
            maxValue = (maxValue > max(dp[0][i], dp[1][i]))? maxValue:max(dp[0][i], dp[1][i]);
        }
        
        cout << maxValue << "\n";
    }   
    return 0;
}
```