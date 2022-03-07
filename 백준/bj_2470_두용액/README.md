# 두 용액

문제 번호: 2470
알고리즘 분류: 이분 탐색, 투 포인터
푼 날짜: 2021년 2월 2일 오후 7:02

### 문제 링크

[https://www.acmicpc.net/problem/2470](https://www.acmicpc.net/problem/2470)

## 문제

KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다. 각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다.  산성 용액의 특성값은 1부터 1,000,000,000까지의 양의 정수로 나타내고, 알칼리성 용액의 특성값은 -1부터 -1,000,000,000까지의 음의 정수로 나타낸다.

같은 양의 두 용액을 혼합한 용액의 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의한다. 이 연구소에서는 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 한다.

예를 들어, 주어진 용액들의 특성값이 [-2, 4, -99, -1, 98]인 경우에는 특성값이 -99인 용액과 특성값이 98인 용액을 혼합하면 특성값이 -1인 용액을 만들 수 있고, 이 용액이 특성값이 0에 가장 가까운 용액이다. 참고로, 두 종류의 알칼리성 용액만으로나 혹은 두 종류의 산성 용액만으로 특성값이 0에 가장 가까운 혼합 용액을 만드는 경우도 존재할 수 있다.

산성 용액과 알칼리성 용액의 특성값이 주어졌을 때, 이 중 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액을 찾는 프로그램을 작성하시오.

## 입력

첫째 줄에는 전체 용액의 수 N이 입력된다. N은 2 이상 100,000 이하이다. 둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다. N개의 용액들의 특성값은 모두 다르고, 산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 경우도 있을 수 있다.

## 출력

첫째 줄에 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력한다. 출력해야 하는 두 용액은 특성값의 오름차순으로 출력한다. 특성값이 0에 가장 가까운 용액을 만들어내는 경우가 두 개 이상일 경우에는 그 중 아무것이나 하나를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

1차원 배열에서 2개의 index를 이용해 해답을 찾는 **투 포인터 알고리즘**을 이용해 답을 찾을 수 있다. 배열을 오름차순으로 정렬해 index 0 에서는 minus 포인터가, index N-1 에서는 plus 포인터가 값을 가리키며 0에 가장 가까운 용액을 찾는다. 

## 풀이

데이터를 입력받아 정렬한다. 

0번 index(minus 포인터)에서부터는 가장 작은 값이, N-1번 index(plus 포인터)에서부터는 가장 큰 값이 매겨진다. 정렬되어 있기 때문에, minus 포인터를 한 칸 위로 옮기면 값이 커지고,  plus 포인터를 한 칸 아래로 옮기면 값이 작아진다. minus 포인터와 plus 포인터가 가리키는 두 수의 합이 0보다 크면 plus 포인터를 한 칸 아래로 옮겨 합을 줄이고, 그 반대의 경우에는 minus 포인터를 한 칸 위로 옮겨 합을 키운다. 이 과정을 반복하여 0에 최대한 가까운 값을 찾는다.

```cpp
int minusIndex = 0, plusIndex = N-1;
int minusIndex0 = 0, plusIndex0 = N-1;
long minSum = mix(arr[minusIndex], arr[plusIndex]);

while(minusIndex < plusIndex) {
    long sum = mix(arr[minusIndex], arr[plusIndex]);
    
    if(sum < minSum) {
        minusIndex0 = minusIndex;
        plusIndex0 = plusIndex;
        
        minSum = sum;
    }
    
    if(arr[minusIndex] + arr[plusIndex] > 0) {
        plusIndex--;
    } else {
        minusIndex++;
    }
}
```

---

## 코멘트

두 포인터에 대해 처음 공부해봤다. 대충 아이디어는 생각했는데, 이게 실제로 있는 알고리즘 방식이란거는 신기하더라. 

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long mix(long a, long b) {
    return (a+b > 0)? a+b: 0-(a+b);
}

int main() {
    int N;
    cin >> N;
    vector<long> arr(N);
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    int minusIndex = 0, plusIndex = N-1;
    int minusIndex0 = 0, plusIndex0 = N-1;
    long minSum = mix(arr[minusIndex], arr[plusIndex]);
    
    while(minusIndex < plusIndex) {
        long sum = mix(arr[minusIndex], arr[plusIndex]);
        
        if(sum < minSum) {
            minusIndex0 = minusIndex;
            plusIndex0 = plusIndex;
            
            minSum = sum;
        }
        
        if(arr[minusIndex] + arr[plusIndex] > 0) {
            plusIndex--;
        } else {
            minusIndex++;
        }
    }
    
    
    printf("%ld %ld", arr[minusIndex0], arr[plusIndex0]);
    
    return 0;
}
```