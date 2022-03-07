# 창고 다각형

문제 번호: 2304
알고리즘 분류: 스택
푼 날짜: 2021년 2월 17일 오후 11:33

## 문제링크

[https://www.acmicpc.net/problem/2304](https://www.acmicpc.net/problem/2304)

## 문제

N 개의 막대 기둥이 일렬로 세워져 있다. 기둥들의 폭은 모두 1 m이며 높이는 다를 수 있다. 이 기둥들을 이용하여 양철로 된 창고를 제작하려고 한다. 창고에는 모든 기둥이 들어간다. 이 창고의 지붕을 다음과 같이 만든다.

1. 지붕은 수평 부분과 수직 부분으로 구성되며, 모두 연결되어야 한다.
2. 지붕의 수평 부분은 반드시 어떤 기둥의 윗면과 닿아야 한다.
3. 지붕의 수직 부분은 반드시 어떤 기둥의 옆면과 닿아야 한다.
4. 지붕의 가장자리는 땅에 닿아야 한다.
5. 비가 올 때 물이 고이지 않도록 지붕의 어떤 부분도 오목하게 들어간 부분이 없어야 한다.

그림 1은 창고를 옆에서 본 모습을 그린 것이다. 이 그림에서 굵은 선으로 표시된 부분이 지붕에 해당되고, 지붕과 땅으로 둘러싸인 다각형이 창고를 옆에서 본 모습이다. 이 다각형을 창고 다각형이라고 하자.

![https://www.acmicpc.net/JudgeOnline/upload/201011/cd.png](https://www.acmicpc.net/JudgeOnline/upload/201011/cd.png)

그림1 . 기둥과 지붕(굵은 선)의 예

창고 주인은 창고 다각형의 면적이 가장 작은 창고를 만들기를 원한다. 그림 1에서 창고 다각형의 면적은 98 ㎡이고, 이 경우가 가장 작은 창고 다각형이다.

기둥들의 위치와 높이가 주어질 때, 가장 작은 창고 다각형의 면적을 구하는 프로그램을 작성하시오.

## 입력

첫 줄에는 기둥의 개수를 나타내는 정수 N이 주어진다. N은 1 이상 1,000 이하이다. 그 다음 N 개의 줄에는 각 줄에 각 기둥의 왼쪽 면의 위치를 나타내는 정수 L과 높이를 나타내는 정수 H가 한 개의 빈 칸을 사이에 두고 주어진다. L과 H는 둘 다 1 이상 1,000 이하이다.

## 출력

첫 줄에 창고 다각형의 면적을 나타내는 정수를 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

기둥을 왼쪽에 두고 오른쪽 기둥까지 펼쳐지는 지붕을 생각해보자. 가장 높은 기둥을 기준으로 왼쪽 편에만 해당 형태의 지붕이 만들어 질 것이다. 반대로, 기둥을 오른쪽에 두고 왼쪽 기둥까지 펼쳐지는 지붕이라면 가장 높은 기둥의 왼쪽 편에만 만들어질 것이다. 

## 풀이

입력받은 기둥들을 position에 대해 오름차순으로 정렬해준다. (문제에 나와있는 그림과 같은 형태로 만들어준다.) 

![https://www.acmicpc.net/JudgeOnline/upload/201011/cd.png](https://www.acmicpc.net/JudgeOnline/upload/201011/cd.png)

기둥을 왼쪽에 두고 오른쪽 기둥까지 펼쳐지는 지붕을 생각해보자. 가장 높은 기둥을 기준으로 왼쪽 편에만 해당 형태의 지붕이 만들어 질 것이다. 반대로, 기둥을 오른쪽에 두고 왼쪽 기둥까지 펼쳐지는 지붕이라면 가장 높은 기둥의 왼쪽 편에만 만들어질 것이다. 

왼쪽에서 `leftMaxHeight`의 값을 기둥마다 비교하여 update하면서, 더 높은 기둥이 나올 때 마다 이전의 가장 높았던 기둥과 현재 더 높은 기둥 사이의 면적을 계산하여 result에 더해준다. 오른쪽은 그 반대로 하면 된다.

```cpp
int leftPos = house[0].first;
int leftMaxHeight = house[0].second;
int result = 0;
for(auto& p : house) {
    if(leftMaxHeight <= p.second) {
        result += (p.first-leftPos) * leftMaxHeight;
        leftMaxHeight = p.second;
        leftPos = p.first;
    }
}

int rightPos = house.back().first;
int rightMaxHeight = house.back().second;
for(int i = house.size() - 1; i >= 0; i--) {
    if(rightMaxHeight < house[i].second) {
        result += (rightPos - house[i].first) * rightMaxHeight;
        rightMaxHeight = house[i].second;
        rightPos = house[i].first;
    }
}

```

가장 높은 기둥에 대한 넓이를 함께 더해주기 위해 `leftMaxHeight`를 결과에 더해 출력해준다.

```cpp
cout << result + leftMaxHeight;
```

---

## 코멘트

이 문제는 좀 어려웠던 것 같다. 코드를 짜다가 자꾸 넘

## 고민

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> house;
    
    int pos, high;
    for(int i = 0; i < N; i++) {
        cin >> pos >> high;
        house.emplace_back(pos, high);
    }
    
    sort(house.begin(), house.end(), [](auto a, auto b) {
        return a.first < b.first;
    });
    
    int leftPos = house[0].first;
    int leftMaxHeight = house[0].second;
    int result = 0;
    for(auto& p : house) {
        if(leftMaxHeight <= p.second) {
            result += (p.first-leftPos) * leftMaxHeight;
            leftMaxHeight = p.second;
            leftPos = p.first;
        }
    }
    
    int rightPos = house.back().first;
    int rightMaxHeight = house.back().second;
    for(int i = house.size() - 1; i >= 0; i--) {
        if(rightMaxHeight < house[i].second) {
            result += (rightPos - house[i].first) * rightMaxHeight;
            rightMaxHeight = house[i].second;
            rightPos = house[i].first;
        }
    }
    
    cout << result + leftMaxHeight;
    return 0;
}
```