# 파일 합치기

문제 번호: 11066
알고리즘 분류: DP
푼 날짜: 2021년 2월 27일 오후 8:24

## 문제링크

[https://www.acmicpc.net/problem/11066](https://www.acmicpc.net/problem/11066)

## 문제

소설가인 김대전은 소설을 여러 장(chapter)으로 나누어 쓰는데, 각 장은 각각 다른 파일에 저장하곤 한다. 소설의 모든 장을 쓰고 나서는 각 장이 쓰여진 파일을 합쳐서 최종적으로 소설의 완성본이 들어있는 한 개의 파일을 만든다. 이 과정에서 두 개의 파일을 합쳐서 하나의 임시파일을 만들고, 이 임시파일이나 원래의 파일을 계속 두 개씩 합쳐서 소설의 여러 장들이 연속이 되도록 파일을 합쳐나가고, 최종적으로는 하나의 파일로 합친다. 두 개의 파일을 합칠 때 필요한 비용(시간 등)이 두 파일 크기의 합이라고 가정할 때, 최종적인 한 개의 파일을 완성하는데 필요한 비용의 총 합을 계산하시오.

예를 들어, C1, C2, C3, C4가 연속적인 네 개의 장을 수록하고 있는 파일이고, 파일 크기가 각각 40, 30, 30, 50 이라고 하자. 이 파일들을 합치는 과정에서, 먼저 C2와 C3를 합쳐서 임시파일 X1을 만든다. 이때 비용 60이 필요하다. 그 다음으로 C1과 X1을 합쳐 임시파일 X2를 만들면 비용 100이 필요하다. 최종적으로 X2와 C4를 합쳐 최종파일을 만들면 비용 150이 필요하다. 따라서, 최종의 한 파일을 만드는데 필요한 비용의 합은 60+100+150=310 이다. 다른 방법으로 파일을 합치면 비용을 줄일 수 있다. 먼저 C1과 C2를 합쳐 임시파일 Y1을 만들고, C3와 C4를 합쳐 임시파일 Y2를 만들고, 최종적으로 Y1과 Y2를 합쳐 최종파일을 만들 수 있다. 이때 필요한 총 비용은 70+80+150=300 이다.

소설의 각 장들이 수록되어 있는 파일의 크기가 주어졌을 때, 이 파일들을 하나의 파일로 합칠 때 필요한 최소비용을 계산하는 프로그램을 작성하시오.

## 입력

프로그램은 표준 입력에서 입력 데이터를 받는다. 프로그램의 입력은 T개의 테스트 데이터로 이루어져 있는데, T는 입력의 맨 첫 줄에 주어진다.각 테스트 데이터는 두 개의 행으로 주어지는데, 첫 행에는 소설을 구성하는 장의 수를 나타내는 양의 정수 K (3 ≤ K ≤ 500)가 주어진다. 두 번째 행에는 1장부터 K장까지 수록한 파일의 크기를 나타내는 양의 정수 K개가 주어진다. 파일의 크기는 10,000을 초과하지 않는다.

## 출력

프로그램은 표준 출력에 출력한다. 각 테스트 데이터마다 정확히 한 행에 출력하는데, 모든 장을 합치는데 필요한 최소비용을 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 256MB

---

## 해설

행이 구간의 시작 원소 / 열이 구간의 끝 원소를 가리키는 DP 2차원 벡터를 만들어 차례대로 채워가면 원하는 결과를 얻을 수 있다.

## 풀이

chapter에 K만큼의 값을 받아 저장한다. 계산의 편의를 위해 가장 앞 원소에는 0을 담아주었다.

```cpp
int K;
cin >> K;

vector<int> chapter(K+1);
vector<int> sum(K+1, 0);

for(int i = 1; i <= K; i++) {
    cin >> chapter[i];
    sum[i] = sum[i-1] + chapter[i];
}
```

DP를 하기 위해 2차원 벡터를 선언해주었다. `dp[i][j]`는 i~j 까지의 구간에 대한 cost를 나타낸다.

초깃값으로 `dp[i][i]` 값은 i번째 값 하나에 대한 cost이므로,  `chapter[i]`와 같은 값을 갖는다. 길이가 길면 아직 정보가 부족해 값을 구할 수 없으므로, 길이가 1인 구간부터 차례대로 올라가면서 dp 값을 찾아준다. 길이와 시작 값을 이용해 2중 반복문을 돌리면서 `dp[start][end]`에 대한 값을 차례대로 구하면 된다. `dp[start][end]`값을 만드는 방법은 start ~ end 중간에 mid 값에서 2등분하여 start ~ mid / mid+1 ~ end 로 구간을 나누어 두 구간을 더했을 때 만들 수 있다. `dp[start][end]` 는 `dp[start][mid] + dp[mid+1][end]` + `chapter[start ~ end]` 와 같다. (chapter를 더하는 이유는 해당 구간을 만드는데 사용되는 cost값을 더해주기 위해서이다.) mid값을 start+1 ~ end-1 구간에서 움직이면서 최소인 `dp[start][end]`를 저장해주면 최적화된 값을 계속 저장할 수 있다.

```cpp
vector<vector<int>> dp(K+1, vector<int>(K+1, 0));
  
for(int length = 1; length < K; length++) {
    for(int start = 1; start+length <= K; start++) {
        int end = start+length;
        dp[start][end] = INT_MAX;
        
        for(int mid = start; mid < end; mid++) {
            dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid+1][end] + sum[end] - sum[start-1]);
        }
    }
}

cout << dp[1][K] << '\n';
```

---

## 코멘트

이 문제는 나한테 어려웠다. ㅠㅠㅠ. 아래 블로그의 게시글을 통해 겨우 공부해서 문제를 풀었다. 2차원 벡터로 만들면 되겠다는 생각을 못했는데 말이야.. ㅋㅋㅋ

[https://js1jj2sk3.tistory.com/3](https://js1jj2sk3.tistory.com/3)

## 고민

처음에는 문제를 잘못읽어서 연속된 값 끼리만 합칠 수 있는지 모르고, cost가 최소한이 될 수 있는 방법을 찾고자 하였다. 이를 위해 입력 값들을 역순으로 sort하여 stack에서 최소인 값 끼리만 더하면서 결과를 만들었다. 근데 연속된 값 끼리만 할 수 있다고 하더라구.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool reverse(int a, int b) {
    return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	
	while(T--) {
	    int K;
	    cin >> K;
	    
	    vector<int> chapter(K);
	    for(int i = 0; i < K; i++) cin >> chapter[i];
	    
	    sort(chapter.begin(), chapter.end(), greater<int>());
	    
	    long result = 0;
	    
	    while(chapter.size() > 1) {
	        int pointer = chapter.size()-1;
	        int sumedValue;
	        
	        chapter[pointer-1] += chapter[pointer];
	        sumedValue = chapter[pointer-1];
	        result += sumedValue;
	        
	        chapter.pop_back();
	        
	        while(--pointer >= 1 && chapter[pointer-1] < sumedValue) {
	            chapter[pointer] = chapter[pointer-1];
	        }
	        
	        chapter[pointer] = sumedValue;
	        
	        cout << result << " : ";
	        for(auto x : chapter) {
	            cout << x << " ";
	        } cout << '\n';
	    }
	    
	    cout << result << '\n';
	}
	
	return 0;
}
```

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	
	while(T--) {
	    int K;
	    cin >> K;
	    
	    vector<int> chapter(K+1);
	    vector<int> sum(K+1, 0);
	    
	    for(int i = 1; i <= K; i++) {
	        cin >> chapter[i];
	        sum[i] = sum[i-1] + chapter[i];
	    }
	    
	    vector<vector<int>> dp(K+1, vector<int>(K+1, 0));
        
	    for(int length = 1; length < K; length++) {
	        for(int start = 1; start+length <= K; start++) {
	            int end = start+length;
	            dp[start][end] = INT_MAX;
	            
	            for(int mid = start; mid < end; mid++) {
	                dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid+1][end] + sum[end] - sum[start-1]);
	            }
	        }
	    }
	    cout << dp[1][K] << '\n';
    }
	
	return 0;
}
```