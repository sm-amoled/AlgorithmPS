#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int temp;
    vector<int> sesu;

    scanf("%d", &temp);
    sesu.push_back(temp);
    scanf("%d", &temp);
    sesu.push_back(temp);
    scanf("%d", &temp);
    sesu.push_back(temp);

    sort(sesu.begin(), sesu.end());

    printf("%d %d %d", sesu.at(0), sesu.at(1), sesu.at(2));
    return 0;
}