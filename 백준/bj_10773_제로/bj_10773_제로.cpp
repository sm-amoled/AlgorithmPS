#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int K;
    cin >> K;
    vector<int> arr(K);
    
    int temp, top = -1;
    for(int i = 0; i < K; i++) {
        cin >> temp;
        if(temp != 0) {
            arr[++top] = temp;
        } else {
            top--;
        }
    }
    
    int sum = 0;
    for(int i = 0; i <= top; i++) {
        sum += arr[i];
    }
    cout << sum;
    
    return 0;
}