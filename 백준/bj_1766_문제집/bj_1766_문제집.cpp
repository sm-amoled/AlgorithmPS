#include <iostream>
#include <vector>
#include <queue>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

int main() {
    FAST;

    int N, M;
    cin >> N >> M;

    vector<int> indegree(N+1);
    vector<vector<int>> nextQ(N+1, vector<int>(0));

    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        indegree[to]++;
        nextQ[from].push_back(to);
    }

    priority_queue<int> sequence;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0)
            sequence.push(-i);
    }

    while(!sequence.empty()) {
        int node = -sequence.top();
        sequence.pop();

        cout << node << ' ';
        for(auto x : nextQ[node]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                sequence.push(-x);
            }
        }
    }

    return 0;
}