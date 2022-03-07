#include <iostream>
#include <vector>

using namespace std;

bool findAnswer = false;

bool checkValue(int sudoku[][9], int row, int column, int value) {
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][column] == value || sudoku[row][i] == value) return false;
    }
    
    int rowIndex = row/3 * 3;
    int columnIndex = column/3 * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(sudoku[rowIndex+i][columnIndex+j] == value) return false;
        }
    }
    
    return true;
}

void findValue(int sudoku[][9], vector<pair<int, int>> blank, int index) {
    if(index == blank.size()) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }cout <<'\n';
        }

        findAnswer = true;
        return;
    }
    
    int row = blank[index].first;
    int column = blank[index].second;
    
    for(int select = 1; select <= 9; select++) { 
        if(checkValue(sudoku, row, column, select)) {
            sudoku[row][column] = select;
            findValue(sudoku, blank, index+1);
        }
        
        if(findAnswer) return;
    }
    sudoku[row][column] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int sudoku[9][9];
    vector<pair<int, int>> blank;
    
    for(int row = 0; row < 9; row++) {
        for(int column = 0; column < 9; column++) {
            cin >> sudoku[row][column];
            
            if(sudoku[row][column] == 0) {
                blank.push_back(make_pair(row, column));
            }
        }
    }
    
    findValue(sudoku, blank, 0);

	return 0;
}