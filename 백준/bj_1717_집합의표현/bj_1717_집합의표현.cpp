#include <iostream>

const int SIZE = 1000001;
using namespace std;

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

    bool isSameSet(int A, int B) {
        return find(A) == find(B);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    union_find UF = union_find(n);

    while(m--) {
        int type, a, b;
        cin >> type >> a >> b;

        if(!type) UF.unite(a, b);
        else {
            cout << ((UF.isSameSet(a, b))? "YES\n":"NO\n");
        }
    }

    return 0;
}
