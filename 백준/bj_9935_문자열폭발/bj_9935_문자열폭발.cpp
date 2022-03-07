#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<char> str;
    vector<char> bomb;
    vector<char> survived;
    
    while(true) {
        char temp = getchar();
        if(temp == '\n') break;
        
        str.push_back(temp);
    }
     
    while(true) {
        char temp = getchar();
        if(temp == '\n') break;
        
        bomb.push_back(temp);
    } 
    
    int strIndex = 0;
    int bombIndex = 0;
    int survivedIndex;
    
    while(strIndex < str.size()) {
        survived.push_back(str[strIndex]);
        survivedIndex = survived.size() - 1;
        
        if(survived[survivedIndex] == bomb[bombIndex]) {
            bombIndex++;
        } else if (survived[survivedIndex] == bomb[0]) {
            bombIndex = 1;
        } else {
            bombIndex = 0;
        }
        
        if(bombIndex == bomb.size()) {
            for(int i = 0; i < bomb.size(); i++) {
                survived.pop_back();
            }
            bombIndex = 0;
            
            survivedIndex = (int)survived.size() - (int)bomb.size() + 1;
            survivedIndex = (survivedIndex>=0)? survivedIndex:0;
            for(; survivedIndex < survived.size(); survivedIndex++) {
                
                if(survived[survivedIndex] == bomb[bombIndex]) {
                    bombIndex++;
                } else if (survived[survivedIndex] == bomb[0]) {
                    bombIndex = 1;
                } else {
                    bombIndex = 0;
                }
            }
        }
    
        strIndex++;
    }
    
    if(survived.size() > 0) {
        for(auto x : survived) {
            cout << x;
        }
    } else {
        cout << "FRULA";
    }
	
    return 0;
}