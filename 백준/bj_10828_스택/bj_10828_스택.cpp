#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int topPointer = -1;

void push(int* arr, int X) {
    arr[++topPointer] = X;
}

void pop(int* arr) {
    if(topPointer == -1) {
        cout << "-1\n";
        return;
    } else {
        cout << ((topPointer == -1)? -1:arr[topPointer--]) << "\n";
    }
}

void size(int* arr) {
    cout << topPointer+1 << "\n";
}

void empty(int* arr) {
    cout << ((topPointer == -1)? "1":"0") << "\n";
}

void top(int* arr) {
    
    cout << ((topPointer==-1)? -1:arr[topPointer]) << "\n";
}

int main() {
    int N;
    cin >> N;
    
    int* arr = new int[10001];
    for(int i = 0; i < N; i++) {
        int temp;
        
        string instruction;
        cin >> instruction;
        
        if(instruction == "push") {
            cin >> temp;
            push(arr, temp);
        } else if (instruction == "pop") {
            pop(arr);
        } else if (instruction == "size") {
            size(arr);
        } else if (instruction == "empty") {
            empty(arr);
        } else if (instruction == "top") {
            top(arr);
        } 
        
    }   
    return 0;
}