#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while(true) {
        int n;
        cin >> n; 
    
        if(n==0) return 0;
        
        vector<int> histogram(n);
        vector<int> stack;
        
        for(int i = 0; i < n; i++) {
            cin >> histogram[i];
        }
        
        long result = 0;
        
        for(int i = 0; i < n; i++) {
            while(!stack.empty() && histogram[i] < histogram[stack.back()]) {
                long h = histogram[stack.back()];
                stack.pop_back();
                long l = i;
                
                if(!stack.empty())
                     l = i - stack.back() - 1;
                if(result < l*h) result = l*h;
            }
            
            stack.push_back(i);
        }
        
        while(!stack.empty()) {
            long h = histogram[stack.back()];
            long l = n;
            stack.pop_back();
            
            if(!stack.empty())
                l = n - stack.back() - 1;
            if(result < l*h) 
                result = l*h;
        }
        
        cout << result << '\n';
    }
    
   return 0;
}