#include <iostream>

using namespace std;

int sumV(int a) {
    return a*(a+1)/2;
}

int main() {
    long S;
    cin >> S;
    
    long sum = 0;
    int count = 0;
    while(sum <= S) {
        count++;
        sum += count;
    }
    
    // 한 번 더 카운트한 다음 탈출하니깐
    cout << count-1 << '\n';   

    return 0;
}