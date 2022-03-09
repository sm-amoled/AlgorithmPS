# [백준] 1697 - 숨바꼭질

Category: 알고리즘
PublishDate: 2022년 3월 8일 오후 11:05
Tag: BFS, 그래프
Visibility: Public
문제 번호: 1697

## 문제 링크

[https://www.acmicpc.net/problem/1697](https://www.acmicpc.net/problem/1697)

## 문제

수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

## 입력

첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

## 출력

수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

## 조건

- 시간 제한 : 2초
- 메모리 제한 : 128MB

---

## 해설

시작 위치 N에서부터 움직일 수 있는 경우는 3가지이다. [ +1 / -1 / x2 ] 

초 단위로 단계를 나눠서, 1초에 방문할 수 있는 위치 → 2초에 방문할 수 있는 위치 → 3초에 방문할 수 있는 위치 ... 를 쭉 계산하면서 목표 위치 K를 향해 움직인다. 
t초에 목표 위치 K에 방문할 수 있을 때, t초는 K에 방문할 수 있는 가장 빠른 t이므로, 탐색을 종료하고 시간 t초를 출력한다. 

```
ex)
위치 5에서 출발 -> 17 목표
1초에 방문할 수 있는 위치 : 4 6 10
2초에 방문할 수 있는 위치 : 3 7 8 9 11 12 20 (이미 방문한 위치 제거)
3초에 방문할 수 있는 위치 : ...
4초에 방문할 수 있는 위치 : ... 17 ... ( -> 4 출력 )
```

**내가 착각했던 부분**

100,000 위치 이상 (100,000 + $\alpha$)으로 넘어갔다가 다시 돌아오는 경우도 있을 것이므로, 범위를 200,000으로 잡아야 한다.

→ 시작 위치가 50,001 이고, 목표 위치가 100,000 이라고 하자. 이 경우에도 50,001 x2 -1 -1 보다 50,001 -1 x2 의 순서로 연산하는 것이 더 빠르게 목표 위치에 도달할 수 있다. 즉, 100,000을 넘어야 더 빠른 경우가 없으므로, 범위를 100,000까지로 제한하면 탐색을 더 빠르게 처리할 수 있다.

N이 K보다 더 멀리 있다면, N과 K의 위치를 바꿔 계산해주면 항상 양의 방향으로 움직이게 된다.

→ N / 2 로 움직이는 방향이 없기 때문에, N과 K의 위치를 바꾸면 전혀 엉뚱하게 움직이게 되기 때문에 안된다. 

## 풀이

필요한 변수와 공간을 선언해준다. 다음 초에 방문할 위치를 저장할 queue와 이미 방문한 장소를 저장할 bool 배열을 선언해주었다.

```cpp
int N, K;
queue<int> Q;

bool visit[100001];
```

main 함수에서 입력과 초기화부분의 코드이다. 초 단위를 카운트해줄 변수 `sec`을 선언하고, 시작 위치 N에 방문 표시 및 큐에 시작 위치 N을 담아준다. 만약 출발지와 도착지가 같다면 0을 출력하고 프로그램을 종료한다.

```cpp
cin >> N >> K;

int sec = 0;
Q.push(N);
visit[N] = true;

if(N == K) {
    cout << "0";
    return 0;
}
```

2중 반복문을 사용하여 찾아가는데 걸리는 시간을 체크한다. 
바깥쪽 while 문은 1초에 방문할 수 있는 곳 / 2초에 방문할 수 있는 곳 의 XX 초를 카운트하는 역할을 수행한다. 
안쪽 for 문은 X초에 방문할 수 있는 위치에서 X+1초에 방문할 위치를 기록하는 역할을 수행한다. 

주의할 점은, 방문한 곳과 방문할 곳을 동일한 큐에 저장하고 있다는 점이다. 따라서, for문의 선언부에 `Q.size()`를 통해 시작 size를 체크해두고, 이미 담겨있던 1초에 방문할 수 있는 곳의 개수 만큼만 pop 시키면서 방문할 곳을 push하고 있다. 

이 과정에서 목표 위치 K를 찾으면 바로 반복문을 둘 다 탈출한다. 그리고 초 sec를 출력하면 된다.

```cpp
// N과 K가 만날 때 까지
while(true) {
    sec++;
    
    for(int i = Q.size(); i > 0; i--) {
        int pos = Q.front();
        Q.pop();
        
        if(pos == K) break;
        
        if(pos - 1 >= 0 && visit[pos-1] == false) {
            Q.push(pos-1);
            visit[pos-1] = true;
        }
        
        if(pos + 1 <= 100000 && visit[pos+1] == false) {
            Q.push(pos+1);
            visit[pos+1] = true;
        }
        
        if(pos * 2 <= 100000 && visit[pos*2] == false) {
            Q.push(pos*2);
            visit[pos*2] = true;
        }
    }
    
    if(visit[K]) break;
}

cout << sec;
```

---

## 코멘트

BFS 풀이 방법을 적용하라고 하는데, 떠올리기가 너무 어려웠다. DP를 활용하는 방법을 적용했을 때는 메모리가 초과되는 문제가 있어서 틀렸다. 또, 현재 위치가 100,000 이니까 100,000 뒤로 넘어갔다가 -1 로 돌아오는 경우를 대비해 범위를 훨씬 더 넓게 잡았는데, 손으로 끄적여보니 100,000 뒤로 넘어갈 수 없는 형태라는 것을 눈치채고 범위를 줄였다!

shout out to [https://jun-itworld.tistory.com/19](https://jun-itworld.tistory.com/19)

---

## 코드

```cpp
#include <iostream>
#include <queue>
    
using namespace std;

int N, K;
queue<int> Q;

bool visit[100001];

int main(int argc, const char * argv[]) {
    cin >> N >> K;
    
    int sec = 0;
    Q.push(N);
    visit[N] = true;
    
    if(N == K) {
        cout << "0";
        return 0;
    }
    
    // N과 K가 만날 때 까지
    while(true) {
        sec++;
        
        for(int i = Q.size(); i > 0; i--) {
            int pos = Q.front();
            Q.pop();
            
            if(pos == K) break;
            
            if(pos - 1 >= 0 && visit[pos-1] == false) {
                Q.push(pos-1);
                visit[pos-1] = true;
            }
            
            if(pos + 1 <= 100000 && visit[pos+1] == false) {
                Q.push(pos+1);
                visit[pos+1] = true;
            }
            
            if(pos * 2 <= 100000 && visit[pos*2] == false) {
                Q.push(pos*2);
                visit[pos*2] = true;
            }
        }
        
        if(visit[K]) break;
    }
    
    cout << sec;
    return 0;
}
```

---

## 고민

### 1. DP로 풀기

DP로 풀어보려 했으나, int 자료형의 배열이 100001 의 사이즈를 가지면서 메모리 오버가 발생했다.

```cpp
#include <iostream>
#include <queue>
     
 using namespace std;

 int N, K;
 int dp[100001];

 void findPath(int from, int sec) {
     if(from < 0 || from > 100001) return;
     
     if(dp[from+1] > sec+1) dp[from+1] = sec+1;
     if(dp[from-1] > sec+1) dp[from-1] = sec+1;
     if(dp[from*2] > sec+1) dp[from*2] = sec+1;
 }

 int main(int argc, const char * argv[]) {
     cin >> N >> K;
     
     if(N > K) {
         int temp = N;
         N = K;
         K = temp;
     }
     
     fill_n(dp, K*2, 100000);
     
     dp[N] = 0;
     
     for(int i = N, sec = 0; i <= K; i++, sec++) {
         findPath(i, sec);
     }
     
     for(int i = 0; i < 20; i++) {
         cout << dp[i] << ' ';
     }
     
     cout << '\n';
     cout << dp[K] << '\n';
 }
```

### 2. BFS 도입

그 다음, 문제를 푼 방식과 유사한 BFS를 통해 해결해보려고 했지만, 또한 int 배열을 사용했기 때문에 메모리 초과로 실패했다.

```cpp
 #include <iostream>
 #include <queue>
     
 using namespace std;

 int N, K;
 queue<pair<int, int>> Q;
 // pair(position, sec)

 int dp[200001];

 int main(int argc, const char * argv[]) {
     cin >> N >> K;
     
     if(N > K) {
         int temp = N;
         N = K;
         K = temp;
     }
     
     fill_n(dp, 200001, 100000);

     
     int maxSec = 100000;
     // K에 도착할 때까지 걸리는 시간
     
     Q.push({N, 0});
     
     while(!Q.empty()) {
         int position = Q.front().first;
         int sec = Q.front().second;
         Q.pop();
         
         // 범위 체크
         if(position < 0 || position > 200000) {
             continue;
         }
         
         if(position == K) {
             // K에 도착하면 걸린 sec update 해주기
             if(maxSec > sec) maxSec = sec;
         }
         
         if(maxSec != 100000 && sec > maxSec) {
             // 이미 구한 최대 sec 보다 더 크다면 버리기
             continue;
         }
         
         if(dp[position] > sec) dp[position] = sec;
         
         Q.push({position+1, sec+1});
         Q.push({position-1, sec+1});
         Q.push({position*2, sec+1});
     }
     
     cout << dp[K];
     return 0;
 }
```
