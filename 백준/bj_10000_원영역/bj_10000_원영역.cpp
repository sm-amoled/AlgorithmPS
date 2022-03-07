#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

struct circle {
    long long from, to, pointer;

    circle(int A, int B) {
        from = A;
        to = B;
        pointer = A;
    }
};

bool cmp(circle A, circle B) {
    if(A.from == B.from) {
        return A.to > B.to;
    }
    return A.from < B.from;
}

int main() {
    FAST;

    int N;
    cin >> N;
    int result = N+1;

    vector<circle> map;
    for(int i = 0; i < N; i++) {
        int pos, rad;
        cin >> pos >> rad;
        map.push_back(circle(pos-rad, pos+rad));
    }

    sort(map.begin(), map.end(), cmp);
    
    stack<circle> st;
    for(int i = 0; i < N; i++) {
        if(!st.empty()) {
            while(!st.empty() && st.top().to <= map[i].from) {
                if(st.top().pointer == st.top().to) result++;
                st.pop();
            }
            if(!st.empty()) {
                if(st.top().pointer == map[i].from) {
                    st.top().pointer = map[i].to;
                }
            } 
        } 
        st.push(map[i]);
    }
    while(!st.empty()) {
        if(st.top().pointer == st.top().to) result++;
        st.pop();
    }

    cout << result;

    return 0;