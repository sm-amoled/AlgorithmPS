#include <iostream>

using namespace std;

int fact(int numb) {
    if(numb == 0) return 1;
    else return numb*fact(numb-1);
}

int main() {
	int N;
	cin >> N;
	
	cout << fact(N);
	
	return 0;
}