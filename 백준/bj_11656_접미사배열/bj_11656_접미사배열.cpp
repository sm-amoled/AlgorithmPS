#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> stringV;
    vector<char> inputV;
    string input;

    cin >> input;
    
    for(int i = 0; i < input.size(); i++) {
        inputV.push_back(input[i]);
    }
    reverse(inputV.begin(), inputV.end());
    
    int boundary = inputV.size();
    string subfixStr;

    for(int i = 0; i < boundary; i++) {
        for(int j = inputV.size()-1; j >= 0; j--) {
            subfixStr.append(1, inputV.at(j)); 
        }
        stringV.push_back(subfixStr);
        subfixStr.clear();
        inputV.pop_back();
    }

    sort(stringV.begin(), stringV.end());

    for(int i = 0; i < stringV.size(); i++) {
        cout << stringV.at(i) << '\n';
    }
    return 0;
}
