#include <iostream>
#include <vector>

using namespace std;

void sequence(vector<int> arr, int N, int depth) {
    if(depth == 0) {
        for(auto x : arr) {
            cout << x << " ";
        } cout << '\n';
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        arr.push_back(i);
        sequence(arr, N, depth-1);
        arr.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> arr;
    
    sequence(arr, N, M);

	return 0;
}