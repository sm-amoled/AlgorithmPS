#include <iostream>

using namespace std;

void tower(int from, int to, int N) {
    if(N == 1) {
        cout << from << " " << to << '\n';
    } else {
        tower(from, 6-from-to, N-1);
        cout << from << " " << to << '\n';
        tower(6-from-to, to, N-1);
    }
}

int main() {
	int N, K = 1;
	cin >> N;
	
	for(int i = 0; i < N; i++) { K *= 2; }
	
	cout << K-1 << '\n';
	tower(1, 3, N);
	
	
	return 0;
}