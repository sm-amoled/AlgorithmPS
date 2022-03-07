# 곱셈

문제 번호: 1629
알고리즘 분류: 분할 정복, 수학
푼 날짜: 2021년 3월 20일 오후 10:18

## 문제링크

[https://www.acmicpc.net/problem/1629](https://www.acmicpc.net/problem/1629)

## 문제

자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

## 출력

첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

## 조건

- 시간 제한 : 0.5s
- 메모리 제한 : 128MB

---

## 해설

굳이 A^B의 전체 수를 구한 다음 C로 나누어 나머지를 구하지 말고, 계속해서 나머지를 이용해 그 다음 나머지를 구해나가면 작은 메모리 안에서 해결이 가능하다.

```
A B C 가 10 11 12라고 하면 result는 A^B % C 와 같다. 

A   = (C x A') + K1
A^2 = ((C x A') + K1)^2 = C x ( ... ) + K1^2
→ 필요한 건 결국 나머지 값끼리의 곱 (다른 값들은 C의 배수)

A^P에서의 C로 나눈 나머지를 Kp 라고 한다면 
K11 → ((K5 * K5) * K1) % C
K5  → ((K2 * K2) * K1) % C
K2  → (K1 * K1) % C
K1  → A % C
```

![%E1%84%80%E1%85%A9%E1%86%B8%E1%84%89%E1%85%A6%E1%86%B7%20a4d0e3ffc66d4ccbade322c28c0f738e/86A249BD-CFD6-4909-80A5-EB18A4B2BBA1.jpeg](%E1%84%80%E1%85%A9%E1%86%B8%E1%84%89%E1%85%A6%E1%86%B7%20a4d0e3ffc66d4ccbade322c28c0f738e/86A249BD-CFD6-4909-80A5-EB18A4B2BBA1.jpeg)

위와 같은 방법으로 지수가 1일 때부터 필요한 값들을 만들면서 올라오면  필요한 나머지를 구할 수 있다. 여기에서 P가 홀수일 때는 3개의 나머지를 곱하게 되는데, 만약 C 값이 2^32에 가까워서, 곱해줄 나머지 값들도 2^32에 가깝다면 3개의 나머지를 곱했을 때 2^96에 가까운 값이 나오게 되므로 `long long` 자료형을 사용해도 정상적으로 값을 담을 수 없다. 따라서 우리가 필요한 값만 사용해주면 되므로, `((K^P’ * K^P’ % C) * K1) % C` 와 같은 식을 사용하여 미리 나머지를 구해 `long long` 자료형의 범위인 2^64 범위 내에 담을 수 있게 해준다.

## 풀이

B에 대해 B/2일때의 값을 temp에 저장하여 B일때의 나머지를 반환해준다. 여기에서 B가 짝수라면 B/2일때의 값을 그대로 두 번 곱해 나머지를 구해주면 되고, B가 홀수라면 위에서 구한 나머지에 A를 한 번 더 곱해 나머지를 구해준다.

```cpp
long long remains(int A, int B, int C) {
    if(B == 1) return A % C;
    
    long long temp = remains(A, B/2, C);
    
    if(B % 2 == 0) {
        return (temp*temp) % C;
    } else {
        return ((temp*temp) % C * A) % C;
    }
}
```

A, B, C를 입력받은 후 아래 코드를 실행시키면 원하는 결과를 얻을 수 있다.

```cpp
cout << remains(A, B, C);
```

---

## 코멘트

생각보다 어려웠다. 이런 풀이방법도 분할 정복에 들어가는구나...

---

## 코드

```cpp
#include <iostream>
#include <math.h>

using namespace std;

long long remains(int A, int B, int C) {
    if(B == 1) return A % C;
    
    long long temp = remains(A, B/2, C);
    
    if(B % 2 == 0) {
        return (temp*temp) % C;
    } else {
        return ((temp*temp) % C * A) % C;
    }
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    cout << remains(A, B, C);
        
    return 0;
}
```

---

## 문제 해결에 대한 고민

처음에는 B를 찾아갈 때 까지 나머지에 계속 A를 곱하면서 B의 카운트를 1씩 올리려고 했었다. 이 경우의 시간복잡도는 O(B). 근데 B가 2^32의 값을 가지면서 시간초과가 뜨더라. 그래서 생각해낸 방법이 위에처럼 반으로 접으면서 해결하는 방법이고, O(log B)의 시간복잡도를 갖는다. 이런 것도 분할정복에 들어가는군.

```cpp
#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int remain = 1;
    
    for(int i = 0; i < B; i++) {
        remain = remain * A % C;
    }
    
    cout << remain;
        
    return 0;
}
```