#include <iostream>

using namespace std;

int A[100][100], B[100][100], result[100][100] = {0};

int main() {
    int N, M, K;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    cin >> M >> K;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < K; j++) {
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            for(int p = 0; p < M; p++) {
                result[i][j] += A[i][p] * B[p][j];
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}