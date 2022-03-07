#include <iostream>
#include <vector>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

const int SIZE = 202;

struct union_find {
    int parent[SIZE];
    int size[SIZE] = {0,};

    union_find(int n) {
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(node == parent[node]) return node;
        
        int temp = find(parent[node]);
        parent[node] = temp;
        return temp;
    }

    void unite(int A, int B) {
        A = find(A);
        B = find(B);

        if(size[A] < size[B]) swap(A, B);

        parent[B] = A;
        size[A] += size[B];
    }
};

int main() {
    FAST;
    
    int n, m;
    cin >> n >> m;

    union_find UF = union_find(n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int connect;
            cin >> connect;

            if(i > j && connect) {
                UF.unite(i, j);
            }
        }
    }

    bool isSameSet = true;
    int root;

// 첫번째 방문할 도시 <- 비교 기준으로 삼음
    cin >> root;
    root = UF.find(root);

    for(int i = 1; i < m; i++) {
        int node;
        cin >> node;

        if(root != UF.find(node)) {
            isSameSet = false;
            break;
        }   
    }

    if(isSameSet) cout << "YES";
    else cout << "NO";

    return 0;
}
