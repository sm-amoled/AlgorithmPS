# 용액

문제 번호: 2467
알고리즘 분류: 이분 탐색, 투 포인터
푼 날짜: 2021년 2월 4일 오후 8:46

## 문제링크

[https://www.acmicpc.net/problem/2467](https://www.acmicpc.net/problem/2467)

## 문제

KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다. 각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다. 산성 용액의 특성값은 1부터 1,000,000,000까지의 양의 정수로 나타내고, 알칼리성 용액의 특성값은 -1부터 -1,000,000,000까지의 음의 정수로 나타낸다.

같은 양의 두 용액을 혼합한 용액의 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의한다. 이 연구소에서는 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 한다.

예를 들어, 주어진 용액들의 특성값이 [-99, -2, -1, 4, 98]인 경우에는 특성값이 -99인 용액과 특성값이 98인 용액을 혼합하면 특성값이 -1인 용액을 만들 수 있고, 이 용액의 특성값이 0에 가장 가까운 용액이다. 참고로, 두 종류의 알칼리성 용액만으로나 혹은 두 종류의 산성 용액만으로 특성값이 0에 가장 가까운 혼합 용액을 만드는 경우도 존재할 수 있다.

산성 용액과 알칼리성 용액의 특성값이 정렬된 순서로 주어졌을 때, 이 중 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액을 찾는 프로그램을 작성하시오.

## 입력

첫째 줄에는 전체 용액의 수 N이 입력된다. N은 2 이상 100,000 이하의 정수이다. 둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 오름차순으로 입력되며, 이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다. N개의 용액들의 특성값은 모두 서로 다르고, 산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 경우도 있을 수 있다.

## 출력

첫째 줄에 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력한다. 출력해야 하는 두 용액은 특성값의 오름차순으로 출력한다. 특성값이 0에 가장 가까운 용액을 만들어내는 경우가 두 개 이상일 경우에는 그 중 아무것이나 하나를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

**투 포인터 알고리즘**을 이용해 문제를 쉽게 해결할 수 있다. 

## 풀이

알고리즘의 적용을 위해 입력받은 데이터를 정렬해준다. 먼저, 가장 작은 값과 가장 큰 값을 더해 0과 비교한다. 합이 0보다 작으면 작은 값을 크게 만들고, 0보다 크면 큰 값을 작게 만들어 더하고 또 0과 비교한다. 값을 크고 작게 만드는 작업은 작은 값을 가리키는 left 인덱스와 큰 값을 가리키는 right 인덱스를 각각 ++ / --하여 쉽게 구현할 수 있다. left와 right가 겹쳐지거나 합이 0인 두 수를 만난 경우에는 유의미한 비교를 끝마쳤으므로 결과를 출력하고 종료한다. 

```cpp
int left = 0, right = N-1;
int minLeft, minRight;
long minValue = 1000000000;

while(left < right) {
    long sum = arr[left]+arr[right];
    
    if(minValue > abs(sum)) {
        minLeft = left;
        minRight = right;
        minValue = abs(sum);
    }
    
    if(sum < 0) {
        left++;
    } else if(sum > 0){
        right--;
    } else {
        break;
    }
}

printf("%ld %ld\n", arr[minLeft], arr[minRight]);
```

만약 모든 값이 양수이거나 음수라면 (가장 큰 수와 가장 작은 수만 비교하면 알 수 있다) 비교할 이유가 없다. 가장 크거나 가장 작은 두 수만 출력해주고 종료한다. 아래 코드를 반복문에 들어가기 전에 삽입해주면 된다.

```cpp
if(arr[left] > 0 && arr[right] > 0) {
    printf("%ld %ld\n", arr[left], arr[left+1]);
    return 0;
} else if (arr[left] < 0 && arr[right] < 0) {
    printf("%ld %ld\n", arr[right-1], arr[right]);
    return 0;
}
```

---

## 코멘트

저번에 비슷한 문제를 푼 것 같은데...?

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
    
    int N;
    cin >> N;
    vector<long> arr(N);
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int left = 0, right = N-1;
    int minLeft, minRight;
    long minValue = 1000000000;
    
    if(arr[left] > 0 && arr[right] > 0) {
        printf("%ld %ld\n", arr[left], arr[left+1]);
        return 0;
    } else if (arr[left] < 0 && arr[right] < 0) {
        printf("%ld %ld\n", arr[right-1], arr[right]);
        return 0;
    }
    
    while(left < right) {
        long sum = arr[left]+arr[right];
        
        if(minValue > abs(sum)) {
            minLeft = left;
            minRight = right;
            minValue = abs(sum);
        }
        
        if(sum < 0) {
            left++;
        } else if(sum > 0){
            right--;
        } else {
            break;
        }
    }
    
    printf("%ld %ld\n", arr[minLeft], arr[minRight]);
    
    return 0;
}
```