#include <iostream>

using namespace std;

bool image[64][64];

void compress(int R, int C, int S) {
    
    if(S == 1) {
        if(image[R][C]) {
            cout << "1";
        } else {
            cout << "0";
        }
        return;
    }
    
    int count = 0;
    
    for(int row = R; row < R + S; row++) {
        for(int column = C; column < C + S; column++) {
            if(image[row][column]) count++;
        }
    }
    
    if(count == S*S) {
        cout << "1";
    } else if(count == 0) {
        cout << "0";
    } else {
        cout << "(";
        compress(R, C, S/2);
        compress(R, C + S/2, S/2);
        compress(R + S/2, C, S/2);
        compress(R + S/2, C + S/2, S/2);
        cout << ")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < N; j++) {
            image[i][j] = (input[j] == '1')? true:false;
        }   
    }
    
    compress(0, 0, N);
    
    return 0;
} 