# 스타트와 링크

문제 번호: 14889
알고리즘 분류: 백 트래킹
푼 날짜: 2021년 3월 7일 오후 6:52

## 문제링크

[https://www.acmicpc.net/problem/14889](https://www.acmicpc.net/problem/14889)

## 문제

오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.

BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.

N=4이고, S가 아래와 같은 경우를 살펴보자.

```
ij   1    2    3    4
1         1    2    3
2    4         5    6
3    7    1         2
4    3    4    6    
```

예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.

- 스타트 팀: S + S = 1 + 4 = 5

    12

    21

- 링크 팀: S + S = 2 + 5 = 7

    34

    43

1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.

- 스타트 팀: S + S = 2 + 7 = 9

    13

    31

- 링크 팀: S + S = 6 + 4 = 10

    24

    42

축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 위의 예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.

## 입력

첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수)이 주어진다. 둘째 줄부터 N개의 줄에 S가 주어진다. 각 줄은 N개의 수로 이루어져 있고, i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.

## 출력

첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 512MB

---

## 해설

모든 경우에 대해 탐색하여 결과가 최소인 값을 출력해주면 된다. 

## 풀이

아래의 변수와 벡터를 전역변수로 선언하여 모든 함수에서 접근 가능하도록 해주었다. `stat`에는 능력치가 저장되고, `start`, `link`에는 각 팀의 멤버가 저장된다.

```cpp
int minValue = 1000000;
int N, stat[20][20];
vector<int> start(10, 0);
vector<int> link(10, 0);
```

start팀을 만드는 함수로 `team`을 사용하였다. 이전에 선택한 멤버와, 이번에 선택할 사람이 start 팀의 몇번째 멤버인지를 인자로 전달한다. 여기에서 N/2명의 멤버를 선택해준다.

```cpp
void team(int memberBefore, int memberIndex) {
   for(int i = memberBefore+1; i < N; i++) {
        start[memberIndex] = i;
        team(i, memberIndex+1);
    }
}
```

이 재귀함수의 종료 조건은 팀 멤버를 N/2 명을 모두 모았을 때이다. N/2 명이  start 팀에 모두 모이면 남은 사람들로 link 팀을 만들고, 양 팀의 능력치 총 합을 구해 그 차이를 구한다. 이 값이 현재 나온 값 중에 최소인지를 확인하고, 다음 팀 멤버 구성을 찾아간다. 이를 코드로 옮기면 아래와 같다. 멤버의 수가 N/2명을 채운 경우에, `akeLinkTeam()`에서 남은 사람들로 link 팀을 만들어 link 벡터에 저장한다. `getTeamPoint()`에서 start 팀과 link 팀의 능력치 합을 구하고, 그 차이를 result에 저장한다. 만약 이 값이 현재 나온 값 중에 최소라면 minValue에 저장한다.

```cpp
void team(int memberBefore, int memberIndex) {
    if(memberIndex >= N/2) {
        makeLinkTeam();
        
        int result = getTeamPoint(start) - getTeamPoint(link);
        result = (result > 0)? result:0-result;
        
        minValue = (result < minValue)? result : minValue;
        return;
    }
    
    for(int i = memberBefore+1; i < N; i++) {
        start[memberIndex] = i;
        team(i, memberIndex+1);
    }
}
```

`makeLinkTeam()`에서는 start 팀의 멤버를 보고, link 팀을 구성한다.

```cpp
void makeLinkTeam() {
    int startIndex = 0;
    int linkIndex = 0;
    
    for(int i = 1; i <= N; i++) {
        if(start[startIndex] == i) {
            startIndex++;
        } else {
            link[linkIndex] = i;
            linkIndex++;
        } 
    }
}
```

`getTeamPoint(team)`에서는 입력된 team의 능력치의 총 합을 구한다. 

```cpp
int getTeamPoint(vector<int> team) {
    int sum = 0;
    
    for(int first = 0; first < N/2; first++) {
        for(int second = 0; second < N/2; second++) {
            sum += stat[team[first]-1][team[second]-1];
        }
    }
    
    return sum;
}
```

main 함수에서 아래 두 줄의 코드를 실행시키면 원하는 결과를 얻을 수 있다. 

```cpp
team(0, 0);
cout << minValue;
```

---

## 코멘트

백트래킹 문제는 뭔가 풀면서 느낌이 “이렇게 만들면 분명히 비효율적일 것 같은데... 이래도 괜찮을까...??? 시간초과 날 것 같은데....???”라는 생각이 든다. 근데 제출해보면 맞는 걸 보니, 일부러 시간을 넉넉하게 주는 것 같기도 해. 

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int minValue = 1000000;
int N, stat[20][20];
vector<int> start(10, 0);
vector<int> link(10, 0);

void makeLinkTeam() {
    int startIndex = 0;
    int linkIndex = 0;
    
    for(int i = 1; i <= N; i++) {
        if(start[startIndex] == i) {
            startIndex++;
        } else {
            link[linkIndex] = i;
            linkIndex++;
        } 
    }
}

int getTeamPoint(vector<int> team) {
    int sum = 0;
    
    for(int first = 0; first < N/2; first++) {
        for(int second = 0; second < N/2; second++) {
            sum += stat[team[first]-1][team[second]-1];
        }
    }
    
    return sum;
}

void team(int memberBefore, int memberIndex) {
    if(memberIndex >= N/2) {
        makeLinkTeam();
        
        int result = getTeamPoint(start) - getTeamPoint(link);
        result = (result > 0)? result:0-result;
        
        minValue = (result < minValue)? result : minValue;
        return;
    }
    
    for(int i = memberBefore+1; i < N; i++) {
        start[memberIndex] = i;
        team(i, memberIndex+1);
    }
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> stat[i][j];
        }
    }
    
    team(0, 0);
    
    cout << minValue;
    
	return 0;
}
```

---

## 문제 해결에 대한 고민

start 팀과 link 팀의 능력치 합을 처음에는 stack 구조로 관리하려 했었다. 예를 들면, 아래처럼 멤버가 1명일 때 / 멤버가 2명일 때 / 멤버가 3명일 때 / 멤버가 4명일 때 / ... 로 나눠보면 능력치 총합이 나름 규칙적으로 증가하는 형태를 보인다.

```
멤버가 순서대로 1, 2, 3, 4가 들어왔다고 가정하자.
1 : 11
2 : 11 12 21 22
3 : 11 12 21 22 13 31 23 32 33
4 : 11 12 21 22 13 31 23 32 33 14 41 24 42 34 43 44
```

그래서 스택에 1, 12, 123, 1234 일 때의 스탯의 합을 넣어두고, 멤버가 1235로 넘어갈 때는 pop하여 top에 있는 총합을 123으로 만든 다음 5에 해당하는 값들만 더해 1235로 만들려고 했었다. 그런데, 이렇게 하면 start 팀은 효율적으로 처리가 되는데, link 팀이 문제였다. start 팀이 123 4~8으로 움직일 때, link 팀은 stack으로 처리할 수 있는 규칙을 따르지 않고 완전히 섞여버리더라. 그래서 그냥 단순하게 총합을 계속 구하는 형태로 풀이를 했는데, 이게 정답이라니..? ㅋㅋㅋ 생각보다 비효율적인 코드인데도 허락해줬나보다.