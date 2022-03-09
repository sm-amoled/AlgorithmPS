#include <iostream>
#include <queue>
    
using namespace std;

int N, K;
queue<int> Q;

bool visit[100001];

int main(int argc, const char * argv[]) {
    cin >> N >> K;
    
    int sec = 0;
    Q.push(N);
    visit[N] = true;
    
    if(N == K) {
        cout << "0";
        return 0;
    }
    
    // N과 K가 만날 때 까지
    while(true) {
        sec++;
        
        for(int i = Q.size(); i > 0; i--) {
            int pos = Q.front();
            Q.pop();
            
            if(pos == K) break;
            
            if(pos - 1 >= 0 && visit[pos-1] == false) {
                Q.push(pos-1);
                visit[pos-1] = true;
            }
            
            if(pos + 1 <= 100000 && visit[pos+1] == false) {
                Q.push(pos+1);
                visit[pos+1] = true;
            }
            
            if(pos * 2 <= 100000 && visit[pos*2] == false) {
                Q.push(pos*2);
                visit[pos*2] = true;
            }
        }
        
        if(visit[K]) break;
    }
    
    cout << sec;
    return 0;
}
