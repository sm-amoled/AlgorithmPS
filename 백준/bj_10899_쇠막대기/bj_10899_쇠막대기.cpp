#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string N;
    cin >> N;
    
    int index = 0;
    
    int cutCount = 0;
    long cutSum = 0;
    while(N[index] != 0) {
        if(N[index] == '(') {
            if(N[index + 1] == '(') {
                cutCount++;
                index++;
            } else {
                cutSum += cutCount;
                index += 2;
            }
        } else {
            cutCount--;
            cutSum++;
            index++;
        }
    }
    
    cout << cutSum;
       
    return 0;
}