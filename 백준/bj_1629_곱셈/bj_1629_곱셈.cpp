#include <iostream>

using namespace std;

long long remains(int A, int B, int C) {
    if(B == 1) return A % C;
    
    long long temp = remains(A, B/2, C);
    
    if(B % 2 == 0) {
        return (temp*temp) % C;
    } else {
        return ((temp*temp) % C * A) % C;
    }
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    cout << remains(A, B, C);
        
    return 0;
}