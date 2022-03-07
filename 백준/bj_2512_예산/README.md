# 예산

문제 번호: 2512
알고리즘 분류: 이분 탐색
푼 날짜: 2021년 1월 30일 오후 9:22

### 문제 링크

[https://www.acmicpc.net/problem/2512](https://www.acmicpc.net/problem/2512)

## 문제

국가의 역할 중 하나는 여러 지방의 예산요청을 심사하여 국가의 예산을 분배하는 것이다. 국가예산의 총액은 미리 정해져 있어서 모든 예산요청을 배정해 주기는 어려울 수도 있다. 그래서 정해진 총액 이하에서 **가능한 한 최대의** 총 예산을 다음과 같은 방법으로 배정한다.

1. 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
2. 모든 요청이 배정될 수 없는 경우에는 특정한 **정수** 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정한다. 상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다.

예를 들어, 전체 국가예산이 485이고 4개 지방의 예산요청이 각각 120, 110, 140, 150이라고 하자. 이 경우, 상한액을 127로 잡으면, 위의 요청들에 대해서 각각 120, 110, 127, 127을 배정하고 그 합이 484로 가능한 최대가 된다.

여러 지방의 예산요청과 국가예산의 총액이 주어졌을 때, 위의 조건을 모두 만족하도록 예산을 배정하는 프로그램을 작성하시오.

## 입력

첫째 줄에는 지방의 수를 의미하는 정수 N이 주어진다. N은 3 이상 10,000 이하이다. 다음 줄에는 각 지방의 예산요청을 표현하는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 값들은 모두 1 이상 100,000 이하이다. 그 다음 줄에는 총 예산을 나타내는 정수 M이 주어진다. M은 N 이상 1,000,000,000 이하이다.

## 출력

첫째 줄에는 배정된 예산들 중 최댓값인 정수를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

구하고자 하는 배정 예산값을 이분 탐색을 이용해 구한다. 국가예산과 배정 예산값을 이용했을 때의 예산값을 비교하여 탐색한다.

## 풀이

아래와 같이 이분탐색을 구현할 수 있다. 

```cpp
int left = 0, right = max, mid, result;
long sum;
while(left <= right) {
    mid = (left+right)/2;
    
    sum = 0;
    for(auto x : urban) {
        if(x<mid) sum += x;
        else sum += mid;
    }
    
    if(budget < sum) {
        right = mid-1;
    } else {
        left = mid+1;
        result = mid;
    }
}

printf("%d\n", result);
```

일반적인 이분 탐색과 비슷하지만, 눈여겨 볼 점은 for 문을 이용해 선택한 예산액에 대한 예산 수요를 구하고, 이와 국가 예산을 비교하여 이분 탐색을 진행한다는 것이다. 또, 예산을 넘지 않는 최저점을 찾기위해, `left = mid + 1`이라는 식 뒤에 `result = mid`를 사용하여 항상 left보다 1 뒤에 있도록 해주었다. 

---

## 코멘트

“전체 예산을 넘지않는 최소 예산액”이라는 부분에서 살짝 고생을 했다. ㅜㅜ 여기에서 도움을 얻을 수 있었다. 감사합니다! [https://jaimemin.tistory.com/992](https://jaimemin.tistory.com/992)

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
    
    int N, budget, temp, max = 0;
    
    vector<int> urban; 
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        urban.push_back(temp);
        if(max < temp) {
            max = temp;
        }
    }
    cin >> budget;
    
    int left = 0, right = max, mid, result;
    long sum;
    while(left <= right) {
        mid = (left+right)/2;
        
        sum = 0;
        for(auto x : urban) {
            if(x<mid) sum += x;
            else sum += mid;
        }
        
        if(budget < sum) {
            right = mid-1;
        } else {
            left = mid+1;
            result = mid;
        }
    }

    printf("%d\n", result);
    return 0;
}
```