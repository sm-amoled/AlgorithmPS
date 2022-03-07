#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    
    int N, K;
    string str;
    cin >> N >> K;
    cin >> str;
    vector<int> numb;
    
    for(int i = 0; i < N; i++) {
        while(K && !numb.empty() && numb.back() < str[i]-'0') {
            numb.pop_back();
            K--;
        }
        
        numb.push_back(str[i]-'0');
    }
    
    for(int i = 0; i < numb.size()-K; i++) {
        cout << numb[i];
    }
    return 0;
}