#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> city(N);
    vector<int> distance(N-1);
    
    for(int i = 0; i < N-1; i++) {
        cin >> distance[i];
    }
    
    long long cost = 0;
    long long beforePrice;
    
    cin >> beforePrice;
    for(int i = 1; i < N; i++) {
        cost += beforePrice * distance[i-1];
        
        int input;
        cin >> input;
        if(beforePrice > input) beforePrice = input;
    }
    
    cout << cost;
    
      
    return 0;
} 