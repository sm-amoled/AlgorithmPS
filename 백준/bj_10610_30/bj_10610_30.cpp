#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    char inputC;
    int sum = 0, index;
    vector<int> numbV;

    while(true) {
        inputC = getchar();
        if(inputC == '\n') break;
        numbV.push_back(inputC-'0');
        sum += inputC-'0';
    }

    sort(numbV.begin(), numbV.end());

    if(numbV.at(0) != 0 || sum%3 != 0) {
        printf("-1");
        return 0;
    } 

    for(int i = numbV.size(); i > 0; i--) {
        printf("%d", numbV.at(i-1));
    }
    return 0;
}
