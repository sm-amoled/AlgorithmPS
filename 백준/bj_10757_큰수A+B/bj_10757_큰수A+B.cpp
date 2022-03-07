#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string Ainput, Binput;
	cin >> Ainput >> Binput;
	
	vector<int> result;
	vector<char> A(Ainput.begin(), Ainput.end());
	vector<char> B(Binput.begin(), Binput.end());
	
	int digit = 0;
	int carryBit = 0;
	while(!A.empty() && !B.empty()) {
	    int temp = (A.back()-'0') + (B.back()-'0') + carryBit;
	    if(temp >= 10) {
	        carryBit = 1;
	        temp -= 10;
	    } else {
	        carryBit = 0;
	    }
	    result.push_back(temp);
	    A.pop_back();
	    B.pop_back();
	}
	
	while(!A.empty()) {
	    int temp = A.back()-'0' + carryBit;
        
        if(temp >= 10) {
            carryBit = 1;
            temp -= 10;
        } else {
            carryBit = 0;
        }
        
        result.push_back(temp);
        A.pop_back();
	}
	
	while(!B.empty()) {
	    int temp = B.back()-'0' + carryBit;
        
        if(temp >= 10) {
            carryBit = 1;
            temp -= 10;
        } else {
            carryBit = 0;
        }
        
        result.push_back(temp);
        B.pop_back();
	}
	
	if(carryBit) {
	    result.push_back(carryBit);
	}
	
	for(int i = result.size()-1; i >= 0; i--) {
	    cout << result[i];
	}
	
	return 0;
}