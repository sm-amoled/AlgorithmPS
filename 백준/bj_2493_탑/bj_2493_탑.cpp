#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    int temp;
    
    vector<int> tops;
    vector<int> index;
    
    // 초기값 설정
    cin >> temp;
    tops.push_back(temp);
    index.push_back(1);
    cout << "0 ";
    
    for(int i = 1; i < N; i++) {
        cin >> temp;
        
        int top = tops.size()-1;
        while(tops[top] < temp && top >= 0) {
            top--;
        }
        
        if(top < 0) {
            cout << "0 ";
        } else {
            cout << index[top] << " ";    
        }
        
        
        if(tops.back() <= temp) {
            tops.pop_back();
            index.pop_back();
        }
        
        tops.push_back(temp);
        index.push_back(i+1);
    }
    return 0;
}