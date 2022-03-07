#include <iostream>
#include <vector>

using namespace std;

void sequence(vector<bool> used, vector<int> arr, int depth) {
    if(depth == 0) {
        for(auto x : arr) {
            cout << x << " ";
        } cout << '\n';
        return;
    }
    
    for(int i = 1; i < used.size(); i++) {
        if(used[i] == false) {
            arr.push_back(i);
            used[i] = true;
            sequence(used, arr, depth-1);
            arr.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> used(N+1, false);
    vector<int> arr;
    
    sequence(used, arr, M);

	return 0;
}