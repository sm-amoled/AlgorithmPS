 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int cmp;
    int start = 0, end = arr.size()-1;
    int result = 0;

    cin >> cmp;

    while(start < end) {
        int sum = arr[start] + arr[end];
        if(sum > cmp) {
            end--;
        } else if (sum < cmp) {
            start++;
        } else {
            result++;
            start++;
            end--;
        }
    }

    cout << result;
    return 0;
}