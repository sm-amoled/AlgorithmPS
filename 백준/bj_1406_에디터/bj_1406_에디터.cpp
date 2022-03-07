#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    
    cin >> s;
    cin >> n;
    
    vector<char> leftStack(s.begin(), s.end());
    vector<char> rightStack;
    
    while(n--) {
        char inst;
        cin >> inst;
        
        switch(inst) {
            case 'L':
                if(leftStack.size()) {
                    rightStack.push_back(leftStack.back());
                    leftStack.pop_back();
                }
            break;
            case 'D':
                if(rightStack.size()) {
                    leftStack.push_back(rightStack.back());
                    rightStack.pop_back();
                }
            break;
            case 'B':
                if(leftStack.size()) leftStack.pop_back();
            break;
            case 'P':
                char temp;
                cin >> temp;
                leftStack.push_back(temp);
            break;
        }
    }
    
    for(int i = 0; i < leftStack.size(); i++) {
        cout << leftStack[i];
    }
    for(int i = rightStack.size()-1; i >= 0; i--) {
        cout << rightStack[i];
    }
    
    return 0;
}