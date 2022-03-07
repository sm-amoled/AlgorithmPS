#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<char> stack;
    
    while(true) {
        char temp = getchar();
        if(temp == '\n' || temp == 0) break;
        
        if(temp >= 'A' && temp <= 'Z') {
            cout << temp;
        } else {
            if(stack.empty()) {
                stack.push_back(temp);
            } else {
                switch(temp) {
                    case '(':
                        stack.push_back(temp);
                        break;
                        
                    case ')':
                        while(stack.back() != '(') {
                            cout << stack.back();
                            stack.pop_back();
                        }
                        stack.pop_back();
                        break;
                        
                    case '+':
                    case '-':
                        while(!stack.empty()) {
                            if(stack.back() == '(') {
                                break;
                            } else {
                                cout << stack.back();
                                stack.pop_back();
                            }
                        }
                        stack.push_back(temp);
                        break;
                        
                    case '*':
                    case '/': 
                        while(!stack.empty()) {
                            if(stack.back() == '(') {
                                break;
                            } else if (stack.back() == '*' || stack.back() == '/') {
                                cout << stack.back();
                                stack.pop_back();
                            } else {
                                break;
                            }
                        }
                        stack.push_back(temp);
                        break;
                }
            }
        }
    }
    
    while(!stack.empty()) {
        cout << stack.back();
        stack.pop_back();
    }
        
    return 0;
}
/*
A+(B*C)*D*E+F
*/