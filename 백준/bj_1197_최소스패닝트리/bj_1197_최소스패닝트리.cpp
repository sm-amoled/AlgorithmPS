#include <iostream>
#include <queue>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

struct Union_Find {
    int parent[10001];
    int size[10001];

    Union_Find(int n) {
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        int temp = node;
        while(parent[node] != node) {
            node = parent[node];
        }
        parent[temp] = node;
        return node;
    }

    void unite(int A, int B) {
        A = find(A);
        B = find(B);

        if(size[A] > size[B]) {
            swap(A, B);
        }

        parent[A] = B;
        size[B] += size[A];
    }
};

int main() {
    FAST;
    
    int V, E;
    cin >> V >> E;
    
    int selectedEdges = 0;
    int result = 0;

    Union_Find UF = Union_Find(V);
    priority_queue<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < E; i++) {
        int A, B, W;
        cin >> A >> B >> W;
        edges.push(make_pair(-W, make_pair(A, B)));
    }

    while(selectedEdges != V-1) {
        int A = edges.top().second.first;
        int B = edges.top().second.second;
        int W = edges.top().first;
        edges.pop();

        if(UF.find(A) != UF.find(B)) {
            result += -W;
            selectedEdges++;
            UF.unite(A, B);
        }
    }

    cout << result << '\n';

    return 0;
}