# 가장 긴 증가하는 부분 수열 3

문제 번호: 12738
알고리즘 분류: LDS, 이분 탐색
푼 날짜: 2021년 2월 2일 오후 7:50

### 문제 링크

[https://www.acmicpc.net/problem/12738](https://www.acmicpc.net/problem/12738)

## 문제

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {**10**, **20**, 10, **30**, 20, **50**} 이고, 길이는 4이다.

## 입력

첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)

## 출력

첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

## 조건

- 시간 제한 : 3s
- 메모리 제한 : 512MB

---

## 해설

LDS 알고리즘을 이용해 해결할 수 있는 문제이다. 

## 풀이

수열을 입력받아준다.

```cpp
int N;
cin >> N;
vector<int> arr(N);
for(int i = 0; i < N; i++) {
    cin >> arr[i];
}
```

int형의 벡터 LDS를 하나 선언해주었다. 이 벡터는 LDS 알고리즘을 수행하기 위한 수가 담기는 공간이다. LDS 벡터 내에서는 항상 오름차순으로 수가 정렬된다. LDS 백터에서 가장 큰 수보다 arr[i]가 더 크다면 push하여 값을 넣는다. 만약 그렇지 않다면, arr[i]보다 큰 가장 작은 수를 탐색하여 arr[i]로 그 자리를 대체한다. 이때 탐색하는 알고리즘은 **이분 탐색**을 사용한다.

```cpp
vector<int> LDS;    
LDS.push_back(arr[0]);
for(int i = 0; i < N; i++) {
    if(LDS.back() < arr[i]) {
        LDS.push_back(arr[i]);
        continue;
    } 
    
    int left = 0, right = LDS.size()-1;
    while(left <= right) {
        int mid = (left + right)/2;
        
        if(LDS.at(mid) >= arr[i]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    if(LDS.at(left) > arr[i]) {
        LDS[left] = arr[i];
    }
}
```

이렇게 만들어진 벡터 LDS에는 부분 수열을 만들기 위한 원소들이 담겨있고, LDS의 길이가 최대 부분 수열의 크기와 같다. 

```cpp
printf("%d", (int)LDS.size());
```

---

## 코멘트

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> LDS;    
    LDS.push_back(arr[0]);
    for(int i = 0; i < N; i++) {
        if(LDS.back() < arr[i]) {
            LDS.push_back(arr[i]);
            continue;
        } 
        
        int left = 0, right = LDS.size()-1;
        while(left <= right) {
            int mid = (left + right)/2;
            
            if(LDS.at(mid) >= arr[i]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        if(LDS.at(left) > arr[i]) {
            LDS[left] = arr[i];
        }
    }
    
    printf("%d", (int)LDS.size());
    
    return 0;
}
```