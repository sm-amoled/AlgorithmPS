# 가장 긴 증가하는 부분 수열 2

문제 번호: 12015
알고리즘 분류: LDS, 이분 탐색
푼 날짜: 2021년 1월 31일 오후 1:06

### 문제 링크

[https://www.acmicpc.net/problem/12015](https://www.acmicpc.net/problem/12015)

## 문제

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {**10**, **20**, 10, **30**, 20, **50**} 이고, 길이는 4이다.

## 입력

첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)

## 출력

첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 512MB

---

## 해설

증가하는 부분 순열 문제(LDS)를 푸는 알고리즘 중 O(n^2)을 이용하면 시간 초과로 해결할 수 없는 문제이다. O(n logn)의 시간복잡도를 갖는 알고리즘을 이용해 해결할 수 있다. 

## 풀이

이 문제에서 원하는 결과는 부분 수열의 최장 길이이므로, maxLength 변수를 하나 선언해주었다.

```cpp
for(int i = 0; i < N; i++) {
    
    // 제일 긴 값보다 더 길면?
    if(X[maxLength] < A[i]) {
        X[++maxLength] = A[i];
    }
    // 중간에 들어올 수 있는 값이면?
    else {
        int left = 0, right = maxLength;
        while(left < right) {       
            int mid = (left+right)/2;
            
            if(X[mid] >= A[i]) {    
                right = mid;        
            } else {
                left = mid + 1;
            }
        }
        
    // A[i]보다 큰 최소인 수랑 바꾸기
        X[left] = A[i];
    }
}

```

여기에서 X 배열은 한 번 지나간 수를 저장하는 배열이며, 크기는 N으로 지정하고 선언하면서 값을 0으로 초기화해주었다.

![%E1%84%80%E1%85%A1%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%80%E1%85%B5%E1%86%AB%20%E1%84%8C%E1%85%B3%E1%86%BC%E1%84%80%E1%85%A1%E1%84%92%E1%85%A1%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%87%E1%85%AE%E1%84%87%E1%85%AE%E1%86%AB%20%E1%84%89%E1%85%AE%E1%84%8B%E1%85%A7%E1%86%AF%202%206286fa127ec14cb98cfd8a02556323a2/DC09ED97-CCB8-4B75-B139-3F68213BC7E5.jpeg](%E1%84%80%E1%85%A1%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%80%E1%85%B5%E1%86%AB%20%E1%84%8C%E1%85%B3%E1%86%BC%E1%84%80%E1%85%A1%E1%84%92%E1%85%A1%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%87%E1%85%AE%E1%84%87%E1%85%AE%E1%86%AB%20%E1%84%89%E1%85%AE%E1%84%8B%E1%85%A7%E1%86%AF%202%206286fa127ec14cb98cfd8a02556323a2/DC09ED97-CCB8-4B75-B139-3F68213BC7E5.jpeg)

X 배열의 index는 해당 원소까지 사용해서 만들 수 있는 배열 길이를 의미한다. 만약에 input이 [1 3 5] 라면 위 그림처럼 배열이 만들어진다. 여기에서 0번 index는 사용하지 않는다. 

![%E1%84%80%E1%85%A1%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%80%E1%85%B5%E1%86%AB%20%E1%84%8C%E1%85%B3%E1%86%BC%E1%84%80%E1%85%A1%E1%84%92%E1%85%A1%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%87%E1%85%AE%E1%84%87%E1%85%AE%E1%86%AB%20%E1%84%89%E1%85%AE%E1%84%8B%E1%85%A7%E1%86%AF%202%206286fa127ec14cb98cfd8a02556323a2/5B44DD16-57FF-4CDA-91C7-0B768C1B3ADD.jpeg](%E1%84%80%E1%85%A1%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%80%E1%85%B5%E1%86%AB%20%E1%84%8C%E1%85%B3%E1%86%BC%E1%84%80%E1%85%A1%E1%84%92%E1%85%A1%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%87%E1%85%AE%E1%84%87%E1%85%AE%E1%86%AB%20%E1%84%89%E1%85%AE%E1%84%8B%E1%85%A7%E1%86%AF%202%206286fa127ec14cb98cfd8a02556323a2/5B44DD16-57FF-4CDA-91C7-0B768C1B3ADD.jpeg)

현재까지 X 배열을 처리할 때 들어온 값 중에서 **입력값이 가장 큰 값이라면 maxLength에 1을 더하고, 해당 index에 저장**한다. 이는 이 원소를 사용하면 maxLength을 가진 부분 수열을 만들 수 있다는 것을 의미한다. 만약 그렇지 않다면(최대인 수가 아니라면) X 배열에서 **이 원소보다 큰 가장 작은 수를 찾아 해당 수를 대체**한다. 뒤에 계속 들어올 입력값에 대해서 작은 수가 부분 수열을 길게 만드는데 더 유리하기 때문에 바꿔주는 것이다. 이 값을 찾을 때는 X 배열에서 binary sort 알고리즘을 이용해준다. X 배열에서 정렬된 부분은 index 0 ~ index maxLength 까지이므로, 0~maxLength를 범위로 하여 찾아준다. 

```cpp
int maxLength = 0;
for(int i = 0; i < N; i++) {
    
    // 제일 긴 값보다 더 길면?
    if(X[maxLength] < A[i]) {
        X[++maxLength] = A[i];
    }
    // 중간에 들어올 수 있는 값이면?
    else {
        int left = 0, right = maxLength;
        while(left < right) {       
            int mid = (left+right)/2;
            
            if(X[mid] >= A[i]) {    
                right = mid;        
            } else {
                left = mid + 1;
            }
        }
        
    // A[i]보다 큰 최소인 수랑 바꾸기
        X[left] = A[i];
    }
}

cout << maxLength;
```

maxLength가 우리가 원하는 부분 수열의 최장 길이값이다. 

---

## 코멘트

LDS... 너란 녀석... 아직 솔직히 헷갈린다. 원래 코드는 이렇게 적었었는데, 왜 틀렸는지 고민을 해봐야할 것 같다.

고민을 하고 디버그를 좀 해봤는데, 이렇게 만들어놓으면 left가 right+1이 될 때 탈출하기 때문에, 내가 지정하고싶었던 index (바꾸려는 값이 있는 곳) + 1에 left가 위치한다. 그 상황에서 `X[left] = A[i]`를 실행하면 그 다음 원소의 값을 바꾸는 작업을 하게되어 오류가 난다. 최장 길이가 제대로 나왔던건 

```cpp
while(left <= right) {       
    int mid = (left+right)/2;
    
    if(X[mid] > A[i]) {    
        right = mid - 1;        
    } else {
        left = mid + 1;
    }
}

X[left] = A[i];
```

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N;
    cin >> N;
    vector<int> A(N); 
    int* X = new int[N] {0,};
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int maxLength = 0;
    for(int i = 0; i < N; i++) {
        
        // 제일 긴 값보다 더 길면?
        if(X[maxLength] < A[i]) {
            X[++maxLength] = A[i];
        }
        // 중간에 들어올 수 있는 값이면?
        else {
            int left = 0, right = maxLength;
            while(left < right) {       
                int mid = (left+right)/2;
                
                if(X[mid] >= A[i]) {    
                    right = mid;        
                } else {
                    left = mid + 1;
                }
            }
            
        // A[i]보다 큰 최소인 수랑 바꾸기
            X[left] = A[i];
        }
    }

    cout << maxLength;
    
    return 0;
}
```