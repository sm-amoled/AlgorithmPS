#include <iostream>
#include <vector>

using namespace std;

struct bulk {
    int weight;
    int height;
    int rank = 1;
};

int compare(bulk a, bulk b) {
    if(a.weight > b.weight && a.height > b.height) {
        return 1;
    } else if (a.weight < b.weight && a.height < b.height) {
        return 2;
    } else {
        return 0;
    }
}

int main() {
    int N;
    cin >> N;
    
    bulk input;
    vector<bulk> people(N);
    
    for(int i = 0; i < N; i++) {
        cin >> input.weight >> input.height;
        people[i] = input;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            switch(compare(people[i], people[j])) {
                case 1 : 
                    people[j].rank++;
                    break;
                case 2 :
                    people[i].rank++;
                    break;
                default :
                    break;
            } 
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << people[i].rank << " ";
    }
    
	return 0;
}