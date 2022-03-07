# K번째 수

문제 번호: 11004
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 27일 오후 7:04

### 문제 링크

[https://www.acmicpc.net/problem/11004](https://www.acmicpc.net/problem/11004)

## 문제

수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N(1 ≤ N ≤ 5,000,000)과 K (1 ≤ K ≤ N)이 주어진다.

둘째에는 A1, A2, ..., AN이 주어진다. (-109 ≤ Ai ≤ 109)

## 출력

A를 정렬했을 때, 앞에서부터 K번째 있는 수를 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 512MB

---

## 해설

정렬 알고리즘을 이용해 매우 쉽게 해결 가능한 문제이다. 

## 풀이

수를 입력받아 지정된 개수만큼 vector에 저장하여 넣어준다. `sort()` 함수를 이용해 vector를 정렬해주고, 앞에서 K 번째 수(index가 K-1) 을 출력한다. 

---

## 코멘트

요즘은 Vector 쓰는 연습을 하고있다. 확실히 동적인 프로그래밍을 할 때 유용한 것 같다.

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int count, K, inputNumber;
    cin >> count >> K;

    for(int i = 0; i < count; i++) {
        scanf("%d", &inputNumber);
        v.push_back(inputNumber);
    }
    sort(v.begin(), v.end());

    cout << v[K-1];
    return 0;
}
```