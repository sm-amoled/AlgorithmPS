#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> values(N);
    vector<int> ordered;
    for(int i = 0; i < N; i++) {
        cin >> values[i];
    }
    
    ordered.assign(values.begin(), values.end());
    sort(ordered.begin(), ordered.end());
    ordered.resize(unique(ordered.begin(), ordered.end())-ordered.begin());

    
    for(auto v : values) {
        cout << lower_bound(ordered.begin(), ordered.end(), v) - ordered.begin() << ' ';
    }
}
