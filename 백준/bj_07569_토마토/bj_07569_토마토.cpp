#include <iostream>
#include <queue>
    
using namespace std;

struct coord {
    int row;
    int column;
    int height;
};

int M, N, H, rawTomato = 0, maxDate = 1;
int box[102][102][102];
queue<coord> ripeTomato;

int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

void raw2ripe(int row, int column, int height, int date) {
    
    ripeTomato.push({row, column, height});
    
    box[row][column][height] = date + 1;
    maxDate = (maxDate > date + 1)? maxDate : date + 1;
    
    rawTomato--;
}

int main(int argc, const char * argv[]) {
    cin >> M >> N >> H;
    
    for(int i = 0; i < N+2; i++) {
        for(int j = 0; j < M+2; j++) {
            box[i][j][0] = -1;
        }
    }
    
    for(int k = 1; k < H+1; k++) {
        for(int j = 0; j < M+2; j++) {
            box[0][j][k] = -1;
        }
        
        for(int i = 1; i < N+1; i++) {
            box[i][0][k] = -1;
            
            for(int j = 1; j < M+1; j++) {
                int input;
                cin >> input;
                
                box[i][j][k] = input;
                if(input == 0) {
                    rawTomato++;
                } else if (input == 1) {
                    ripeTomato.push({i, j, k});
                }
            }
            
            box[i][M+1][k] = -1;
        }
    
        for(int j = 0; j < M+2; j++) {
            box[N+1][j][k] = -1;
        }
    }
    
    for(int i = 0; i < N+2; i++) {
        for(int j = 0; j < M+2; j++) {
            box[i][j][H+1] = -1;
        }
    }
    
    // Debug
//    for(int i = 0; i < H+2; i++) {
//        for(int j = 0; j < N+2; j++) {
//            for(int k = 0; k < M+2; k++) {
//                printf("%-3d", box[j][k][i]);
//            }
//            cout << '\n';
//        }
//        cout << '\n';cout << '\n';
//    }

    
    
    // 토마토 숙성 시작
    while(!ripeTomato.empty()) {
        coord current = ripeTomato.front();
        ripeTomato.pop();
        
        for(int i = 0; i < 6; i++) {
            if(box[current.row + X[i]][current.column + Y[i]][current.height + Z[i]] == 0) {
                raw2ripe(current.row + X[i], current.column + Y[i], current.height + Z[i], box[current.row][current.column][current.height]);
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


