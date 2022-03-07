#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // vector<char> s;
    string s;
    char temp;
    while(true) {
        getline(cin, s, '.');
        if(s == "") return 0;
        
        vector<char> equal;
        
        int index = 0;
        while(s[index] != 0) {
            
            if(s[index] == '(' || s[index] == '[') equal.push_back(s[index]);
            if(s[index] == ')' || s[index] == ']') {
                // )가 먼저 나오는 경우
                if(equal.size() == 0) break;
                
                if((equal.back() == '(' && s[index] == ')') || (equal.back() == '[' && s[index] == ']')) equal.pop_back();
                else {
                   break;
                }
            }
            index++;
        }
        
        cout << ((s[index] == 0 && equal.size() == 0)? "yes\n":"no\n");
        s.clear();
    }
    
    return 0;
}