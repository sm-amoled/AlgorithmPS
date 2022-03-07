#include <iostream>
using namespace std;
int arr[10001]={0,};

int main() {
    int number;
    int temp;
    int max = 0;
    
    cin >> number;
    
    for(int i = 0; i < number; i++) {
        scanf("%d", &temp);
        arr[temp]++;
        // max = (temp > max)? temp : max;
        if(temp > max) max = temp;
    }
    
    for(int i = 1; i <= max; i++) {
        for(int j = 0; j < arr[i]; j++) {
            printf("%d\n", i);
        }
        // if(arr[i] == 0) continue;
        // while(arr[i] != 0) {
        //     cout << i << "\n";
        //     arr[i]--;
        // }
    }
    
    return 0;
}