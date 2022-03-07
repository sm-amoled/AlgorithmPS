#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    
    if(input != "고무오리 디버깅 시작") {
        return 0;
    }
    
    vector<int> stack;
    
    while(true) {
        getline(cin, input);
        
        if(input == "문제") {
            stack.push_back(1);
        } else if (input == "고무오리") {
            if(stack.empty()) {
                stack.push_back(1);
                stack.push_back(1);
            } else {
                stack.pop_back();
            }
        } else if (input == "고무오리 디버깅 끝") {
            break;
        }
    }
    
    if(stack.empty()) {
        cout << "고무오리야 사랑해";
    } else {
        cout << "힝구";
    }
    
    return 0;
}