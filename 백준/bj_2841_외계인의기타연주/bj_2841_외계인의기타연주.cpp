#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, P;
    cin >> N >> P;
    vector<vector<int>>melody (N,vector<int>(0));
    int count = 0;
    for(int i = 0; i < N; i++) {
        int line, pret;
        cin >> line >> pret;
        
        while(!melody[line-1].empty()) {
            if(melody[line-1].back() > pret) {
                melody[line-1].pop_back();
                count++;
            } else {
                break;
            }
        }
        
        if(!melody[line-1].empty()) {
            if(melody[line-1].back() != pret) {
                melody[line-1].push_back(pret);
                count++;
            }
        } else {
            melody[line-1].push_back(pret);
            count++;
        }
    }
    
    cout << count;
    return 0;
}