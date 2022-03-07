# 큰 수 A+B

문제 번호: 10757
알고리즘 분류: 수학, 큰 수
푼 날짜: 2021년 2월 28일 오후 12:24

## 문제링크

[https://www.acmicpc.net/problem/10757](https://www.acmicpc.net/problem/10757)

## 문제

두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)

## 출력

첫째 줄에 A+B를 출력한다.

## 조건

- 시간 제한 : 1s
- 메모리 제한 : 256MB

---

## 해설

일반적인 데이터로는 처리하기 힘든 큰 사이즈를 갖고있다. (int형의 사이즈는 10^3 정도) 따라서, 데이터를 한번에 처리하는 것이 아닌, 작은 사이즈로 쪼개어 처리해야 한다.

아래 풀이에서는 문자열로 입력을 받아들인 뒤 각 자리를 따로 더해 벡터에 담고, 해당 벡터를 출력하여 해결하였다.

## 풀이

값을 string 타입으로 받아온 후, char 단위로 쪼개어 vector<char>에 담아주었다. string Ainput을 vector에 쪼개어 넣기 위해서는 아래와 같은 문법을 사용해주면 된다. (첫 반복자 Ainput.begin() ~ 끝 반복자 Ainput.end()을 담는다)

```cpp
string Ainput, Binput;
cin >> Ainput >> Binput;

vector<int> result;
vector<char> A(Ainput.begin(), Ainput.end());
vector<char> B(Binput.begin(), Binput.end());
```

자리올림을 나타내줄 carryBit을 선언해주었다. 덧셈은 1의 자리부터 진행되므로, 문자열의 끝에서 시작해 함께 더해간다. 둘의 자릿수가 다른 경우에도 아래와 같이 계산하면 겹쳐지는 부분에 대해서 덧셈을 자릿수에 맞추어 진행 가능하다. 

`temp`에 A의 가장 뒤에 있는 값 + B의 가장 뒤에 있는 값 + carryBit을 담아준다. 이때 A, B에 저장되어 있는 값이 모두 char type이기 때문에, 이를 정수형으로 만들어주기 위해 ‘0’을 빼주었다. (ascii 코드 값을 이용한 방법 - ‘1’과 ‘0’은 ascii 상으로 1 차이가 난다.) 만약 이 temp 값이 10 이상이라면 carryBit에 1을 넣고 temp에는 10을 빼준다. 이 값을 result에 push_back() 해주고, A와 B의 맨 뒤에 있는 값 (방금 계산한 값)은 pop해준다. 

```cpp
int carryBit = 0;
while(!A.empty() && !B.empty()) {
    int temp = (A.back()-'0') + (B.back()-'0') + carryBit;
    if(temp >= 10) {
        carryBit = 1;
        temp -= 10;
    } else {
        carryBit = 0;
    }
    result.push_back(temp);
    A.pop_back();
    B.pop_back();
}
```

A, B 둘 중 하나에 있는 수를 모두 처리한 경우 하나의 수에 대해서만 연산을 처리해준다. 그러나 만약 carry가 1이고 남아있는 수가 99999999 라면 이 역시 계속 carry 계산을 해주어야 하기 때문에, 아래처럼 코드가 동작해야 한다. A, B에 남아있던 모든 수를 처리한 뒤에는 carryBit에 수가 남아있을 수 있으므로, 남아있는 경우 ‘1’을 맨 뒤에 push 해준다. 

```cpp
while(!A.empty()) {
    int temp = A.back()-'0' + carryBit;
      
      if(temp >= 10) {
          carryBit = 1;
          temp -= 10;
      } else {
          carryBit = 0;
      }
      
      result.push_back(temp);
      A.pop_back();
}

while(!B.empty()) {
    int temp = B.back()-'0' + carryBit;
      
      if(temp >= 10) {
          carryBit = 1;
          temp -= 10;
      } else {
          carryBit = 0;
      }
      
      result.push_back(temp);
      B.pop_back();
}

if(carryBit) {
    result.push_back(carryBit);
}
```

맨 앞에 1의 자리수가, 맨 뒤에 가장 큰 자리수가 들어있으므로, 정상적으로 출력하기 위해서는 result 벡터를 역순으로 출력해야 한다. 그럼 원하는 결과를 얻을 수 있다.

```cpp
for(int i = result.size()-1; i >= 0; i--) {
    cout << result[i];
}
```

---

## 코멘트

좀 더 깔끔한 방법이 있을 것 같기도 하고 말이지.. 흐음

---

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string Ainput, Binput;
	cin >> Ainput >> Binput;
	
	vector<int> result;
	vector<char> A(Ainput.begin(), Ainput.end());
	vector<char> B(Binput.begin(), Binput.end());
	
	int carryBit = 0;
	while(!A.empty() && !B.empty()) {
	    int temp = (A.back()-'0') + (B.back()-'0') + carryBit;
	    if(temp >= 10) {
	        carryBit = 1;
	        temp -= 10;
	    } else {
	        carryBit = 0;
	    }
	    result.push_back(temp);
	    A.pop_back();
	    B.pop_back();
	}
	
	while(!A.empty()) {
	    int temp = A.back()-'0' + carryBit;
        
        if(temp >= 10) {
            carryBit = 1;
            temp -= 10;
        } else {
            carryBit = 0;
        }
        
        result.push_back(temp);
        A.pop_back();
	}
	
	while(!B.empty()) {
	    int temp = B.back()-'0' + carryBit;
        
        if(temp >= 10) {
            carryBit = 1;
            temp -= 10;
        } else {
            carryBit = 0;
        }
        
        result.push_back(temp);
        B.pop_back();
	}
	
	if(carryBit) {
	    result.push_back(carryBit);
	}
	
	for(int i = result.size()-1; i >= 0; i--) {
	    cout << result[i];
	}
	
	return 0;
}
```

## 코드