#include <iostream>
#include <vector>

using namespace std;

int minValue = 1000000;
int N, stat[20][20];
vector<int> start(10, 0);
vector<int> link(10, 0);

void makeLinkTeam() {
    int startIndex = 0;
    int linkIndex = 0;
    
    for(int i = 1; i <= N; i++) {
        if(start[startIndex] == i) {
            startIndex++;
        } else {
            link[linkIndex] = i;
            linkIndex++;
        } 
    }
}

int getTeamPoint(vector<int> team) {
    int sum = 0;
    
    for(int first = 0; first < N/2; first++) {
        for(int second = 0; second < N/2; second++) {
            sum += stat[team[first]-1][team[second]-1];
        }
    }
    
    return sum;
}

void team(int memberBefore, int memberIndex) {
    if(memberIndex >= N/2) {
        makeLinkTeam();
        
        int result = getTeamPoint(start) - getTeamPoint(link);
        result = (result > 0)? result:0-result;
        
        minValue = (result < minValue)? result : minValue;
        return;
    }
    
    for(int i = memberBefore+1; i < N; i++) {
        start[memberIndex] = i;
        team(i, memberIndex+1);
    }
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> stat[i][j];
        }
    }
    
    team(0, 0);
    
    cout << minValue;
    
	return 0;
}