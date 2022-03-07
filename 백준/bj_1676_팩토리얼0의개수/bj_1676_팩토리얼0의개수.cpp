#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, result = 0;
    cin >> N;
    
    result += N/5;
    result += N/25;
    result += N/125;
    
    cout << result;
    return 0;
} 