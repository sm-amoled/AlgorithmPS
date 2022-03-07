#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int input;
    int min = 1000001, max = 1;
    for(int i = 0; i < N; i++) {
        cin >> input;
        
        if(min > input) min = input;
        if(max < input) max = input;
    }
    
    
    cout << max * min;
      
    return 0;
} 