# 공유기 설치

문제 번호: 2110
알고리즘 분류: 매개 변수 탐색, 이분 탐색
푼 날짜: 2021년 1월 31일 오전 10:28

### 문제 링크

[https://www.acmicpc.net/problem/2110](https://www.acmicpc.net/problem/2110)

## 문제

도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.

도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.

C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.

## 입력

첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다. 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (0 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.

## 출력

첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

binary search 알고리즘을 최소 거리에 따른 공유기의 수를 비교하며 적절한 최소 거리를 찾으면 해결할 수 있는 문제이다.

## 풀이

수직선 위의 주소를 vector<int>에 입력받아온다. 이분 정렬 알고리즘을 적용하기 위해, 주소를 오름차순으로 정렬해준다. 

```cpp
int N, C;

cin >> N >> C;
vector<int> house(N);
for(int i = 0; i < N; i++){
    cin >> house[i];
}

sort(house.begin(), house.end());
```

이분 정렬에서 움직이는 값은 찾고자 하는 값인 **공유기 간의 최소 거리**로 두었다. 이 거리 값이 움직이면 놓을 수 있는 공유기의 개수도 달라지는데, 입력받은 설치하고자 하는 공유기의 개수를 만족하는 거리 중 최소 거리의 최대값을 구하면 된다. 

두 공유기 사이의 거리가 최소 거리 이상을 만족할 때 count++를 하고, 그 공유기부터 최소 거리를 만족하는 다음 공유기에서 count++ 를 반복하여 해당 거리 값에 대한 공유기의 개수를 구한다. 이 개수를 기준으로 이분 탐색 범위를 결정한다. 또, 최소 거리를 구하고 있기 때문에, left 범위를 옮길 때, mid 값을 answer에 저장시켜둔다. 최종적으로 저장된 answer값이 구하고자 하는 최소 거리이다.

```cpp
int left = 1, right = house[N-1] - house[0];
int answer;
while(left<=right) {
    int mid = (left+right)/2;
    int count = 1;
    int start = house[0];
    
    for(int i = 1; i < N; i++) {
        int d = house[i]-start;
        if(d>=mid) {
            start = house[i];
            count++;
        }
    }
    
    if(count >= C) {
        answer = mid;
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}

cout << answer;
```

---

## 코멘트

무엇을 이분 정렬로 찾는 값으로 두고 풀 지를 정하는 것이 어려웠다. 이 부분에 대해서는 연습이 좀 많이 필요할 것 같다.

[https://mygumi.tistory.com/301](https://mygumi.tistory.com/301)

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;
    
    cin >> N >> C;
    vector<int> house(N);
    for(int i = 0; i < N; i++){
        cin >> house[i];
    }
    
    sort(house.begin(), house.end());
    
    int left = 1, right = house[N-1] - house[0];
    int answer;
    while(left<=right) {
        int mid = (left+right)/2;
        int count = 1;
        int start = house[0];
        
        for(int i = 1; i < N; i++) {
            int d = house[i]-start;
            if(d>=mid) {
                start = house[i];
                count++;
            }
        }
        
        if(count >= C) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer;
    return 0;
}
```