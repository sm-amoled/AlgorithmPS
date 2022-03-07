#include <iostream>
#include <vector>

using namespace std;

void sequence(vector<int> arr, int N, int before, int depth) {
    if(depth == 0) {
        for(auto x : arr) {
            cout << x << " ";
        } cout << '\n';
        return;
    }
    
    for(int i = before; i <= N; i++) {
        arr.push_back(i);
        sequence(arr, N, i, depth-1);
        arr.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> arr;
    
    sequence(arr, N, 1, M);

	return 0;
}