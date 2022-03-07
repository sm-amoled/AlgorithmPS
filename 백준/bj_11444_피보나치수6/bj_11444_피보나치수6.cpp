 #include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<long long>> matrix;

matrix operator * (matrix a, matrix b) {
    matrix c(2, vector<long long>(2));

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000000007;
        }
    }

    return c;
}

int main() {
    long long N;
    cin >> N;

    matrix result = {{1, 0}, {0, 1}};
    matrix k = {{1, 1}, {1, 0}};

    while(N > 0) {
        if(N % 2 == 1) {
            result = result * k;
        }
        k = k * k;
        N /= 2;
    }

    cout << result[0][1];
    return 0;
}