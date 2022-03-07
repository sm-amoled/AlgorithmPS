#include <iostream>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

const int SIZE = 1000000;

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
    FAST;

    int n, m;
    cin >> n >> m;

    union_find UF = union_find(n);

    int min_m;
    bool cycle = false;

    for(int i = 1; i <= m; i++) {
        int A, B;
        cin >> A >> B;

        if(UF.find(A) == UF.find(B) && !cycle) {
            cycle = true;
            min_m = i;
        }

        UF.unite(A, B);
    }

    cout << ((cycle)? min_m : 0);

    return 0;
}
