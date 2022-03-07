#include <iostream>
#include <algorithm>
using namespace std;

struct position{
    int xPos;
    int yPos;
};

bool compare(position a, position b) {
    if(a.yPos == b.yPos) {
        return a.xPos < b.xPos;
    } else {
        return a.yPos < b.yPos;
    }
}

int main() {
    int count;
    cin >> count;
    position* posArray = new position[count];
    
    for(int i = 0; i < count; i++) {
        scanf("%d %d", &posArray[i].xPos, &posArray[i].yPos);
    }
    
    sort(posArray, posArray+count, compare);
    
    for(int i = 0; i < count; i++) {
        printf("%d %d\n", posArray[i].xPos, posArray[i].yPos);
    }
    return 0;
}		