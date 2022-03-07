#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        cin >> N;
        
        vector<string> category;
        vector<int> gear; 
        
        for(int i = 0; i < N; i++) {
            string inputName;
            string inputCategory;
            cin >> inputName >> inputCategory;
            
            int k;
            for(k = 0; k < category.size(); k++) {
                if(inputCategory == category[k]) break;
            }
            
            if(k == category.size()) {
                category.push_back(inputCategory);
                gear.push_back(1);
            } else {
                gear[k] += 1 ;
            }
        }
        
        int result = 1;
        for(int i = 0; i < category.size(); i++) {
            
            result *= gear[i]+1;
        }
        
        cout << result - 1 << '\n';
    }
      
    return 0;
} 