# 세수정렬

문제 번호: 2752
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 27일 오후 7:19

### 문제 링크

[https://www.acmicpc.net/problem/2752](https://www.acmicpc.net/problem/2752)

## 문제

동규는 세수를 하다가 정렬이 하고싶어졌다.

숫자 세 개를 생각한 뒤에, 이를 오름차순으로 정렬하고 싶어 졌다.

숫자 세 개가 주어졌을 때, 가장 작은 수, 그 다음 수, 가장 큰 수를 출력하는 프로그램을 작성하시오

## 입력

숫자 세 개가 주어진다. 이 숫자는 1보다 크거나 같고, 1,000,000보다 작거나 같다. 이 숫자는 모두 다르다.

## 출력

제일 작은 수, 그 다음 수, 제일 큰 수를 차례대로 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

3개의 수를 받아온 다음, 정렬하여 출력하면 끝!

## 풀이

3개의 수를 받아온 다음, 정렬하여 출력하면 끝! 받아온 데이터를 저장하는 데에는 vector를 이용해주었고, 정렬하는데는 `sort()`를 이용하였다. 

---

## 코멘트

이런 것도 문제라고! ㅋㅋㅋ

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int temp;
    vector<int> sesu;

    scanf("%d", &temp);
    sesu.push_back(temp);
    scanf("%d", &temp);
    sesu.push_back(temp);
    scanf("%d", &temp);
    sesu.push_back(temp);

    sort(sesu.begin(), sesu.end());

    printf("%d %d %d", sesu.at(0), sesu.at(1), sesu.at(2));
    return 0;
}
```