# 암기왕

문제 번호: 2776
알고리즘 분류: 이분 탐색
푼 날짜: 2021년 2월 3일 오후 11:40

## 문제링크

[https://www.acmicpc.net/problem/2776](https://www.acmicpc.net/problem/2776)

## 문제

연종이는 엄청난 기억력을 가지고 있다. 그래서 하루 동안 본 정수들을 모두 기억 할 수 있다. 하지만 이를 믿을 수 없는 동규는 그의 기억력을 시험해 보기로 한다. 동규는 연종을 따라 다니며, 연종이 하루 동안 본 정수들을 모두 ‘수첩1’에 적어 놓았다. 그것을 바탕으로 그가 진짜 암기왕인지 알아보기 위해, 동규는 연종에게 M개의 질문을 던졌다. 질문의 내용은 “X라는 정수를 오늘 본 적이 있는가?” 이다. 연종은 막힘없이 모두 대답을 했고, 동규는 연종이 봤다고 주장하는 수 들을 ‘수첩2’에 적어 두었다. 집에 돌아온 동규는 답이 맞는지 확인하려 하지만, 연종을 따라다니느라 너무 힘들어서 여러분에게 도움을 요청했다. 동규를 도와주기 위해 ‘수첩2’에 적혀있는 순서대로, 각각의 수에 대하여, ‘수첩1’에 있으면 1을, 없으면 0을 출력하는 프로그램을 작성해보자.

## 입력

첫째 줄에 테스트케이스의 개수 T가 들어온다. 다음 줄에는 ‘수첩 1’에 적어 놓은 정수의 개수 N(1 ≤ N ≤ 1,000,000)이 입력으로 들어온다. 그 다음 줄에 ‘수첩 1’에 적혀 있는 정수들이 N개 들어온다. 그 다음 줄에는 ‘수첩 2’에 적어 놓은 정수의 개수 M(1 ≤ M ≤ 1,000,000) 이 주어지고, 다음 줄에 ‘수첩 2’에 적어 놓은 정수들이 입력으로 M개 들어온다. 모든 정수들의 범위는 int 로 한다.

## 출력

수첩2’에 적혀있는 M개의 숫자 순서대로, ‘수첩1’에 있으면 1을, 없으면 0을 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 256MB

---

## 해설

이분 탐색을 이용하면 쉽게 해결할 수 있는 문제이다.

## 풀이

수첩 1에 받은 값들을 오름차순으로 정렬하여 이분 탐색 알고리즘을 적용가능하게 만들어주었다. 이분 탐색을 이용해 수첩 2에 적힌 숫자들을 차례로 탐색하여 있으면 1, 없으면 0을 출력한다.

```cpp
int numb;
for(int i = 0; i < M; i++) {
    cin >> numb;
    
    int left = 0, right = note1.size()-1;
    int result;
    while(left <= right) {
        int mid = (left+right)/2;
        
        if(note1[mid] > numb) {
            right = mid - 1;
        } else {
            result = mid;
            left = mid + 1;
        }
    }
    
    if(note1[result] == numb) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}
```

---

## 코멘트

이제 이정도 이분탐색 문제는 식은 죽 먹기!

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
    
    int T;
    cin >> T;
    for(int testCase = 0; testCase < T; testCase++) {
        int N;
        cin >> N;
        
        vector<int> note1(N);
        for(int i = 0; i < N; i++) {
            cin >> note1[i];
        }
        sort(note1.begin(), note1.end());
        
        int M;
        cin >> M;
        
        int numb;
        for(int i = 0; i < M; i++) {
            cin >> numb;
            
            int left = 0, right = note1.size()-1;
            int result;
            while(left <= right) {
                int mid = (left+right)/2;
                
                if(note1[mid] > numb) {
                    right = mid - 1;
                } else {
                    result = mid;
                    left = mid + 1;
                }
            }
            
            if(note1[result] == numb) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}
```