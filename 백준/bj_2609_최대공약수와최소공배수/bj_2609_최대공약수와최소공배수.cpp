#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    int factA = A, factB = B;
    while(factA != factB) {
        if(factA < factB) {
            factB -= factA;
        } else {
            factA -= factB;
        }
    }
    cout << factA << '\n';
    
    int multA = A, multB = B;
    while(multA != multB) {
        if(multA < multB) {
            multA += A;
        } else {
            multB += B;
        }
    }
    cout << multA << '\n';
    
    return 0;
} 