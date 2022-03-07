#include <iostream>

using namespace std;

void pattern(int row, int column, int N) {
    if((row / N) % 3 == 1 && (column / N) % 3 == 1) {
        cout << ' ';
    } else {
        if(N / 3 == 0) {
            cout << '*';
        } else {
            pattern(row, column, N/3);
        }
    }
}

int main() {
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
	    for(int j = 0; j < N; j++) {
	        pattern(i, j, N);
	    }
	    cout << '\n';
	}
	
	return 0;
}