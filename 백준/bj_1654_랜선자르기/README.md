# 랜선 자르기

문제 번호: 1654
알고리즘 분류: 탐색
푼 날짜: 2021년 1월 29일 오후 11:31

### 문제 링크

[https://www.acmicpc.net/problem/1654](https://www.acmicpc.net/problem/1654)

## 문제

집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.

이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다. 예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)

편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자. 그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 그리고 항상 K ≦ N 이다. 그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 231-1보다 작거나 같은 자연수이다.

## 출력

첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

만들고자 하는 길이를 범위로 하여 값을 이분탐색으로 찾는다. 이분 탐색에서 값을 저장하는 기준은 N개의 랜선을 만들었는가? 이다.

## 풀이

이분 탐색의 범위인 0~최대 길이 랜선 을 규정해주기 위해 max를 입력과 함께 조사한다. 

아래 코드에서 mid가 우리가 찾고자하는 랜선 길이를 찾아다니는 더듬이이다. 입력받은 각 랜선의 길이를 mid로 나누었을 때의 몫의 합이 만들 수 있는 랜선의 개수이다. mid로 잘랐을 때 랜선이 충분할 때는 더 길게 잘라야 하므로 범위를 올려주고, 부족할 때는 더 짧게 잘라야 하므로 범위를 내려준다. 만약 충분하게 잘랐을 때는, 이게 앞서 탐색했던 mid 중 최댓값일때 result에 저장한다. 

```cpp
left = 0; right = max;
while(left <= right) {
    mid = (left+right)/2;
    cableCount = 0;
    
    for(int i = 0; i < K; i++) {
        cableCount += cable[i]/mid;
    }
    
    if(cableCount >= N) {
        if(result < mid) result = mid;
        left = mid+1;
    }
    else {
        right = mid-1;
    }
}
```

여기에서 `mid = (left+right) / 2` 수식을 실행시키기 위해서 `left+right`를 자료형이 충분히 담을 수 있어야 하는데, 극단적으로 생각해봤을 때, left가 0이고 right가 2^31-1일때는 문제가 안되지만, 그 다음 단계인 left가 2^30-1, right가 2^31-1일때는 문제가 된다. 따라서, **left, right의 자료형은 int가 아닌 long 형이여야 한다.**

```cpp
long left, right, mid;
```

K, N의 값이 1이라고 할 때, left+right가 0+1로 1의 값을 갖게된다. 이때 mid가 0이 되는데, cable[i]를 0으로 나누는 것을 방지하기 위해 반올림 처리를 해주기 위해 left+right에 1을 추가로 더해주었다. 

```cpp
mid = (left+right+1)/2;
```

---

## 코멘트

범위에서 오류가 났을 줄이야... 자료형과 입력되는 값의 범위를 꼭 한 번 더 체크하자.

---

## 코드

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    int* cable;
    int max = 0;
    long left, right, mid;
    int cableCount;
    long result = 0;
    
    cin >> K >> N;
    cable = new int[K];
    
    for(int i = 0; i < K; i++) {
        cin >> cable[i];
        if(max < cable[i]) max = cable[i];
    }
    
    left = 0; right = max;
    while(left <= right) {
        mid = (left+right+1)/2;
        cableCount = 0;
        
        for(int i = 0; i < K; i++) {
            cableCount += cable[i]/mid;
        }
        
        if(cableCount >= N) {
            if(result < mid) result = mid;
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    
    printf("%ld", result);
    
    return 0;
}
```
