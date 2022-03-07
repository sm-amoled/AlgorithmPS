#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    // 입력    
    vector<int> input(N);
    int temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        input[i] = temp;
    }
    
    // DP
    vector<int> increase(N, 1);
    vector<int> decrease(N, 1);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(input[j] < input[i]) {
                if(increase[i] < increase[j]+1) {
                    increase[i] = increase[j] + 1;
                }
            }
            if(input[N-1-j] < input[N-1-i]) {
                if(decrease[N-1-i] < decrease[N-1-j] + 1) { 
                    decrease[N-1-i] = decrease[N-1-j] + 1;
                }
            }
        }
    }
    
    int max = 0;
    for(int i = 0; i < N; i++) {
        increase[i] = increase[i]+decrease[i];
        max = (max > increase[i])? max : increase[i];
    }
    
    cout << max - 1;
    return 0;
}