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