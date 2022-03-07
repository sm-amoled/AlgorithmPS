#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void queen(vector<int> board, int row) {
    int maxBoard = board.size();
    
    if(maxBoard == row) {count++; return;}
    
    for(int i = 0; i < maxBoard; i++) {
        bool survive = true;
        
        for(int j = 1; j <= row; j++) {
            if(board[row-j] == i || board[row-j] == i-j || board[row-j] == i+j) {
                survive = false;
                break;
            }
        }
        
        if(survive) {
            board[row] = i;
            queen(board, row+1);
        }
    }
    
}

int main() {
    int N;
    cin >> N;
    
    vector<int> board(N, -1);
    
    queen(board, 0);
    
    cout << count;
    
	return 0;
}