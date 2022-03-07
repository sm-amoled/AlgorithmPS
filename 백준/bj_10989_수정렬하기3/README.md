# 수 정렬하기 3

문제 번호: 10989
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 20일 오후 8:08

### 문제 링크

[https://www.acmicpc.net/problem/10989](https://www.acmicpc.net/problem/10989)

## 문제

N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

## 입력

첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

## 출력

첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

## 조건

- 시간 제한 : 3s
- 메모리 제한 : 8MB

---

## 해설

10000개의 자연수만 등장한다고 미리 알려주었으므로, 원소의 종류가 충분히 작다고 판단하여 계수 정렬을 이용해 정렬을 진행한 뒤, 결과를 출력하는 방식으로 문제를 해결하였다.

## 풀이

처음에는 cout, cin 함수를 이용해 문제를 해결하려 했지만, 시간 초과로 계속 오답을 받았다. 처음에는 시간복잡도로 인해 발생한 문제라고 생각하고 알고리즘을 수정하려 했는데, 프로그램 실행이 오래걸린 이유는 입출력 함수의 실행속도였다. 실행 속도가 느린 cout, cin 함수 대신 복잡하지만 효율이 좋은 printf, scanf 함수를 사용하여야겠다. 사용했던 코드는 코드 상에 주석 처리를 하여 남겨두었다. 

---

## 코멘트

cout, cin 함수보다 printf, scanf 함수가 빠르다는 점을 이용해야 하는 문제였다. 생각하지도 못했던 함수의 실행 속도에서 발목이 걸릴 수 있다는 것을 배웠다. 

---

## 코드

```cpp
#include <iostream>
using namespace std;
int arr[10001]={0,};

int main() {
    int number;
    int temp;
    int max = 0;
    
    cin >> number;
    
    for(int i = 0; i < number; i++) {
				// cin >> temp;
        scanf("%d", &temp);
        arr[temp]++;
        if(temp > max) max = temp;
    }
    
    for(int i = 1; i <= max; i++) {
        for(int j = 0; j < arr[i]; j++) {
            printf("%d\n", i);
        }
        // if(arr[i] == 0) continue;
        // while(arr[i] != 0) {
        //     cout << i << "\n";
        //     arr[i]--;
        // }
    }
    
    return 0;
}
```