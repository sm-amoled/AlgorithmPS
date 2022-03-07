# 반도체 설계

문제 번호: 2352
알고리즘 분류: LDS, 이분 탐색
푼 날짜: 2021년 2월 1일 오후 7:13

### 문제 링크

[https://www.acmicpc.net/problem/2352](https://www.acmicpc.net/problem/2352)

## 문제

반도체를 설계할 때 n개의 포트를 다른 n개의 포트와 연결해야 할 때가 있다.

![https://www.acmicpc.net/JudgeOnline/upload/201103/chip.png](https://www.acmicpc.net/JudgeOnline/upload/201103/chip.png)

예를 들어 왼쪽 그림이 n개의 포트와 다른 n개의 포트를 어떻게 연결해야 하는지를 나타낸다. 하지만 이와 같이 연결을 할 경우에는 연결선이 서로 꼬이기 때문에 이와 같이 연결할 수 없다. n개의 포트가 다른 n개의 포트와 어떻게 연결되어야 하는지가 주어졌을 때, 연결선이 서로 꼬이지(겹치지, 교차하지) 않도록 하면서 최대 몇 개까지 연결할 수 있는지를 알아내는 프로그램을 작성하시오

## 입력

첫째 줄에 정수 n(1 ≤ n ≤ 40,000)이 주어진다. 다음 줄에는 차례로 1번 포트와 연결되어야 하는 포트 번호, 2번 포트와 연결되어야 하는 포트 번호, …, n번 포트와 연결되어야 하는 포트 번호가 주어진다. 이 수들은 1 이상 n 이하이며 서로 같은 수는 없다고 가정하자.

## 출력

첫째 줄에 최대 연결 개수를 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

문제를 잘 읽어보면 꼬이지 않게 포트를 선택하기 위해서는 선택한 포트의 번호가 계속 증가해야 한다. 이전에 선택한 포트 번호보다 작으면 줄이 꼬이기 때문이다. 이 점을 본다면 나열된 숫자 배열에서 선택한 원소들이 오름차순으로 정렬된 배열을 만드는 알고리즘이므로, LDS(가장 긴 증가하는 부분 수열) 알고리즘을 이용해 풀 수 있다는 것을 알 수 있다.

## 풀이

Input을 받아와 동적으로 메모리 공간을 생성하기 위해 vector를 사용해주었다. lds 벡터는 lds 알고리즘을 해결하기 위해 사용되는 벡터이다. 

```cpp
int N;
cin >> N;

vector<int> arr(N);
vector<int> lds;
for(int i = 0; i < N; i++) {
    cin >> arr[i];
}
```

우선 `lds.back()`이 메모리 참조에서 오류가 발생하지 않도록 하기 위해 첫번째 원소를 lds에 넣어주고 시작한다. lds 벡터의 최댓값보다 비교하는 원소가 크다면 `push_back()` 함수를 통해 넣어주고, 작다면 lds 벡터에서 해당 원소보다 큰 가장 작은 값을 찾아 자리를 대체한다. (작은 값일수록 더 긴 배열을 만들기에 유리하기 때문에) 이 알고리즘에 대해 더 자세하게 알고싶다면 **LDS 알고리즘**을 찾아보자. 마지막에 lds 벡터의 사이즈가 만들 수 있는 부분 수열의 최대길이이자, 선택할 수 있는 포트의 최대 개수이다. 

```cpp
// initial value
lds.push_back(arr[0]);

for(int i = 1; i < N; i++) {
    if(lds.back() < arr[i]) {
        lds.push_back(arr[i]);
    } else {
        int left = 0, right = lds.size();
        int mid;
        while(left <= right) {
            mid = (left+right)/2;
        
            if(lds[mid] <= arr[i]) {
                left=mid+1;
            } else {
                right=mid-1;
            }
        }
        lds[left] = arr[i];
    }
}

printf("%d\n", (int)lds.size());

```

---

## 코멘트

수학 활용 문제를 만난 기분이다. 뭔가 숨겨져있어서, 파헤쳐봤더니 LDS 문제네 ㅎㅎ. 이정도 난이도의 숨겨진 알고리즘을 찾아내는 문제라면 기분좋게 풀어낼 수 있을 것 같다.

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
    vector<int> lds;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // initial value
    lds.push_back(arr[0]);
    for(int i = 1; i < N; i++) {
        if(lds.back() < arr[i]) {
            lds.push_back(arr[i]);
        } else {
            int left = 0, right = lds.size();
            int mid;
            while(left <= right) {
                mid = (left+right)/2;
            
                if(lds[mid] <= arr[i]) {
                    left=mid+1;
                } else {
                    right=mid-1;
                }
            }
            lds[left] = arr[i];
        }
    }
    
    printf("%d\n", (int)lds.size());
    return 0;
}
```