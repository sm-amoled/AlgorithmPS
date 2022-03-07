
int main(){

    
    return 0;

}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> vinum(n+1);
    vector<int> vinumMax(n+1, 0);
    
    cin >> vinum[1] >> vinum[2];
    vinumMax[1] = vinum[1];
    vinumMax[2] = vinum[1] + vinum[2];
    
    for(int i = 3; i <= n; i++) {
        cin >> vinum[i];
        
        vinumMax[i] = max(vinumMax[i-2] + vinum[i], vinumMax[i-3]+vinum[i-1]+vinum[i]);
        vinumMax[i] = max(vinumMax[i], vinumMax[i-1]);
    }
    
    cout << vinumMax[n];
    return 0;
}