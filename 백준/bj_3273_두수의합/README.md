#  두 수의 합

문제 번호: 3273
알고리즘 분류: 투 포인터
푼 날짜: 2021년 3월 29일 오후 11:09

## 문제링크

[https://www.acmicpc.net/problem/3273](https://www.acmicpc.net/problem/3273)

## 문제

n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다. 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)

## 출력

문제의 조건을 만족하는 쌍의 개수를 출력한다.


## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

배열을 정렬하여 오름차순으로 값을 나열한 다음, 두 수를 더했을 때 결과가 주어진 값과 일치하는 쌍의 개수를 구하면 된다. 두 수의 합이 값보다 작으면 둘 중 작은 수를 더 큰 수로 만들고, 크면 둘 중 큰 수를 더 작은 수로 만들면 된다.



## 풀이

주어진 수열(배열)을 오름차순으로 정렬하면 작은 값부터 차례로 배열에 들어가있다. 가장 큰 값과 가장 작은 값의 합을 기준으로 시작하여, 이 값이 비교하고자 하는 값보다 작다면 둘 중 큰 값을 2번째로 큰 값으로 교체하여 합을 줄인다. 반대로, 비교하고자 하는 값보다 크다면 둘 중 작은 값을 2번째로 작은 값으로 교체하여 합을 키운다. 이렇게 값을 비교하면서 만약 결과가 일치한다면 쌍의 개수를 하나 카운트하고, 값의 쌍을 작은 값은 덜 작은 값, 큰 값은 덜 큰 값으로 바꾸고 계속 비교해나간다. 

```cpp
	int cmp;
    int start = 0, end = arr.size()-1;
    int result = 0;

    cin >> cmp;

    while(start < end) {
        int sum = arr[start] + arr[end];
        if(sum > cmp) {
            end--;
        } else if (sum < cmp) {
            start++;
        } else {
            result++;
            start++;
            end--;
        }
    }
```



선택할 수 있는 작은/큰 값이 남아있지 않은 경우에 반복을 종료하고 쌍의 개수를 출력해준다.

```cpp
     cout << result;
```



---

## 코멘트

이정도 레벨의 투 포인터는 쉽게 해결 할 수 있지 ㅎㅎ


---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int cmp;
    int start = 0, end = arr.size()-1;
    int result = 0;

    cin >> cmp;

    while(start < end) {
        int sum = arr[start] + arr[end];
        if(sum > cmp) {
            end--;
        } else if (sum < cmp) {
            start++;
        } else {
            result++;
            start++;
            end--;
        }
    }

    cout << result;
    return 0;
}
```
