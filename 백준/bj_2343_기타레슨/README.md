# 기타 레슨

문제 번호: 2343
알고리즘 분류: 이분 탐색
푼 날짜: 2021년 2월 3일 오후 10:58

## 문제링크

[https://www.acmicpc.net/problem/2343](https://www.acmicpc.net/problem/2343)

## 문제

강토는 자신의 기타 레슨 동영상을 블루레이로 만들어 판매하려고 한다. 블루레이에는 총 N개의 레슨이 들어가는데, 블루레이를 녹화할 때, 레슨의 순서가 바뀌면 안 된다. 순서가 뒤바뀌는 경우에는 레슨의 흐름이 끊겨, 학생들이 대혼란에 빠질 수 있기 때문이다. 즉, i번 레슨과 j번 레슨을 같은 블루레이에 녹화하려면 i와 j 사이의 모든 레슨도 같은 블루레이에 녹화해야 한다.

강토는 이 블루레이가 얼마나 팔릴지 아직 알 수 없기 때문에, 블루레이의 개수를 가급적 줄이려고 한다. 오랜 고민 끝에 강토는 M개의 블루레이에 모든 기타 레슨 동영상을 녹화하기로 했다. 이때, 블루레이의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 단, M개의 블루레이는 모두 같은 크기이어야 한다.

강토의 각 레슨의 길이가 분 단위(자연수)로 주어진다. 이때, 가능한 블루레이의 크기 중 최소를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 레슨의 수 N (1 ≤ N ≤ 100,000)과 M (1 ≤ M ≤ N)이 주어진다. 다음 줄에는 강토의 기타 레슨의 길이가 레슨 순서대로 분 단위로(자연수)로 주어진다. 각 레슨의 길이는 10,000분을 넘지 않는다.

## 출력

첫째 줄에 가능한 블루레이 크기중 최소를 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

블루레이의 크기에 따라 필요한 블루레이의 개수가 정해져 있으며, 블루레이의 크기를 기준으로 이분 탐색을 실행하면 적절한 값을 구할 수 있다. 블루레이의 크기에 따라 필요한 개수가 오름차순으로 정렬되므로 이분 탐색의 적용이 가능하다.

## 풀이

우선 필요한 데이터를 입력받는다. 이때, 블루레이 길이의 최솟값 (레슨 1개짜리 블루레이)인 `maxLength`와 모든 레슨의 길이의 합인 `sumLength`를 구한다.   

```cpp
int N, M;
cin >> N >> M;
vector<int> Lesson(N);

int maxLength = 0, sumLength = 0;
for(int i = 0; i < N; i++) {
    cin >> Lesson[i];
    if(maxLength < Lesson[i]) maxLength = Lesson[i];
    sumLength += Lesson[i];
}
```

블루레이 길이에 대해 이분탐색을 실행한다. left, right로 움직일 지 결정하는 분기는 mid를 길이로 블루레이를 잘랐을 때 필요한 블루레이의 개수와 찾고자 하는 개수인 M을 비교하여 결정한다. 

```cpp
int left = maxLength, right = sumLength;
while(left <= right) {
    int mid = (left+right)/2;
    int count = 0, sum = 0;
    
    for(int i = 0; i < N; i++) {
        sum += Lesson[i];
        
        if(sum > mid) {
            sum = Lesson[i];
            count++;
        }
    }    
    
    if(count >= M) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}

printf("%d", left);
```

---

## 코멘트

이분 탐색은 아직 뭘 기준으로 놓을지가 헷갈린다. ㅜㅜ 

---

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> Lesson(N);
    
    int maxLength = 0, sumLength = 0;
    for(int i = 0; i < N; i++) {
        cin >> Lesson[i];
        if(maxLength < Lesson[i]) maxLength = Lesson[i];
        sumLength += Lesson[i];
    }
    
    int left = maxLength, right = sumLength;
    while(left <= right) {
        int mid = (left+right)/2;
        int count = 0, sum = 0;
        
        for(int i = 0; i < N; i++) {
            sum += Lesson[i];
            
            if(sum > mid) {
                sum = Lesson[i];
                count++;
            }
        }    
        
        if(count >= M) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    printf("%d", left);
    return 0;
}
```

## 코드