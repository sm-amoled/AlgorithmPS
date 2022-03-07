#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N;
    cin >> N;
    vector<int> A(N); 
    int* X = new int[N] {0,};
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int maxLength = 0;
    for(int i = 0; i < N; i++) {
        
        // 제일 긴 값보다 더 길면?
        if(X[maxLength] < A[i]) {
            X[++maxLength] = A[i];
        }
        // 중간에 들어올 수 있는 값이면?
        else {
            int left = 0, right = maxLength;
            while(left < right) {       
                int mid = (left+right)/2;
                
                if(X[mid] >= A[i]) {    
                    right = mid;        
                } else {
                    left = mid + 1;
                }
            }
            
        // A[i]보다 큰 최소인 수랑 바꾸기
            X[left] = A[i];
        }
    }


    cout << maxLength;
    
    return 0;
}