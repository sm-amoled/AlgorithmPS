# 회의실 배정

문제 번호: 1931
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 22일 오후 10:11

### 문제 링크

[https://www.acmicpc.net/problem/1931](https://www.acmicpc.net/problem/1931)

## 문제

한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다. 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자. 단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.

## 입력

첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.

## 출력

첫째 줄에 최대 사용할 수 있는 회의의 최대 개수를 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 128MB

---

## 해설

이벤트 스케줄링 문제이다. 정렬 알고리즘을 이용해 이벤트의 시간을 기준으로 오름차순으로 정렬한 뒤, 선택 가능한 이벤트 중에서 가장 끝나는 시간이 짧은 이벤트를 선택하여 가장 많은 이벤트의 개수를 구할 수 있다. 

## 풀이

입력받은 시작시간과 종료시간이 같이 움직이는 하나의 쌍이므로, `pair` 또는 구조체를 만들어 묶어준다. 병합정렬 알고리즘을 이용하였고, 정렬 알고리즘을 이용할 때 **한 종류의 수를 기준으로 정렬을 수행하면 구조체들을 정렬**하도록 알고리즘을 약간 변형해주었다. 

또, 끝나는 시각을 기준으로 정렬할 때, 끝나는 시각이 같은 경우에는 시작 시간을 비교하여 시작 시간 사이에서도 정렬이 될 수 있게 알고리즘을 약간 수정해주었다.

```cpp
while(i <= j && k <= l) {
	  if(arr[i].endTime < arr[k].endTime) {
	      sorted[index++] = arr[i++];
	  } else if(arr[i].endTime > arr[k].endTime) {
	      sorted[index++] = arr[k++];
	  } else {
	      if(arr[i].startTime < arr[k].startTime) {
	          sorted[index++] = arr[i++];
	      } else {
	          sorted[index++] = arr[k++];
	      }
    }
}
```

정렬이 완료되면 끝나는 시각을 기준으로 오름차순, 끝나는 시각이 같을 때는 시작 시각을 기준으로 오름차순으로 회의 시간이 정렬된다. 가장 앞에 있는 회의부터 순서대로 끝나는 시각을 기록하고 회의 횟수를 1회 증가시키고, 다음 index의 회의의 시작 시간과 비교하며 최대 회의 횟수를 카운트 해나간다. 

---

## 코멘트

병합 정렬의 파라미터로 정렬하고자 하는 시작 index와 끝 index가 들어가야 하는데, 끝 index를 길이로 값을 잘못 넣어서 1시간동안 삽질을 했다. 인자에 어떤 값이 들어가야 하는지 꼭 확인하자!

---

## 코드

```cpp
#include <iostream>
using namespace std;

struct conference {
    int startTime;
    int endTime;
};

void mergeSort(conference* arr, int left, int right);
void merge(conference* arr, int left, int mid, int right);

void mergeSort(conference* arr, int left, int right) {
    if(left < right) {
        int mid = (left+right)/2+1;
        
        mergeSort(arr, left, mid-1);
        mergeSort(arr, mid, right);
        
        merge(arr, left, mid, right);
    }
}

void merge(conference* arr, int left, int mid, int right) {
    int i = left, j = mid-1, k = mid, l = right;
    conference* sorted = new conference[l-i+1];
    int index = 0;
    
    while(i <= j && k <= l) {
        if(arr[i].endTime < arr[k].endTime) {
            sorted[index++] = arr[i++];
        } else if(arr[i].endTime > arr[k].endTime) {
            sorted[index++] = arr[k++];
        } else {
            if(arr[i].startTime < arr[k].startTime) {
                sorted[index++] = arr[i++];
            } else {
                sorted[index++] = arr[k++];
            }
        }
    }
    
    if (i > j) {
        for(; k <= l;) {
            sorted[index++] = arr[k++];
        }
    } else {
        for(; i <= j;) {
            sorted[index++] = arr[i++];
        }
    }
    
    for(int m = left; m <= right; m++) {
        arr[m] = sorted[m-left];
    }
    
    delete[] sorted;
    return;
}

int main() {
    int count, startTime, endTime;
    int confTime = 0, confCount = 0;
    
    scanf("%d", &count);
    conference* confArray = new conference[count+1];
    
    for(int i = 0; i < count; i++) {
        scanf("%d %d", &startTime, &endTime);
        confArray[i] = conference {startTime, endTime};
    }
    
    mergeSort(confArray, 0, count-1);
    
    for(int i = 0; i < count; i++) {
        if(confTime <= confArray[i].startTime) {
            confCount++;
            confTime = confArray[i].endTime;
        }
    }

    printf("%d", confCount);
    
    delete[] confArray;
    return 0;
}
```