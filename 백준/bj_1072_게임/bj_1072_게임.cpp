#include <iostream>
#include <algorithm>
using namespace std;

int winRate(long win, long total) {
    return 100 * win / total;
}

int main() {
    
    long X, Y 
		int Z;
    cin >> X >> Y;
    Z = winRate(Y, X);
    
    if(Z >= 99) {
        printf("-1");
        return 0;
    }
    
    long left = 0, right = 1000000000;
    
    while(left < right) {
        long mid = (left+right)/2;
        int A = winRate(Y+mid, X+mid);
        
        if(A > Z) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    printf("%ld", right);
    return 0;
}