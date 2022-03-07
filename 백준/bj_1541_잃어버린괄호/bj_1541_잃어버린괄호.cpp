#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    char input;
    int temp = 0;
    bool addV = true;
    vector<int> cache(1, 0);
    
    do {
        input = getchar();
        
        if(input >= '0' && input <= '9') {
            temp = temp * 10 + (input-'0');
        } else if (input == '+') {
            if(addV) {
                cache[cache.size()-1] += temp;
            } else {
                cache.push_back(temp);
            }
            temp = 0;
            addV = true;
        } else if (input == '-') {
            if(addV) {
                cache[cache.size()-1] += temp;
            } else {
                cache.push_back(temp);
            }
            temp = 0;
            addV = false;
        } else {
            if(addV) {
                cache[cache.size()-1] += temp;
            } else {
                cache.push_back(temp);
            }
        }
    } while (input != '\n');
      
    int result = cache[0];
    for(int i = 1; i < cache.size(); i++) {
        result -= cache[i];
    }
    
    cout << result;
    
    return 0;
} 