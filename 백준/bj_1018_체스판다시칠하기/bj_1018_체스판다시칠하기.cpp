#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> board(N, vector<char>(M));    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    int minCorrect = 64;
    
    for(int i = 0; i <= N-8; i++) {
        for(int j = 0; j <= M-8; j++) {
            
            int correct = 0;
            
            for(int p = 0; p < 8; p++) {
                for(int q = 0; q < 8; q++) {
                    if(board[i+p][j+q] != (((p+q) % 2 == 0)? 'B':'W')) {
                        correct++;
                    }
                }
            }
            
            if(correct > 64-correct) correct = 64-correct;
            minCorrect = (minCorrect < correct)? minCorrect : correct;
        }
    }
    
    cout << minCorrect;
	return 0;
}