#include <iostream>
#include <queue>
    
using namespace std;

typedef struct currentPos {
    int x;
    int y;
} pos;

int boardSize;
int board[301][301];
pos start;
pos target;
queue<pos> Q;

int moveX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int moveY[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool sizeCheck(int x, int y) {
    if(x >= 0 && x < boardSize && y >= 0 && y < boardSize) return true;
    return false;
}

bool isTarget(int x, int y) {
    if(target.x == x && target.y == y) return true;
    return false;
}

void BFS() {
    if(isTarget(start.x, start.y)) return;
    
    int stage = 0;
    while(!Q.empty()) {
        stage++;
        
        for(int i = Q.size(); i > 0; i--) {
            pos curr = Q.front();
            Q.pop();
            
            for(int moves = 0; moves < 8; moves++) {
                pos next = {curr.x + moveX[moves], curr.y + moveY[moves]};
                
                if(sizeCheck(next.x, next.y) && board[next.x][next.y] == 0) {
                    board[next.x][next.y] = stage;
                    if(isTarget(next.x, next.y)) return;
                    
                    Q.push({curr.x + moveX[moves], curr.y + moveY[moves]});
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count;
    cin >> count;
    
    while(count-- > 0) {
        cin >> boardSize;
        cin >> start.x >> start.y;
        cin >> target.x >> target.y;
        Q = queue<pos>(); // element가 들어있는 Queue 비우기
        
        for(int row = 0; row < boardSize; row++) {
            for(int column = 0; column < boardSize; column++) {
                board[row][column] = 0;
            }
        }
        
        Q.push(start);
        BFS();
        cout << board[target.x][target.y] << '\n';
    }
    
    return 0;
}
