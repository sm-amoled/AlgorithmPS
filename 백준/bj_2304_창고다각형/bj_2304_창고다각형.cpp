#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> house;
    
    int pos, high;
    for(int i = 0; i < N; i++) {
        cin >> pos >> high;
        house.emplace_back(pos, high);
    }
    
    sort(house.begin(), house.end(), [](auto a, auto b) {
        return a.first < b.first;
    });
    
    int leftPos = house[0].first;
    int leftMaxHeight = house[0].second;
    int result = 0;
    for(auto& p : house) {
        if(leftMaxHeight <= p.second) {
            result += (p.first-leftPos) * leftMaxHeight;
            leftMaxHeight = p.second;
            leftPos = p.first;
        }
    }
    
    int rightPos = house.back().first;
    int rightMaxHeight = house.back().second;
    for(int i = house.size() - 1; i >= 0; i--) {
        if(rightMaxHeight < house[i].second) {
            result += (rightPos - house[i].first) * rightMaxHeight;
            rightMaxHeight = house[i].second;
            rightPos = house[i].first;
        }
    }
    
    cout << result + leftMaxHeight;
    return 0;
}