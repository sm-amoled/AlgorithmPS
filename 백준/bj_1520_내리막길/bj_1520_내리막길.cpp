#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    // map : 높이 값 저장
    // countMap : 각 cell 주변에 처리해야 할 더 높은 cell의 개수 저장
    // pathMap : 각 cell 에 도달할 수 있는 경로의 경우의 수
    vector<vector<int>> map(M, vector<int>(N));
    vector<vector<int>> countMap(M, vector<int>(N));
    vector<vector<int>> pathMap(M, vector<int>(N));
    
    
    queue<pair<int, int>> Q;

    for(int row = 0; row < M; row++) {
        for(int column = 0; column < N; column++) {
            cin >> map[row][column];
        }
    }

    int dx[] = { 1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    for(int row = 0; row < M; row++) {
        for(int column = 0; column < N; column++) {
            int count = 0;

            for(int i = 0; i < 4; i++) {
                int x = column + dx[i];
                int y = row + dy[i];
                
                if(0 <= x && x < N && 0 <= y && y < M) {
                    if(map[y][x] > map[row][column]) count++;
                }
            }
            
            countMap[row][column] = count;
            
            if(count == 0) Q.push(make_pair(row, column));
        }
    }

    pathMap[0][0] = 1;
    while(!Q.empty()) {
        int row = Q.front().first;
        int column = Q.front().second;
        Q.pop();

        countMap[row][column]--;

        for(int i = 0; i < 4; i++) {
            int x = column + dx[i];
            int y = row + dy[i];
            
            if(0 <= x && x < N && 0 <= y && y < M) {
                if(map[y][x] < map[row][column]) {
                    pathMap[y][x] += pathMap[row][column];
                    countMap[y][x]--;
                    
                    if(countMap[y][x] == 0) Q.push(make_pair(y, x));
                }
            }
        }
    }

    cout << pathMap[M-1][N-1] << '\n';
    return 0;
}


