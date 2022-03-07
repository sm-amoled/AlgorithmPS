# 국영수

문제 번호: 10825
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 27일 오후 7:27

### 문제 링크

[https://www.acmicpc.net/problem/10825](https://www.acmicpc.net/problem/10825)

## 문제

도현이네 반 학생 N명의 이름과 국어, 영어, 수학 점수가 주어진다. 이때, 다음과 같은 조건으로 학생의 성적을 정렬하는 프로그램을 작성하시오.

1. 국어 점수가 감소하는 순서로
2. 국어 점수가 같으면 영어 점수가 증가하는 순서로
3. 국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
4. 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)

## 입력

첫째 줄에 도현이네 반의 학생의 수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 한 줄에 하나씩 각 학생의 이름, 국어, 영어, 수학 점수가 공백으로 구분해 주어진다. 점수는 1보다 크거나 같고, 100보다 작거나 같은 자연수이다. 이름은 알파벳 대소문자로 이루어진 문자열이고, 길이는 10자리를 넘지 않는다.

## 출력

문제에 나와있는 정렬 기준으로 정렬한 후 첫째 줄부터 N개의 줄에 걸쳐 각 학생의 이름을 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

`sort()` 함수에 비교 함수를 직접 만들어 넣어줄 수 있다. 국어 점수를 내림차순으로, 영어 점수를 오름차순으로, 수학 점수를 내림차순으로, 이름을 오름차순으로 정렬하는 비교함수 `cmp`를 만들어 실행시켜주면 된다.

## 풀이

이름, 국어, 영어, 수학 점수를 담고있기 위해 구조체를 선언해주었다. string input을 받아오기 위해 `cin`을 이용하였고, 나머지는 `scanf`로 받아왔다. 구조체에 값을 넣어 vector에 push 하면서 데이터를 입력받는다.

국어, 영어, 수학, 이름을 비교하는 함수는 아래와 같이 만들어주었다. 국어 성적이 같을 때 / 아닐 때를 나누어 계산했다. return 에서 오름차순의 경우 ‘<‘, 내림차순의 경우 ‘>’로 설정해주면 된다.

```cpp
bool cmp(student a, student b) {
    if(a.korean == b.korean) {
        if(a.english == b.english) {
            if(a.math == b.math) {
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.english < b.english;
    }
    return a.korean > b.korean;
}
```

---

## 코멘트

string 타입으로 데이터를 받아올 때는 `scanf()`를 사용할 수 없다. 대신 char[]로 받아서 복사하거나 `cin()`, `getline()` 을 이용하면 된다.

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct student {
    string name;
    int korean;
    int english;
    int math;
};

bool cmp(student a, student b) {
    if(a.korean == b.korean) {
        if(a.english == b.english) {
            if(a.math == b.math) {
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.english < b.english;
    }
    return a.korean > b.korean;
}

int main() {
    int count;
    cin >> count;

    vector<student> studV;
    student std;
    int tempKor, tempEng, tempMath;
    string tempName;

    for(int i = 0; i < count; i++) {
        cin >> tempName;
        scanf("%d %d %d", &tempKor, &tempEng, &tempMath);
        std = student {tempName, tempKor, tempEng, tempMath};
        studV.push_back(std);    
    }

    sort(studV.begin(), studV.end(), cmp);

    for(int i = 0; i < count; i++) {
       cout << studV.at(i).name << '\n';
    }
    return 0;
}
```