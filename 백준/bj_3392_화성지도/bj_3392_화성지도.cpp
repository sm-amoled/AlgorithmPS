#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct square{
    int x;
    int y;
    int ySize;
    bool start;

    square(int xIn, int yIn, int ySizeIn, bool startIn) {
        x = xIn;
        y = yIn;
        ySize = ySizeIn;
        start = startIn;
    }
};

bool compare(square A, square B) {
    return A.x < B.x;
}

int checkNonZeros(int arr[30000]) {
    int result = 0;
    for(int i = 0; i < 30000; i++) {
        if(arr[i] != 0) { 
            result++;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<square> map;

    for(int i = 0; i < N; i++) {
        int inx, iny, outx, outy;
        cin >> inx >> iny >> outx >> outy;

        square start = square(inx, iny, outy-iny, true);
        map.push_back(start);
        square end = square(outx, outy, outy-iny, false);
        map.push_back(end);
    }

    sort(map.begin(), map.end(), compare);

    int result = 0;
    int beforex = 0;
    int ys[30000] = {0};

    for(auto sg : map) {
        result += (sg.x - beforex) * checkNonZeros(ys);
        if(sg.start) {
            for(int i = 0; i < sg.ySize; i++) {
                ys[sg.y + i]++;
            }
        } else {
            for(int i = 1; i <= sg.ySize; i++) {
                ys[sg.y - i]--;
            }
        }

        beforex = sg.x;
    }

    cout << result;
    return 0;
}