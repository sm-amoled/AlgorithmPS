#include <iostream>
#include <vector>

using namespace std;

int getGCD(int a, int b) {
    while(a != b) {
        if(a < b) {b = b-a;}
        else {a = a-b;}
    }
    
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, first;
    cin >> N;
    
    cin >> first;
    for(int i = 1; i < N; i++) {
        int input;
        cin >> input;
        
        int gcd = getGCD(first, input);
        cout << first/gcd << '/' << input/gcd <<'\n';
    }
     
    return 0;
} 