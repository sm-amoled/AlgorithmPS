# 분해합

문제 번호: 2231
알고리즘 분류: 브루트 포스
푼 날짜: 2021년 3월 1일 오후 8:35

## 문제링크

[https://www.acmicpc.net/problem/2231](https://www.acmicpc.net/problem/2231)

## 문제

어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다. 어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다. 예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 따라서 245는 256의 생성자가 된다. 물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다. 반대로, 생성자가 여러 개인 자연수도 있을 수 있다.

자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.

## 입력

첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

## 출력

첫째 줄에 답을 출력한다. 생성자가 없는 경우에는 0을 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 192MB

---

## 해설

N이 주어졌을 때, N이 만들어질 가능성이 있는 가장 작은 생성자의 값 ~ 가장 큰 생성자의 값 에 대해 N이 만들어지는 지를 검사하여, 있다면 가장 작은 생성자 값을 출력하고 없다면 0을 출력하면 된다. 

## 풀이

해당 분해합을 만들 가능성이 있는 가장 큰 값은 `분해합 - 1`일 것이다. (ex - 2 : 생성자가 1 ) 분해합을 만들 가능성이 있는 가장 작은 값은 어떻게 구해야 할까. 4자리 수 ABCD가 분해합으로 제시되었다면, 각 A, B, C, D에 들어갈 수 있는 가장 큰 수는 9이다. 즉, `ABCD - 4x9` 에서부터 생성자가 분해합을 만들 수 있는지를 검사한다면 1000 ~ 9999까지 4자리수인 분해합에 대해서 모두 커버가 가능하다. N자리수라면 주어진 분해자에서 Nx9를 빼주면 되겠다.

이를 코드로 구현하면 아래와 같다. 우선 생성자를 검사할 초기값을 만들어준다. temp를 통해 주어진 N이 몇 자리 수인지를 계산하며 그만큼 9를 생성자에 더해준다. 그다음 주어진 N 값에서 해당 값을 빼면 적절한 생성자의 초기값이다.

```cpp
// generator의 초깃값은 N이 4자리라면 ABCD - (ABCD가 모두 최댓값일 때 가질 최대 부분 = 9, 9, 9, 9 ... 4x9) 이다. 이 값보다 작은 값에서 생성자가 나올 수 없다.
int digitSum, generator = 0, temp = 1;
while(temp < N) {
    temp *= 10;
    generator += 9;
}
generator = N - generator;
```

generator를 1씩 키워가면서 `generator + 각 자리의 값들`을 계산하고, 이 값이 N과 동일하면 generator를 출력하고 프로그램을 종료한다. 이 반복문은 generator가 N보다 작을 때 까지만 반복해준다. 처음에는 generator로 만들어진 분해합을 N과 비교하여 반복문의 탈출 조건을 결정했었는데, 이렇게 만들어진 분해합이 계속 증가하는게 아니라 들쭉날쭉해서 제대로 검사를 진행할 수 없었다. 그래서, 확실하게 generator와 N의 비교를 탈출 조건으로 두었다. 반복문을 탈출할 때 까지 값을 못찾으면 해당 분해값을 만들 수 있는 generator가 없는 것이므로, 0을 출력한다.

```cpp
do {
    digitSum = 0;
    temp = generator;
    
    while(temp > 0) {
        digitSum += temp%10;
        temp /= 10;
    }
    
    digitSum += generator;
    
    if(digitSum == N) {
        cout << generator;
        return 0;
    }
    
} while (++generator < N);

cout << '0';
```

---

## 코멘트

분해합은 digitSum, 생성자는 generator이다. constructor 일 줄 알았는데... ㅋㅋㅋ

## 고민

처음에는 생성자를 몇 부터 검사할 지 애매해서 0부터 끝까지 끌고 올라갔는데 여기에서 시간이 4ms가 소요되었다. 이게 영 아닌 것 같아서 개선하려고 고민했는데, 자리수는 주어졌고 각 자리에 들어올 수 있는 가장 큰 수가 9라는 점을 이용하면 쉽게 해결이 가능하더라.

---

## 코드

```cpp
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    
    // generator의 초깃값은 N이 4자리라면 ABCD - (ABCD가 모두 최댓값일 때 가질 최대 부분 = 9, 9, 9, 9 ... 4x9) 이다. 이 값보다 작은 값에서 생성자가 나올 수 없다.
    int digitSum, generator = 0, temp = 1;
    while(temp < N) {
        temp *= 10;
        generator += 9;
    }
    generator = N - generator;
    
    do {
        digitSum = 0;
        temp = generator;
        
        while(temp > 0) {
            digitSum += temp%10;
            temp /= 10;
        }
        
        digitSum += generator;
        
        if(digitSum == N) {
            cout << generator;
            return 0;
        }
        
    } while (++generator < N);
    
    cout << '0';
	return 0;
}
```