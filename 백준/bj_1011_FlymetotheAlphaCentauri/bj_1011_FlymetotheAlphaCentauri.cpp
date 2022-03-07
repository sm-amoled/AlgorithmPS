#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int T;
    cin >> T;
    
    while(T--) {
        int x, y;
        cin >> x >> y;
        
        int length = y-x;
        
        int count = 1;
        long long N = 1;
        
        while(length > N*N) {
            N++;
            count += 2;
        }
        
        if(length <= N*(N-1)) {
            count--;
        }
        
        cout << count << '\n';
    }

	return 0;
}