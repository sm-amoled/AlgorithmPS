#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> fibo(N+1);
    
    if(N < 2){
        cout << N;
        return 0;
    }
    
    fibo[0] = 0;
    fibo[1] = 1;
    
    for(int i = 2; i <= N; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    cout << fibo[N];
    return 0;
}