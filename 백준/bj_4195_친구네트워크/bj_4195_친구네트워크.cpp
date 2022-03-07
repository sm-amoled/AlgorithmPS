#include <iostream>
#include <string>
#include <unordered_map>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

struct union_find {
    unordered_map<string, pair<string, int>> map;

    string find(string name) {
        if(map.find(name) != map.end()) {
            if(name == map[name].first) return name;
            
            string temp = find(map[name].first);
            map[name].first = temp;
            return temp;
        } else {
            map.insert(make_pair(name, make_pair(name, 1)));
            return name;
        }
    }

    void unite(string A, string B) {
        A = find(A);
        B = find(B);

        if(A==B) {
            cout << max(map[A].second, map[B].second) << '\n';
            return;
        }

        if(map[A].second < map[B].second) swap(A, B);

        map[B].first = A;
        map[A].second += map[B].second;
        
        cout << map[A].second <<'\n';
    }
};

int main() {
    FAST;
    
    int T;
    cin >> T;

    while(T--) {
        
        int F;
        cin >> F;

        union_find UF;

        while(F--) {
            string firstName, secondName;
            cin >> firstName >> secondName;

            UF.unite(firstName, secondName);
        }
    }

    return 0;
}
