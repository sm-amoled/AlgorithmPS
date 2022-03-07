# 숫자 카드 2

문제 번호: 10816
알고리즘 분류: 이분 탐색
푼 날짜: 2021년 1월 30일 오후 2:29

### 문제 링크

[https://www.acmicpc.net/problem/10816](https://www.acmicpc.net/problem/10816)

## 문제

숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

## 출력

첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

정렬된 배열에서 특정 값 이상의 원소 중 가장 작은 index를 반환하는 `lower_bound()` 함수와 특정 값 초과 원소 중 가장 작은 index를 반환하는 `upper_boud()` 함수를 이용하여 해결하는 문제이다.

## 풀이

[ 정답 코드는 맨 아래에 있습니다 ]

vector로 카드의 값들을 입력받고, 카드에 적힌 숫자들은 탐색 알고리즘을 사용하기 위해 정렬해주었다. 

```cpp
int N;
cin >> N;
vector<int> card(N);

for(int i = 0; i < N; i++) {
	  cin >> card[i];
}

sort(card.begin(), card.end());
```

찾고자 하는 숫자는 입력과 동시에 처리 후 출력한다. `upper_bound()`함수를 사용하면 내가 원하는 값의 원소+1의 index를 얻을 수 있고, `lower_bound()`함수를 사용하면 내가 원하는 값의 첫 index를 얻을 수 있다. 따라서 `upper_bound() - lower_bound()`를 실행하면 원하는 원소의 개수를 결과로 얻을 수 있다. ( 1 2 2 2 3 일 때, index로는 4 - 1 = 3 → 3개)

```cpp
int M;
cin >> M;

for(int i =0; i < M; i++) {
    int num;
    cin >> num;
    
    cout << upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num) << " ";
}
```

`upper_bound`, `lower_bound` 함수는 인자로 `탐색 시작 주소값, 탐색 끝 주소값, 찾으려는 값`을 받는다. 

이렇게 하면 근데 입력시간이 병목이 되어 **시간 초과가 뜬다!**

```cpp
ios_base::sync_with_stdio(0);
cin.tie(0);
```

main 함수에 위 두 줄을 추가해주면 `cin()`, `cout()` 을 통한 input, output에 걸리는 시간을 줄여 코드 실행 속도를 올려준다.

---

## 고민1

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, M;
    int temp;
    vector<int> card, target;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        scanf("%d", &temp);
        card.push_back(temp);
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        scanf("%d", &temp);
        target.push_back(temp);
    }
    
    sort(card.begin(), card.end());
    
    // for(auto x : card) {
    //     printf("%d ", x);
    // }
    
    int left, right, mid, minIndex, count;
    int targetNumb;
    for(int i = 0; i < M; i++) {
        left = 0; right = N-1; minIndex = N; count = 0;
        targetNumb = target.at(i);
      
        while(left <= right) {
            mid = (left+right)/2;
            // printf("-> %d %d %d\n", mid, card.at(mid),targetNumb);
            if(mid == 0) {
                if(targetNumb > card.at(mid)) {
                    left = mid + 1;
                    minIndex = left;
                } else {
                    minIndex = 0;
                    break;
                }
            }
            
            if(targetNumb == card.at(mid)) {
                while(targetNumb == card.at(mid-1)) {
                    mid--;
                    if(mid == 0) break;
                }
                minIndex=mid;
                break;
            } else if(targetNumb < card.at(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
                minIndex = left;
            }
        }
        
        if(0 <= N && minIndex < N) {
            while(target.at(i) == card.at(minIndex)) {
                count++;
                if(++minIndex >= N) {
                    break;
                }
            }
        }
        
        cout << count << " ";
    }
    
   return 0;
}
```

이렇게 만들어봤는데, 시간초과가 뜨더라... 위에 있는 입출력 시간을 줄여주는 코드를 사용해보고 cin, cout으로도 바꿔봤는데, 오래걸리는 걸 보니 알고리즘 자체가 시간이 더 걸리는건가봐. ㅠㅠ 그래서 밑에 코드로 개선을 해봤다.

## 고민 2

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct tar {
    int index;
    int number;
    int count;
};

bool sortIndex (tar a, tar b) {
    return a.index < b.index;    
}

bool sortNumber (tar a, tar b) {
    return a.number < b.number;
}

int main() {
    int N, M;
    int temp;
    vector<int> card;
    vector<tar> target;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        scanf("%d", &temp);
        card.push_back(temp);
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        scanf("%d", &temp);
        target.push_back({i, temp});
    }

    sort(card.begin(), card.end());
    sort(target.begin(), target.end(), sortNumber);
    
    int left, right, mid;
    int count, indexStart, leftStart = 0;
    
    for(int i = 0; i < M; i++) {
        count = 0; indexStart = -1;
        left = leftStart; right= N-1;
        
        while(left <= right) {
            mid = (left+right)/2;
            // printf("-> %d %d %d\n", mid, card.at(mid),target.at(i).number);

            if(target.at(i).number < card.at(mid)) {
                right = mid-1;
            } else if (target.at(i).number > card.at(mid)) {
                left = mid+1;
            } else {
                left = right+1;
                indexStart = mid;
            }
        }
        
        if(indexStart == -1) {
            continue;
        }
        
        while(target.at(i).number == card.at(indexStart)) {
            if(indexStart == 0) { indexStart--; break; } 
            indexStart--; 
        }
        indexStart += 1; // indexStart에서 원하는 값 시작!
        
        while(target.at(i).number == card.at(indexStart)) {
            indexStart++;
            count++;
            if(indexStart == N) { indexStart = N-1; break;}
        }
        
        target.at(i).count = count;
    }
    
    sort(target.begin(), target.end(), sortIndex);
    
    for(int i = 0; i < M; i++) {
        printf("%d ", target.at(i).count);    
    }
    
   return 0;
}
```

이 친구도 역시나 시간초과가 떴다. 이 알고리즘은 맞추고자 하는 수도 정렬을 해서 이분 탐색을 하는 범위 자체를 점점 줄여나가는 컨셉이였는데, 아무래도 sort 알고리즘이 3번 나오고 했던게 패인이 아닌가 싶다. ㅠㅠㅠ

## 코멘트

시간 초과가 진짜 빡치는 것 같아... 알고리즘 개량해서 더 개선했는데 59%에서 시간 초과로 멈추고, 통과한 밑에있는 코드는 2%에서 시간초과로 멈추다가 입출력 병목 개선하는 코드 넣으니깐 바로 통과하더라. 내 5시간은 어디로 간건가... 알고리즘 트레이닝 책 찾아보니깐 병목 개선하는 코드가 2장에 나와있더라고... 이거 한 번 써볼걸 그랬네. 역시 사람은 당해야 기억을 하게 되는 것 같다 ㅋㅋㅋㅋㅋㅋ 시발....

```cpp
ios_base::sync_with_stdio(0);
cin.tie(0);
```

---

## 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> card(N);
    
    for(int i = 0; i < N; i++) {
        cin >> card[i];
    }
    
    sort(card.begin(), card.end());
    
    int M;
    cin >> M;
    
    for(int i =0; i < M; i++) {
        int num;
        cin >> num;
        
        cout << upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num) << " ";
    }
    return 0;
}
```