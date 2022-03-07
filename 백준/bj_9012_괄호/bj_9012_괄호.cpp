#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int top = -1;
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        
        int index = 0;
        top = -1;
        while(input[index] != '\0') {
            if(input[index] == '(') {
                top++;
            } else if (input[index] == ')') {
                top--;
                if(top < -1) {
                    break;
                }
            }
            index++;
        }
        
        cout << ((top == -1)? "YES":"NO") << "\n";
    }
    
    return 0;
}