#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    int T;
    cin >> T;
    
    while(T--) {
        int A, B;
        cin >> A >> B;
        
        int multA = A, multB = B;
        while(multA != multB) {
            if(multA < multB) {
                multA += A;
            } else {
                multB += B;
            }
        }
        cout << multA << '\n';
    }
    return 0;
} 