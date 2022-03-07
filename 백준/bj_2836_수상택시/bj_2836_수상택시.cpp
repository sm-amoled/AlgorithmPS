#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int, int>> work;
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        int from, to;
        cin >> from >> to;

        if(from > to) {
            work.push_back(pair<int, int>(to, from));
        }
    }

    sort(work.begin(), work.end());

    long long result = M;
    int left = -1, right = -1;

    for(auto x : work) {
        if(x.first > right) {
            result += (right - left)*2;
            left = x.first;
            right = x.second;
        } else {
            right = max(right, x.second);
        }
    }

    result += (right-left)*2;

    cout << result;
    return 0;
}