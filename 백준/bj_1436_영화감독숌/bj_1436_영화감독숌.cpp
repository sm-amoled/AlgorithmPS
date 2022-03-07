#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string str;
    int numb = 665;
    
    while(++numb) {
        str = to_string(numb);
        
        if(str.find("666") != -1) {
            N--;
        }
        
        if(N == 0) {
            cout << numb;
            return 0;
        }
    }

	return 0;
}