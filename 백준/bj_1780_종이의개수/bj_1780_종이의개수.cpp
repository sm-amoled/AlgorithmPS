#include <iostream>
#include <math.h>

using namespace std;

int paper[2187][2187];
int minusResult = 0, plusResult = 0, zeroResult = 0;

void getPaper(int R, int C, int S) {
    int zero = 0, plus = 0, minus = 0;
    
    for(int row = R; row < R + S; row++) {
        for(int column = C; column < C + S; column++) {
            if(paper[row][column] == 0) {
                zero++;
            } else if (paper[row][column] == 1) {
                plus++;
            } else {
                minus++;
            }
        }
    }
    
    if(plus == 0 && minus == 0) {
        zeroResult++;
    } else if (plus == 0 && zero == 0) {
        minusResult++;
    } else if (minus == 0 && zero == 0) {
        plusResult++;
    } else {
        getPaper(R,           C, S/3);  getPaper(R,           C + S/3, S/3);    getPaper(R,           C + S/3 * 2, S/3);
        getPaper(R + S/3,     C, S/3);  getPaper(R + S/3,     C + S/3, S/3);    getPaper(R + S/3,     C + S/3 * 2, S/3);
        getPaper(R + S/3 * 2, C, S/3);  getPaper(R + S/3 * 2, C + S/3, S/3);    getPaper(R + S/3 * 2, C + S/3 * 2, S/3);
    }
    
    return;
}

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    
    
    getPaper(0, 0, N);
    
    cout << minusResult << '\n' << zeroResult << '\n' << plusResult;
    return 0;
} 