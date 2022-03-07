#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, budget, temp, max = 0;
    
    vector<int> urban; 
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        urban.push_back(temp);
        if(max < temp) {
            max = temp;
        }
    }
    cin >> budget;
    
    int left = 0, right = max, mid, result;
    long sum;
    while(left <= right) {
        mid = (left+right)/2;
        
        sum = 0;
        for(auto x : urban) {
            if(x<mid) sum += x;
            else sum += mid;
        }
        
        if(budget < sum) {
            right = mid-1;
        } else {
            left = mid+1;
            result = mid;
        }
    }

    printf("%d\n", result);
    return 0;
}