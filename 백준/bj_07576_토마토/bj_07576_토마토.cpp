#include <iostream>
#include <queue>
    
using namespace std;

struct coord {
    int row;
    int column;
};

int M, N, rawTomato = 0, maxDate = 1;
int box[1002][1002];
queue<coord> ripeTomato;

int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

void raw2ripe(int row, int column, int date) {
    
    ripeTomato.push({row, column});
    
    box[row][column] = date + 1;
    maxDate = (maxDate > date + 1)? maxDate : date + 1;
    
    rawTomato--;
}

int main(int argc, const char * argv[]) {
    cin >> M >> N;
    
    for(int j = 0; j < M+2; j++) {
        box[0][j] = -1;
    }
    
    for(int i = 1; i < N+1; i++) {
        box[i][0] = -1;
        
        for(int j = 1; j < M+1; j++) {
            int input;
            cin >> input;
            
            box[i][j] = input;
            if(input == 0) {
                rawTomato++;
            } else if (input == 1) {
                ripeTomato.push({i, j});
            }
        }
        
        box[i][M+1] = -1;
    }
    
    for(int j = 0; j < M+2; j++) {
        box[N+1][j] = -1;
    }
    
    // 토마토 숙성 시작
    while(!ripeTomato.empty()) {
        coord current = ripeTomato.front();
        ripeTomato.pop();
        
        for(int i = 0; i < 4; i++) {
            if(box[current.row + X[i]][current.column + Y[i]] == 0) {
                raw2ripe(current.row + X[i], current.column + Y[i], box[current.row][current.column]);
            }
        }
    }
    
    // 토마토 숙성 완료
    if(rawTomato > 0) {
        cout << "-1";
    } else {
        cout << maxDate-1;
    }
    
    return 0;
}

