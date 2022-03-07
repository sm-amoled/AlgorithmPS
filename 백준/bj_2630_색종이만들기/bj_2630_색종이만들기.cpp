#include <iostream>

using namespace std;

int blue = 0, white = 0;
bool paper[128][128] = {false};

void getPaper(int Rstart, int Cstart, int size) {
    if(size == 1) {
        if(paper[Rstart][Cstart]) {
           blue++;
       } else {
           white++;
       }
       return;
    }
    
    bool cmp = paper[Rstart][Cstart];
    int sum = 0;
    for(int rowIndex = 0; rowIndex < size; rowIndex++) {
        for(int columnIndex = 0; columnIndex < size; columnIndex++) {
            if(paper[Rstart + rowIndex][Cstart + columnIndex]) sum++;
        }
    }
    
    if(sum == size*size) {
      blue++;
    } else if (sum == 0) {
      white++;
    } else {
        getPaper(Rstart, Cstart, size/2);
        getPaper(Rstart + size/2, Cstart, size/2);
        getPaper(Rstart, Cstart + size/2, size/2);
        getPaper(Rstart + size/2, Cstart + size/2, size/2);
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int input;
            cin >> input;
            
            paper[i][j] = (input == 1)? true:false;
        }
    }
    
    getPaper(0, 0, N);
    
    cout << white << '\n' << blue;
    return 0;
} 