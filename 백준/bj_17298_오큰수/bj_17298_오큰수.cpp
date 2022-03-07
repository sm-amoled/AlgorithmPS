#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A;
    cin >> A;
    
    vector<int> NGE(A);
    vector<int> stack;
    vector<int> answer(A);
    
    for(int i = 0; i < A; i++) {
        cin >> NGE[i];
    }
    
    stack.push_back(1000001);
    
    for(int i = A-1; i >= 0; i--) {
        while(stack.back() <= NGE[i]) {
            stack.pop_back();
        }
        answer[i] = (1000001 == stack.back())? -1:stack.back();
        stack.push_back(NGE[i]);
    }
    
    for(auto x : answer) {
        cout << x << " ";
    }
    cout << '\n';
    
    return 0;
}
