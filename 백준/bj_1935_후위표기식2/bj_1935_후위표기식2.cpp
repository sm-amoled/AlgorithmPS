#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    
    string stack;
    cin >> stack;
    
    vector<int> variable(N);
    vector<double> calc;
    
    char temp;
    
    for(int i = 0; i < N; i++) {
        cin >> variable[i];
    }
    
    for(int i = 0; i < stack.size(); i++) {
        temp = stack[i];
        
        if(temp >= 'A' && temp <= 'Z') {
            calc.push_back(variable[temp-'A']);
        } else {
            double a, b;
            b = calc.back();
            calc.pop_back();
            a = calc.back();
            calc.pop_back();
                    
            switch(temp) {
                case '+':
                    calc.push_back(a+b);
                    break;
                case '-':
                    calc.push_back(a-b);
                    break;
                case '*':
                    calc.push_back(a*b);
                    break;
                case '/':
                    calc.push_back(a/b);
                    break;
            }
        }
    }
    
    cout << setprecision(2) << fixed;
    cout << calc.back();
    
    return 0;
}