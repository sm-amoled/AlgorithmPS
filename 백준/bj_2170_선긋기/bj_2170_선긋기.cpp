#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int N;
    cin >> N;

    pair<int, int> lines[1000000];
    for(int i = 0; i < N; i++) {
        int down, up;
        cin >> down >> up;

        lines[i] = pair<int, int> (down, up);
    }

    // Calculate
    sort(lines, lines+N);

    int result = 0;
    int left = -1000000000,  right = -1000000000;
    for(int i = 0; i < N; i++) {
        if(right < lines[i].first) {
            result += right - left;

            left = lines[i].first;
            right = lines[i].second;
        } else {
            right = max(right, lines[i].second);
        }
    }

    result += right-left;
    cout << result;

    return 0;
}