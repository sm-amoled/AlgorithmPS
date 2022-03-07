# 패션왕 신해빈

문제 번호: 9375
알고리즘 분류: 수학
푼 날짜: 2021년 3월 16일 오후 10:57

## 문제링크

[https://www.acmicpc.net/problem/9375](https://www.acmicpc.net/problem/9375)

## 문제

해빈이는 패션에 매우 민감해서 한번 입었던 옷들의 조합을 절대 다시 입지 않는다. 예를 들어 오늘 해빈이가 안경, 코트, 상의, 신발을 입었다면, 다음날은 바지를 추가로 입거나 안경대신 렌즈를 착용하거나 해야한다. 해빈이가 가진 의상들이 주어졌을때 과연 해빈이는 알몸이 아닌 상태로 며칠동안 밖에 돌아다닐 수 있을까?

## 입력

첫째 줄에 테스트 케이스가 주어진다. 테스트 케이스는 최대 100이다.

- 각 테스트 케이스의 첫째 줄에는 해빈이가 가진 의상의 수 n(0 ≤ n ≤ 30)이 주어진다.
- 다음 n개에는 해빈이가 가진 의상의 이름과 의상의 종류가 공백으로 구분되어 주어진다. 같은 종류의 의상은 하나만 입을 수 있다.

모든 문자열은 1이상 20이하의 알파벳 소문자로 이루어져있으며 같은 이름을 가진 의상은 존재하지 않는다.

## 출력

각 테스트 케이스에 대해 해빈이가 알몸이 아닌 상태로 의상을 입을 수 있는 경우를 출력하시오.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 128MB

---

## 해설

주어진 의상을 다 받아들인 다음, 옷들을 선택하는 경우의 수 중 아무것도 선택하지 않는 경우를 제외한 나머지를 계산해주면 된다.

## 풀이

카테고리를 담는 string 타입의 벡터를 선언하여 새로운 종류가 나올 때 마다 해당 벡터에 push 한다. 각 카테고리의 옷의 개수만이 필요하므로, int형 벡터를 선턴하여 각 카테고리에 몇 개의 옷이 현재 포함되었는지를 헤아린다.

```cpp
vector<string> category;
vector<int> gear; 

for(int i = 0; i < N; i++) {
    string inputName;
    string inputCategory;
    cin >> inputName >> inputCategory;
    
    int k;
    for(k = 0; k < category.size(); k++) {
        if(inputCategory == category[k]) break;
    }
    
		// 만약에 카테고리에 이미 들어있으면 k가 적절한 위치에서 탈출
		// 없으면 새로 push해주고, gear에는 1개부터 count 시작
    if(k == category.size()) {
        category.push_back(inputCategory);
        gear.push_back(1);
    } else {
				// 추가해주기
        gear[k] += 1 ;
    }
}
```

아무것도 착용하지 않은 경우를 제외한 경우의 수를 구하면 된다. 각 카테고리당 하나의 의상을 착용할 수 있으므로, 아무것도 선택하지 않거나 하나의 아이템을 선택하는 경우의 수를 통해 값을 구해주면 된다.

```
A, B, C 세 개의 카테고리가 있다고 할 때,
ABC + AB + AC + BC + A + B + C 가 원하는 결과이다.

이는 (A + 1)(B + 1)(C + 1) - 1 의 값과 같다.
```

```cpp
int result = 1;
for(int i = 0; i < category.size(); i++) {
    
    result *= gear[i]+1;
}

cout << result - 1 << '\n';
```

---

## 코멘트

이게 왜 수학에 들어가있나 했더니, 마지막 부분 때문에 수학으로 포함된 것 같다.

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        cin >> N;
        
        vector<string> category;
        vector<int> gear; 
        
        for(int i = 0; i < N; i++) {
            string inputName;
            string inputCategory;
            cin >> inputName >> inputCategory;
            
            int k;
            for(k = 0; k < category.size(); k++) {
                if(inputCategory == category[k]) break;
            }
            
            if(k == category.size()) {
                category.push_back(inputCategory);
                gear.push_back(1);
            } else {
                gear[k] += 1 ;
            }
        }
        
        int result = 1;
        for(int i = 0; i < category.size(); i++) {
            
            result *= gear[i]+1;
        }
        
        cout << result - 1 << '\n';
    }
      
    return 0;
}
```

---