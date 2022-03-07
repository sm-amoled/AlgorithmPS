#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int count, K, inputNumber;
    cin >> count >> K;

    for(int i = 0; i < count; i++) {
        scanf("%d", &inputNumber);
        v.push_back(inputNumber);
    }
    sort(v.begin(), v.end());

    cout << v[K-1];
    return 0;
}