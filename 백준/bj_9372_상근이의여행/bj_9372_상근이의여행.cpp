#include <iostream>
#include <stack>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

struct Union_Find {
    int parent[1001];
    int size[1001];

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
    
    int T;
    cin >> T;

    while(T--) {
        int N, M;
        cin >> N >> M;
        
        int result = 0;

        Union_Find UF = Union_Find(N);

        for(int i = 0; i < M; i++) {
            int A, B;
            cin >> A >> B;
        
            if(UF.find(A) != UF.find(B)) {
                UF.unite(A, B);
                result++;
            }
        }

        cout << result << '\n';
    }

    return 0;
}