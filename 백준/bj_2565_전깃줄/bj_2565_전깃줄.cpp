#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line {
    int start, end;
};

bool compareLine(line a, line b) {
    return a.start < b.start;   
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	vector<line> lines(N);
	
	for(int i = 0; i < N; i++) {
	    line temp;
	    cin >> temp.start >> temp.end;
	    lines[i] = temp;
	}
	
	sort(lines.begin(), lines.end(), compareLine);
	
	vector<int> dp;
	dp.push_back(lines[0].end);
	for(auto x : lines) {
	   if(dp.back() < x.end) {
	       dp.push_back(x.end);
	   } else {
	       vector<int>::iterator point = lower_bound(dp.begin(), dp.end(), x.end);
	       *point = x.end;
	   }
	}
	
	cout << N - dp.size();
	return 0;
}

  	