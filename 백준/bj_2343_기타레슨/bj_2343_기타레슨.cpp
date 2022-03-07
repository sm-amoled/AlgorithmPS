#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> Lesson(N);
    
    int maxLength = 0, sumLength = 0;
    for(int i = 0; i < N; i++) {
        cin >> Lesson[i];
        if(maxLength < Lesson[i]) maxLength = Lesson[i];
        sumLength += Lesson[i];
    }
    
    int left = maxLength, right = sumLength;
    while(left <= right) {
        int mid = (left+right)/2;
        int count = 0, sum = 0;
        
        for(int i = 0; i < N; i++) {
            sum += Lesson[i];
            
            if(sum > mid) {
                sum = Lesson[i];
                count++;
            }
        }    
        
        if(count >= M) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    printf("%d", left);
    return 0;
}