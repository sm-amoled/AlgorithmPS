#include <iostream>
#include <vector>

using namespace std;

int minValue = 1000000001, maxValue = -1000000001;
int N, op[4];
vector<int> A;

void findMinMax(int beforeResult, int index) {
    if(index == N) {
        if(minValue > beforeResult) minValue = beforeResult;
        if(maxValue < beforeResult) maxValue = beforeResult;
        return;
    }
    
    int nextResult;
    for(int i = 0; i < 4; i++) {
        if(op[i]) {
            op[i]--;
            switch(i) {
                case 0 : 
                    nextResult = beforeResult + A[index];
                    break;
                case 1 :
                    nextResult = beforeResult - A[index];
                    break;
                case 2 :
                    nextResult = beforeResult * A[index];
                    break;
                case 3 :
                    nextResult = beforeResult / A[index];
                    break;
                }
            findMinMax(nextResult, index+1);
            op[i]++;
        }
    }
}

int main() {
    
    // input
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp; cin >> temp;
        A.push_back(temp);
    }
    for(int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    
    // back tracking
    findMinMax(A[0], 1);
    
    cout << maxValue << '\n' << minValue;
    
	return 0;
}