# 행렬 제곱

문제 번호: 10830
알고리즘 분류: 수학, 분할 정복
푼 날짜: 2021년 3월 32일 오후 8:27

## 문제링크

[https://www.acmicpc.net/problem/10830](https://www.acmicpc.net/problem/10830)

## 문제
크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

## 입력
첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

## 출력
첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설
[https://seokjin2.tistory.com/9](https://seokjin2.tistory.com/9) 에서 풀이를 참고하였다. 

입력받은 행렬을 주어진 값만큼 제곱하면 된다. 행렬의 제곱하는 방법은 자주 해서 알지만, 이를 분할 정복으로 쪼개서 어떻게 적용해야 빠르게 해결할 수 있을 지가 관건인 문제. 만약 100의 제곱이라면 100 <- 50 <- 25 <- 12 <- 6 <- 3 <- 1 로 쪼개어 1승일 때부터 결과 자체를 제곱하면 빠르게 해결할 수 있다.


## 풀이
행렬을 나타내기 위해 2차원 벡터를 사용해주었고, 이를 `typedef`를 이용해 `matrix`로 정의해주었다.
```cpp
typedef vector<vector<long long>> matrix;
```

행렬 곱에 대해 아래와 같이 정의해주었다. matrix 에 대한 연산자인 *을 재정의 해주었다.
```cpp
matrix operator * (const matrix &A, const matrix &B) {
    int size = A.size();
    matrix result(size, vector<long long>(size));

    for(int row = 0; row < size; row++) {
        for(int column = 0; column < size; column++) {
            for(int p = 0; p < size; p++) {
                result[row][column] += A[row][p] * B[p][column];
            }
            result[row][column] %= 1000;
        }
    }

    return result;
}
```

주어진 값 만큼 제곱하는 함수를 아래와 같이 작성하였다. N을 2로 나누면서 값을 찾아나서는 것은 N을 2진수로 변환했을 때 값을 찾는 것과 같다. N이 100이라 할 때 예시를 들어보면 아래와 같다. 2로 나누면서 A를 계속 제곱시키고, 나눈 나머지가 1이면 (right shift하면서 1이 LSB에 오면) A를 result에 곱해준다.
```
100 = 1100100 (2)

A를 제곱시키면서 A^4가 되었을 때 result에 곱하기
A^32가 되었을 때 result에 곱하기
A^64가 되었을 때 result에 곱하기

=> result = A^4 * A^32 * A^64 = A^100
```

이를 코드로 옮기면 아래와 같다.
```cpp
matrix multiply(matrix A, long long N) {
    int size = A.size();
    matrix result(size, vector<long long>(size));

    for(int i = 0; i < size; i++) {
        result[i][i] = 1;
    }

    while(N > 0) {
        if(N % 2 == 1) {
            result = result * A;
        }
        N /= 2;
        A = A * A;
    }

    return result;
}
```

행렬을 출력하는 코드는 아래와 같이 작성할 수 있다.
```cpp
void print(const matrix& A) {
    int size = A.size();

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}
```

아래 코드를 main에서 실행시켜주면 원하는 결과를 얻을 수 있다. B의 값이 굉장히 크기 때문에, int로 선언해주면 틀렸다고 나오니 주의가 필요하다!
```cpp
    long long N, B;
    cin >> N >> B;

    matrix A(N, vector<long long> (N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    print(multiply(A, B));
```


---

## 코멘트
어렵네.. ㅎㄷㄷ 연산자 재정의는 처음 해본 것 같다. 이런 방법도 있구나. 되게 깔끔하네.

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

void print(const matrix&);

matrix operator * (const matrix &A, const matrix &B) {
    int size = A.size();
    matrix result(size, vector<long long>(size));

    for(int row = 0; row < size; row++) {
        for(int column = 0; column < size; column++) {
            for(int p = 0; p < size; p++) {
                result[row][column] += A[row][p] * B[p][column];
            }
            result[row][column] %= 1000;
        }
    }

    return result;
}

matrix multiply(matrix A, long long N) {
    int size = A.size();
    matrix result(size, vector<long long>(size));

    for(int i = 0; i < size; i++) {
        result[i][i] = 1;
    }

    while(N > 0) {
        if(N % 2 == 1) {
            result = result * A;
        }
        N /= 2;
        A = A * A;
    }

    return result;
}

void print(const matrix& A) {
    int size = A.size();

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {

    long long N, B;
    cin >> N >> B;

    matrix A(N, vector<long long> (N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    print(multiply(A, B));
    return 0;
}
```

---

## 문제 해결에 대한 고민
처음에는 A, temp, result 2차원 배열을 만들어 이렇게 저렇게 하려고 했는데, 이상하게 꼬여서 블로그를 찾아보면서 풀이를 작성하였다. 되게 어렵네. 아직은 포인터랑 배열을 잘 못다루는 것 같다.
