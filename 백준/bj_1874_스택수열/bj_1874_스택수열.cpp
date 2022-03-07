#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int top = -1, k = 1, currentValue;
    vector<int> stack;
    vector<char> instruction;
    
    for(int i = 0; i < N; i++) {
        cin >> currentValue;
        
        if(top == -1) {
            stack.push_back(k++);
            top++;
            instruction.push_back('+');
        } 
        
        while(stack[top] != currentValue) {
            
            stack.push_back(k++);
            top++;
            instruction.push_back('+');
            
            if(k > N+1) {
                cout << "NO\n";
                return 0;
            }
        }
        
        stack.pop_back();
        top--;
        instruction.push_back('-');
    }
    
    for(auto x : instruction) {
        cout << x << "\n";
    }
    
    return 0;
}