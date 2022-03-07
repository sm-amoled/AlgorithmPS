#include <iostream>
using namespace std;

int main() {
    int number;
    int arr[10]={0,};
    
    cin >> number;
    
    if(number == 0) {
        cout << '0';
    }
    
    while(number != 0) {
        arr[number%10]++;
        number /= 10;
    }
    
    for(int i = 9; i >= 0; i--) {
        while(arr[i] != 0) {
            cout << i;
            arr[i]--;
        }
    }
    
    return 0;
}