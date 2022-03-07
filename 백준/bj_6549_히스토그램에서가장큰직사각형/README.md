# 히스토그램에서 가장 큰 직사각형

문제 번호: 6549
알고리즘 분류: 스택
푼 날짜: 2021년 2월 13일 오후 3:41

## 문제링크

[https://www.acmicpc.net/problem/6549](https://www.acmicpc.net/problem/6549)

## 문제

히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.

![https://www.acmicpc.net/upload/images/histogram.png](https://www.acmicpc.net/upload/images/histogram.png)

히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

## 입력

입력은 테스트 케이스 여러 개로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000) 그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다. 이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다. 모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

## 출력

각 테스트 케이스에 대해서, 히스토그램에서 가장 넓이가 큰 직사각형의 넓이를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

꽤나 어려웠던 문제라고 생각한다. 스택에 유의미한 정보만을 남기고 나머지는 pop하면서 뒤로 넘어가면 풀 수 있는 문제이다. 

오름차순으로 올라가는 값들이 계속 나올 때는 뒤에서도 사용될 높이들이기에 의미가 있는 값이지만, 감소하는 값이 나오면 앞에 나왔던 높이들은 작은 값 때문에 그 위로는 의미가 없어진다. 이 점을 이용해 높은 값들을 stack에서 pop해주면 된다.

## 풀이

히스토그램이 아래 예시처럼 있다고 할 때, 중요한 포인트는 높이가 감소할 때이다. 만약 높이가 계속 증가하고 있다면 그 다음 칸에서 넓이를 계산할 때 앞에 있는 높이들이 얼마나 사용될 지 모르지만, 감소한다면 얼마나 높든 뒤에서 사각형을 만들 때 필요한 높이를 충족한다는 것만이 의미를 갖기 때문이다.

![%E1%84%92%E1%85%B5%E1%84%89%E1%85%B3%E1%84%90%E1%85%A9%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7%E1%84%8B%E1%85%A6%E1%84%89%E1%85%A5%20%E1%84%80%E1%85%A1%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B3%E1%86%AB%20%E1%84%8C%E1%85%B5%E1%86%A8%E1%84%89%E1%85%A1%E1%84%80%E1%85%A1%E1%86%A8%E1%84%92%E1%85%A7%E1%86%BC%20db83e4f474a04d4aa4f9aaef46711c96/575AA3BF-A35E-423D-8531-1A6E38EE6778.jpeg](575AA3BF-A35E-423D-8531-1A6E38EE6778.jpeg)

이를 구현하기 위해 stack 벡터에서는 histogram 벡터의 index를 관리한다. stack에 남게되는 원소들은 필요한 높이들이다. 만약 이번 차례에 처리하는 원소가 지난 원소에 비해 증가했다면 index를 stack에 push만 하고 넘어간다. 그러나 만약 감소했다면, 해당 원소가 포함되기 이전에 만들 수 있는 사각형들을 만들어보고 의미있는 원소까지만 stack에 남긴다.

![%E1%84%92%E1%85%B5%E1%84%89%E1%85%B3%E1%84%90%E1%85%A9%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7%E1%84%8B%E1%85%A6%E1%84%89%E1%85%A5%20%E1%84%80%E1%85%A1%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8F%E1%85%B3%E1%86%AB%20%E1%84%8C%E1%85%B5%E1%86%A8%E1%84%89%E1%85%A1%E1%84%80%E1%85%A1%E1%86%A8%E1%84%92%E1%85%A7%E1%86%BC%20db83e4f474a04d4aa4f9aaef46711c96/20E3A481-8F4F-4287-BAE0-657BFCC6FE90.jpeg](20E3A481-8F4F-4287-BAE0-657BFCC6FE90.jpeg)

stack에 저장되어있는 값에서 `histogram[stack.back()]` 이 h의 값을 갖고, `i - stack.back() - 1`이 l의 값을 갖는다. 이를 이용해 사각형의 넒이를 구하고 현재까지 구한 넓이와 비교해 저장한다. 이후 계산된 원소는 어차피 앞에 계산할 원소들 / 뒤에 추가될 원소보다 값이 크기 때문에 자리를 차지하는 것만 의미가 있기 때문에 (어차피 높이 조건은 무조건 충족하므로) stack에서 pop해준다. l을 계산할 때는 index로 하기 때문에 포함된다. 

이를 코드로 구현하면 아래와 같다.

```cpp
for(int i = 0; i < n; i++) {
    while(!stack.empty() && histogram[i] < histogram[stack.back()]) {
        long h = histogram[stack.back()];
        stack.pop_back();
        long l = i;
        
        if(!stack.empty())
             l = i - stack.back() - 1;
        if(result < l*h) result = l*h;
    }
    
    stack.push_back(i);
}
```

위 코드가 돌아가고 나서도 stack이 비어있지 않을 수 있다. (계속 오름차순으로 올라가다가 입력이 종료된 경우) 이러한 경우에는 stack이 빌 때 까지 넓이를 구하며 결과를 내면 된다. 

```cpp
while(!stack.empty()) {
    long h = histogram[stack.back()];
    long l = n;
    stack.pop_back();
    
    if(!stack.empty())
        l = n - stack.back() - 1;
    if(result < l*h) 
        result = l*h;
}
```

위 코드를 거치고 나면 result에 최댓값이 들어있다. 

---

## 코멘트

[https://yangorithm.tistory.com/165](https://yangorithm.tistory.com/165)

붙잡고 있는데 도저히 모르겠어서 여기에서 코드를 보고 공부했다. 다른 곳은 세그먼트 트리를 사용하던데, 나는 세그먼트 트리를 아직 공부안해서 스택으로 구현하려다 보니 여기가 제일 깔끔하고 이해할만한 코드를 갖고 있는 것 같더라. 

스택 문제를 풀 때 중요한 점 : **뒤에서 앞 원소에 접근할 때 더이상 필요없는 부분은 pop 해버리기. ← 시간을 아낄 수 있다.**

## 고민

일반적인 방식으로 해결하려 했는데, 시간초과가 난다. 역시 스택을 이용해서 의미없는 값을 줄이는 과정을 거쳐야했나보다.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while(true) {
        int N;
        cin >> N; 
    
        if(N==0) return 0;
        
        vector<int> histogram(N);
        for(int i = 0; i < N; i++) {
            cin >> histogram[i];
        }
        
        long result = 0;
        for(int i = 0; i < N; i++) {
            int height = histogram[i];
            
            int k=i, j=i; 
            
            while(histogram[k] >= height) {
                k--;
                if(k < 0) break;
            }
            k++;
            
            while(histogram[j] >= height) {
                j++;
                if(j > N-1) break;
            }
            j--;
            
            result = (result > (j-k+1)*height)? result:(j-k+1)*height;
            // cout << "height : " << height << " result : " << result << "\n";
        }
     
        cout << result << "\n";
    }
    
   return 0;
}
```

---

## 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while(true) {
        int n;
        cin >> n; 
    
        if(n==0) return 0;
        
        vector<int> histogram(n);
        vector<int> stack;
        
        for(int i = 0; i < n; i++) {
            cin >> histogram[i];
        }
        
        long result = 0;
        
        for(int i = 0; i < n; i++) {
            while(!stack.empty() && histogram[i] < histogram[stack.back()]) {
                long h = histogram[stack.back()];
                stack.pop_back();
                long l = i;
                
                if(!stack.empty())
                     l = i - stack.back() - 1;
                if(result < l*h) result = l*h;
            }
            
            stack.push_back(i);
        }
        
        while(!stack.empty()) {
            long h = histogram[stack.back()];
            long l = n;
            stack.pop_back();
            
            if(!stack.empty())
                l = n - stack.back() - 1;
            if(result < l*h) 
                result = l*h;
        }
        
        cout << result << '\n';
    }
    
   return 0;
}
```