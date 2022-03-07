#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> stack;
    char temp;
    
    while(true) {
        temp = getchar();
        if(temp == '\n') break;
        
        if(temp == '(') {
            stack.push_back(0);
        } else if (temp == '[') {
            stack.push_back(1);
        } else if (temp == ')' || temp == ']') {
            int match = (temp == ')')? 0:1;
            
            if(stack.size() == 0) {
                cout << "0";
                return 0;
            }
            
            if(stack.back() == match) {
                stack.pop_back();
                stack.push_back(match+2);
            } else if (stack.back() == (match == 0)? 1:0) {
                // 반례 : ( [ )
                cout << "0";
                return 0;
            } else {
                if(stack.size() == 1) {
                    // 반례 : X )
                    cout << "0";
                    return 0;
                }
                else if(stack[stack.size()-2] == match) {
                    stack[stack.size()-2] = stack.back()*(match+2);
                    stack.pop_back();
                }
            }
            
            if(stack.size() >= 2) {
                if(stack.back() > 1 && stack[stack.size()-2] > 1) {
                    stack[stack.size()-2] += stack.back();
                    stack.pop_back();
                }
            }
        }
    }
    if(stack.size() > 1) {
        // 반례 : X ( 
        cout << "0";
        return 0;
    }
    
    cout << stack.back();
    return 0;
}