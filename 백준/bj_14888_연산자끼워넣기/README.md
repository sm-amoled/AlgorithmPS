# 연산자 끼워넣기

문제 번호: 14888
알고리즘 분류: 백 트래킹
푼 날짜: 2021년 3월 7일 오후 3:06

## 문제링크

[https://www.acmicpc.net/problem/14888](https://www.acmicpc.net/problem/14888)

## 문제

N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.

우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.

예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 있다. 예를 들어, 아래와 같은 식을 만들 수 있다.

- 1+2+3-4×5÷6
- 1÷2+3+4-5×6
- 1+2÷3×4-5+6
- 1÷2×3-4+5+6

식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다. 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.

- 1+2+3-4×5÷6 = 1
- 1÷2+3+4-5×6 = 12
- 1+2÷3×4-5+6 = 5
- 1÷2×3-4+5+6 = 7

N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.

## 출력

첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다. 연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 또한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 512MB

---

## 해설

모든 경우에 대해 검사하여 최대, 최소값을 찾는 백트래킹 문제이다. 

가장 앞에있는 원소부터 차례대로 바로 뒤의 원소와 남아있는 연산자 중 하나를 선택해 연산을 진행하고, 그 결과를 다시 그 다음 원소와 남아있는 연산자 중 하나를 선택해 연산을 진행하면서 재귀적으로 연산을 시도한다. 모든 연산자를 사용하면 최대, 최소값과 비교하여 유의미하다면 최대, 최소값에 대입해준다. 

## 풀이

연산을 진행하는 백트래킹 함수에서 인자로 받지 않고도 입력받아둔 값에 접근할 수 있도록 배열과 벡터를 전역 변수로 선언해주었다. op는 연산자의 개수를 저장하고, A 벡터는 연산에 사용될 숫자들을 순서대로 저장한다. 연산의 결과가 최대 1억, 최소 -1억이라고 하였으므로 아래와 같이 초기값을 지정하여 비교문을 통해 적절한 값을 저장할 수 있도록 만들어주었다.

```cpp
int minValue = 1000000001, maxValue = -1000000001;
int N, op[4];
vector<int> A;
```

위 공간들에 입력받은 값을 적절하게 저장해준다.

```cpp
cin >> N;
for(int i = 0; i < N; i++) {
    int temp; cin >> temp;
    A.push_back(temp);
}
for(int i = 0; i < 4; i++) {
    cin >> op[i];
}
```

연산을 수행하는 함수 `findMinMax`를 만들어주었다. 이전에 연산한 결과를 전달할 인자인 `beforeResult`, 이번 연산에 필요한 피연산자를 가져오기 위해 index를 지정해주는 `index`를 인자로 사용한다. 4개의 op에 대해 아직 사용하지 않은 연산자를 순서대로 가져와 하나씩 넣어 계산을 수행하고, 그 결과를 다음 `findMinMax`에게 인자로 전달한다. 다음 숫자와 이번 연산 결과를 연산해야하니, `index+1`도 수행해준다. op를 하나 사용했으므로, 호출된 하위 함수에서 해당 연산자가 중복사용되는 것을 막기 위해 `op[i]-—`을 수행한 뒤 함수를 호출한다. 만약 호출된 함수가 연산을 마무리하고 반환되면(지금 연산자에 대해 그 다음 연산자들의 경우의 수가 모두 탐색된 경우) 지금 사용한 연산자를 돌려놓고(`op[i]++`) 다음 연산자에 대해 탐색한다.

```cpp
void findMinMax(int beforeResult, int index) {
    int nextResult;
    for(int i = 0; i < 4; i++) {
        if(op[i]) {
            op[i]--;
            switch(i) {
                case 0 : 
                    nextResult = beforeResult + A[index];
                    break;
                case 1 :
                    nextResult = beforeResult - A[index];
                    break;
                case 2 :
                    nextResult = beforeResult * A[index];
                    break;
                case 3 :
                    nextResult = beforeResult / A[index];
                    break;
                }
            findMinMax(nextResult, index+1);
            op[i]++;
        }
    }
}
```

이 함수의 종료 조건은 모든 연산자를 사용했을 때이다. 이는 피 연산자가 0개 남았다는 뜻과도 같다. 따라서 인자로 전달된 index의 값이 N이라면 (N-1번 index까지 있는 피연산자를 모두 사용한 경우) 최소값과 최댓값을 update해주고 함수를 종료한다. 이 코드를 추가하면 `findMinMax` 함수는 아래와 같은 형태를 갖는다.

```cpp
void findMinMax(int beforeResult, int index) {
    if(index == N) {
        if(minValue > beforeResult) minValue = beforeResult;
        if(maxValue < beforeResult) maxValue = beforeResult;
        return;
    }
    
    int nextResult;
    for(int i = 0; i < 4; i++) {
        if(op[i]) {
            op[i]--;
            switch(i) {
                case 0 : 
                    nextResult = beforeResult + A[index];
                    break;
                case 1 :
                    nextResult = beforeResult - A[index];
                    break;
                case 2 :
                    nextResult = beforeResult * A[index];
                    break;
                case 3 :
                    nextResult = beforeResult / A[index];
                    break;
                }
            findMinMax(nextResult, index+1);
            op[i]++;
        }
    }
}
```

이제 main 함수에서 아래 코드를 실행해주면 원하는 결과를 얻을 수 있다. 가장 처음 연산에서는 이전에 연산된 결과가 없으므로, `beforeResult`는 `A[0]`으로, 연산을 시작하는 피연산자의 index를 1부터로 지정하여 `A[0], A[1]`끼리의 연산부터 시작하도록 해주었다. 

```cpp
// back tracking
findMinMax(A[0], 1);

cout << maxValue << '\n' << minValue;
```

---

## 코멘트

백 트래킹 문제라는 걸 알아서 쉽게 풀었던거지, 만약에 이 문제의 유형을 몰랐으면 최대, 최소로 만드는 경우의 조건을 따져서 유효한 계산만 수행하려고 했을 것 같다. 아마 그게 시간복잡도, 성능 면에서는 더 좋겠지만, 그만큼 문제를 해결하기에는 더 어려웠겠지?

---

## 코드

---

```cpp
#include <iostream>
#include <vector>

using namespace std;

int minValue = 1000000001, maxValue = -1000000001;
int N, op[4];
vector<int> A;

void findMinMax(int beforeResult, int index) {
    if(index == N) {
        if(minValue > beforeResult) minValue = beforeResult;
        if(maxValue < beforeResult) maxValue = beforeResult;
        return;
    }
    
    int nextResult;
    for(int i = 0; i < 4; i++) {
        if(op[i]) {
            op[i]--;
            switch(i) {
                case 0 : 
                    nextResult = beforeResult + A[index];
                    break;
                case 1 :
                    nextResult = beforeResult - A[index];
                    break;
                case 2 :
                    nextResult = beforeResult * A[index];
                    break;
                case 3 :
                    nextResult = beforeResult / A[index];
                    break;
                }
            findMinMax(nextResult, index+1);
            op[i]++;
        }
    }
}

int main() {
    
    // input
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp; cin >> temp;
        A.push_back(temp);
    }
    for(int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    
    // back tracking
    findMinMax(A[0], 1);
    
    cout << maxValue << '\n' << minValue;
    
	return 0;
}
```