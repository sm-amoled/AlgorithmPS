# 단어 정렬

문제 번호: 1181
알고리즘 분류: 정렬
푼 날짜: 2021년 1월 23일 오전 10:02

### 문제 링크

[https://www.acmicpc.net/problem/1181](https://www.acmicpc.net/problem/1181)

## 문제

알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

1. 길이가 짧은 것부터
2. 길이가 같으면 사전 순으로

## 입력

첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

## 출력

조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

## 조건

- 시간 제한 : 2s
- 메모리 제한 : 256MB

---

## 해설

단어와 글자 수를 담는구조체를 선언하여 입력과 동시에 값들을 넣어준다. 정렬 알고리즘을 통해 글자 수에 따라 먼저 정렬을 해주고, 글자 수가 같은 경우에는 단어를 오름차순으로 정렬해준다. 만약 단어가 겹치는 경우에는, 해당 단어의 길이를 음수로 넣어주어 출력할 때 중복되지 않는 단어만 출력할 수 있도록 한다.

## 풀이

단어의 글자 수와 단어를 함께 묶어줄 구조체를 선언한다. 정렬할 때 값들이 쌍으로 함께 움직여야 편하기 때문에 구조체로 묶어주었다. 

```cpp
struct wordSet {
    char* word;
    int wordCount;
};
```

이에 맞게, `merge()` 함수 역시 조금 수정해주었다. 

길이가 다른 경우는 글자 수 값을 가져와 비교하여 정렬할 수 있고, 길이가 같은 경우에는 첫 글자부터 차례로 비교하면서 한 글자라도 다른 경우 정렬한다. 만약 두 단어 모두 같다면 (동시에 문자열의 끝을 알리는 null 값에 도달한다면) **단어 하나는 정상적으로 sorted 배열에 넣어주고, 나머지 한 단어에 대해서는 글자 수에 -1을 대입**하면서 sorted 배열에 넣어준다. 이렇게 하면, 정렬된 배열에는 같은 글자의 단어가 뭉쳐있겠지만, 출력할 때 글자 수가 -1인 단어를 생략하여 겹치지 않는 단어만 뽑아낼 수 있다.

```cpp
void merge(wordSet** arr, int left, int mid, int right) {
    int i = left, j = mid-1, k = mid, l = right;
    wordSet** sorted = new wordSet*[l-i+1];
    wordSet* Lword;
    wordSet* Rword;
    int index = 0, charIndex;
    
    while(i <= j && k <= l) {
        charIndex = 0;
        Lword = arr[i];
        Rword = arr[k];
        
        // 길이가 다를 때
        if(Lword->wordCount < Rword->wordCount) {
            sorted[index++] = arr[i++];
        } else if (Lword->wordCount > Rword->wordCount) {
            sorted[index++] = arr[k++];
        } else { 
        // 길이가 같을 때
            while(true) {
                if(Lword->word[charIndex] == 0 && Rword->word[charIndex] == 0) {
                    // 동일한 단어
                    sorted[index++] = arr[i++];
                    Rword->wordCount = -1;
                    sorted[index++] = arr[k++];
                    break;
                }
                
                if(Lword->word[charIndex] < Rword->word[charIndex]) {
                    sorted[index++] = arr[i++];
                    break;
                } else if(Lword->word[charIndex] > Rword->word[charIndex]){
                    sorted[index++] = arr[k++];
                    break;
                }
                
                charIndex++;
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
```

---

## 코멘트

어렵지 않은 문제였지만, 어렵게 풀었다. 여러 블로그들에서 찾아본 문제풀이들은 다들 `sort()` 함수를 사용하더라. 정렬 알고리즘 문제인데 정렬 함수를 쓰는게 맞는건가? 싶은 생각이 들어서 혼자 낑낑대면서 열심히 풀어내었다. sort 함수를 사용하는 방법을 공부해놓아야 할 것 같다. 

---

## 코드

```cpp
#include <iostream>
using namespace std;

struct wordSet {
    char* word;
    int wordCount;
};

void mergeSort(wordSet** arr, int left, int right);
void merge(wordSet** arr, int left, int mid, int right);

void mergeSort(wordSet** arr, int left, int right) {
    if(left < right) {
        int mid = (left+right)/2+1;
        
        mergeSort(arr, left, mid-1);
        mergeSort(arr, mid, right);
        
        merge(arr, left, mid, right);
    }
}

void merge(wordSet** arr, int left, int mid, int right) {
    int i = left, j = mid-1, k = mid, l = right;
    wordSet** sorted = new wordSet*[l-i+1];
    wordSet* Lword;
    wordSet* Rword;
    int index = 0, charIndex;
    
    while(i <= j && k <= l) {
        charIndex = 0;
        Lword = arr[i];
        Rword = arr[k];
        
        // 길이가 다를 때
        if(Lword->wordCount < Rword->wordCount) {
            sorted[index++] = arr[i++];
        } else if (Lword->wordCount > Rword->wordCount) {
            sorted[index++] = arr[k++];
        } else { 
        // 길이가 같을 때
            while(true) {
                if(Lword->word[charIndex] == 0 && Rword->word[charIndex] == 0) {
                    // 동일한 단어
                    sorted[index++] = arr[i++];
                    Rword->wordCount = -1;
                    sorted[index++] = arr[k++];
                    break;
                }
                
                if(Lword->word[charIndex] < Rword->word[charIndex]) {
                    sorted[index++] = arr[i++];
                    break;
                } else if(Lword->word[charIndex] > Rword->word[charIndex]){
                    sorted[index++] = arr[k++];
                    break;
                }
                
                charIndex++;
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
    int count;
    int index = 0;
    
    scanf("%d", &count);
    wordSet** words = new wordSet*[count];
    wordSet* wordSetInput;
    char word[51];
    
    for(int i = 0; i < count; i++) {
        // scanf("%s ",  words[i]);
        scanf("%s", word);
        char* inputWord = new char[51];
        
        index = 0;
        while(word[index] != 0) {
            inputWord[index] = word[index];
            index++;
        }
        inputWord[index] = 0;
        
        wordSetInput = new wordSet;
        wordSetInput->word = inputWord;
        wordSetInput->wordCount = index;
        words[i] = wordSetInput;
    }

    mergeSort(words, 0, count-1);

    for(int i = 0; i < count; i++) {
        if(words[i]->wordCount >= 0) printf("%s\n", words[i]->word);
        // printf("%d\n", words[i]->wordCount);
    }
    
    delete[] words;
    return 0;
}
```