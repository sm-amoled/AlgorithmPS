# 전깃줄

문제 번호: 2565
알고리즘 분류: DP, LIS
푼 날짜: 2021년 2월 25일 오후 10:41

## 문제링크

[https://www.acmicpc.net/problem/2565](https://www.acmicpc.net/problem/2565)

## 문제

두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.

예를 들어, <그림 1>과 같이 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄, A의 3번 위치와 B의 9번 위치를 잇는 전깃줄, A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든 전깃줄이 서로 교차하지 않게 된다.

![https://www.acmicpc.net/upload/images/i7Wn4h3qIiezi.jpg](https://www.acmicpc.net/upload/images/i7Wn4h3qIiezi.jpg)

전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때, 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 전깃줄의 개수는 100 이하의 자연수이다. 둘째 줄부터 한 줄에 하나씩 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호가 차례로 주어진다. 위치의 번호는 500 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다.

## 출력

첫째 줄에 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

이 문제를 처음 읽을 때 든 생각은 줄이 겹치지 않으려면 오름차순으로 정렬된 출발지에 대해서 도착지 역시 오름차순으로 정렬된 전선만 남으면 되겠다는 것이였다.

```
예시 입력 값
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6

출발지를 오름차순으로 정렬했을 때 
1 8
2 2
3 9
4 1
6 4
7 6
9 7
10 10

만약에 제거하고 남은 전깃줄들의 도착지가 오름차순이 된다면 전선들이 교차하지 않게된다. 최대한 많은 전선의 도착지가 오름차순이 된다면 최소한으로 전선을 제거할 수 있다.
2 2
6 4
7 6
9 7
10 10
→ 제거한 전선 수 : 3개
```

출발지에 대해 정렬하고, 도착지에 대해 최대 오름차순 개수를 구하면 이 문제의 답을 쉽게 구할 수 있다.

## 풀이

출발지에 대해 전선을 정렬했을 때 도착지도 함께 정렬되어야 하므로, 둘을 묶어둘 구조체와 정렬에 사용할 비교 함수를 만들어준다.

```cpp
struct line {
    int start, end;
};

bool compareLine(line a, line b) {
    return a.start < b.start;   
}
```

값을 입력받는다. 이 값들을 위에서 만든 비교 함수를 이용해 전선의 출발지에 대해 정렬해준다.

```cpp
t N;
cin >> N;
vector<line> lines(N);

for(int i = 0; i < N; i++) {
	  line temp;
	  cin >> temp.start >> temp.end;
	  lines[i] = temp;
}

sort(lines.begin(), lines.end(), compareLine);
```

LIS 알고리즘(증가하는 최장 부분 수열의 길이)을 이용해 오름차순의 길이를 구해주었다. 처음 길이 N에서 알고리즘을 통해 구한 오름차순의 최대 길이를 빼면 제거해야할 전선의 개수를 구할 수 있다. 이를 출력해주면 원하는 결과를 얻을 수 있다.

```cpp
vector<int> dp;
dp.push_back(lines[0].end);
for(auto x : lines) {
   if(dp.back() < x.end) {
       dp.push_back(x.end);
   } else {
       vector<int>::iterator point = lower_bound(dp.begin(), dp.end(), x.end);
       *point = x.end;
   }
}

cout << N - dp.size();
```

---

## 코멘트

뭔가 알고리즘 공부를 많이 하면 이런 기분일까..? 문제를 풀면서 오름차순? LIS? 라는 생각이 딱 들면서 문제를 풀었더니 정답이 나왔다. 도구를 잘 알아두는게 이렇게 중요하구나 라는 생각이 든다.

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line {
    int start, end;
};

bool compareLine(line a, line b) {
    return a.start < b.start;   
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	vector<line> lines(N);
	
	for(int i = 0; i < N; i++) {
	    line temp;
	    cin >> temp.start >> temp.end;
	    lines[i] = temp;
	}
	
	sort(lines.begin(), lines.end(), compareLine);
	
	vector<int> dp;
	dp.push_back(lines[0].end);
	for(auto x : lines) {
	   if(dp.back() < x.end) {
	       dp.push_back(x.end);
	   } else {
	       vector<int>::iterator point = lower_bound(dp.begin(), dp.end(), x.end);
	       *point = x.end;
	   }
	}
	
	cout << N - dp.size();
	return 0;
}
```