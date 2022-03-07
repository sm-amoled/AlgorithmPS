# N과 M (1)

문제 번호: 15649
알고리즘 분류: 백 트래킹
푼 날짜: 2021년 3월 3일 오후 9:02

## 문제링크

[https://www.acmicpc.net/problem/15649](https://www.acmicpc.net/problem/15649)

## 문제

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

## 입력

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

## 출력

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 512MB

---

## 해설

선택하지 않은 수 중에서 가장 작은 수부터 차례대로 선택하는 재귀 함수를 통해 모든 경우의 수의 수열을 출력할 수 있다.

## 풀이

사전 순으로 출력을 해야하며, 수열을 만들 때 가장 마지막 원소부터 차례대로 더 큰 값으로 바뀌는 규칙에서 stack을 이용하는 방법을 생각할 수 있다. 

이를 구현하기위해 boolean 형 백터 `used`와 stack으로 사용할 벡터 `arr`를 선언해주었다. used는 수열을 만들 때 현재 해당 값이 사용되고 있는지를 기록하는 벡터이다. 만약에 1이 수열을 만들 때 사용되었다면`used[1]`이 true가 되고, 1을 수열에서 빼면 `used[1]`이 false가 된다.

```cpp
vector<bool> used(N+1, false);
vector<int> arr;
```

used, arr 벡터와 depth를 인자로 받아오는 함수 `sequence`를 정의해주었다.  여기에서 depth는 앞으로 수열에 들어와야 할 수의 개수를 말한다. 1부터 N까지의 값을 차례대로 검사하면서, K값에 대해서 만약에 수열을 만들 때 K가 사용되지 않았다면(used[K]가 false라면) 수열에 해당 값을 넣고 used[K]는 true로 체크한다. 그다음 depth 인자 값에는 depth-1을 넣어 `sequence` 함수를 재귀 호출한다. 호출한 재귀함수가 끝나면 수열에서 K 값을 pop하고, used[K]는 false로 체크한다.

```cpp
void sequence(vector<bool> used, vector<int> arr, int depth) {
		for(int i = 1; i < used.size(); i++) {
		    if(used[i] == false) {
		        arr.push_back(i);
		        used[i] = true;
		        sequence(used, arr, depth-1);
		        arr.pop_back();
		        used[i] = false;
		    }
		}
}
```

만약 depth가 0이라면 (더 이상 넣을 값이 필요가 없다면) 해당 수열이 완성되었으므로 출력만 하고 함수를 종료한다. 이를 종료하면 depth가 1인 함수 내로 다시 돌아가므로, 반복해서 수열 만들기를 실행한다.

```cpp
// 위 sequence 함수 내 제일 위에 삽입
if(depth == 0) {
    for(auto x : arr) {
        cout << x << " ";
    } cout << '\n';
    return;
}
```

### 예시

함수를 재귀호출했을 때는 어떤 일이 일어나는지 설명해보겠다. N이 8이고, 4개의 수를 담아야하는 수열에 2가 이미 들어와있다고 해보자. 

```
depth = 4
arr : [ 2 _ _ _ ]
```

여기에서 `sequence(used, arr, 3)`가 호출된다. used에서 1부터 차례로 검사하기 때문에, `used[1]`의 값을 검사한다. 수열에 1이 없으므로 1을 수열에 넣고 다음 재귀함수를 호출한다.

```
depth = 3
arr : [ 2 1 _ _ ]
```

`sequence(used, arr, 2)`를 호출하면 used에서 1부터 차례로 검사한다. 3이 처음으로 발견되는 사용하지 않은 값이므로, 수열에 3을 넣고 다음 함수를 호출한다.

```
depth = 2
arr : [ 2 1 3 _ ]
```

`sequence(used, arr, 1)`이 호출되고 used에서 4가 가장 처음으로 발견되는 사용하지 않은 값이므로, 수열에 4를 넣고 다음 함수를 호출한다.

```
depth = 1
arr : [ 2 1 3 4 ]
```

`sequence(used, arr, 0)`이 호출되면, 이미 하나의 수열이 완성되었으므로 해당 수열을 출력하고 함수를 종료한다.

```
>> 2 1 3 4
```

함수를 종료하면 다시 `sequence(used, arr, 1)`에서 depth가 0인 함수를 호출했을 때로 돌아간다. 4를 pop하고, 미사용 처리 한 뒤, 반복문을 통해 그 다음 수인 5를 검사하고, 사용중이 아니므로 5를 넣고 depth가 0인 함수를 호출한다. 

```
depth = 1
arr : [ 2 1 3 5 ]
```

이 과정을 반복하면 순차적으로 수열을 계속 바꾸면서 값을 만들어가므로, 모든 수열을 출력할 수 있다.

---

## 코멘트

깔끔한 방법이라고 생각해.

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

void sequence(vector<bool> used, vector<int> arr, int depth) {
    if(depth == 0) {
        for(auto x : arr) {
            cout << x << " ";
        } cout << '\n';
        return;
    }
    
    for(int i = 1; i < used.size(); i++) {
        if(used[i] == false) {
            arr.push_back(i);
            used[i] = true;
            sequence(used, arr, depth-1);
            arr.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> used(N+1, false);
    vector<int> arr;
    
    sequence(used, arr, M);

	return 0;
}
```