#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

void print(const matrix&);

matrix operator * (const matrix &A, const matrix &B) {
    int size = A.size();
    matrix result(size, vector<long long>(size));

    for(int row = 0; row < size; row++) {
        for(int column = 0; column < size; column++) {
            for(int p = 0; p < size; p++) {
                result[row][column] += A[row][p] * B[p][column];
            }
            result[row][column] %= 1000;
        }
    }

    return result;
}

matrix multiply(matrix A, long long N) {
    int size = A.size();
    matrix result(size, vector<long long>(size));

    for(int i = 0; i < size; i++) {
        result[i][i] = 1;
    }

    while(N > 0) {
        if(N % 2 == 1) {
            result = result * A;
        }
        N /= 2;
        A = A * A;
    }

    return result;
}

void print(const matrix& A) {
    int size = A.size();

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {

    long long N, B;
    cin >> N >> B;

    matrix A(N, vector<long long> (N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    print(multiply(A, B));
    return 0;
}