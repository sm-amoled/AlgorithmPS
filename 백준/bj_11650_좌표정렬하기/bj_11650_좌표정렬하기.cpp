#include <iostream>
#include <algorithm>
using namespace std;

struct position {
    int xPos;
    int yPos;
};

bool compare(position a, position b) {
    if(a.xPos == b.xPos) {
        return a.yPos < b.yPos;
    } else {
        return a.xPos < b.xPos;
    }
}

int main() {
    int number, xPos, yPos;
    cin >> number;
    
    position* posArray = new position[number];
    
    for(int i = 0; i < number; i++) {
        scanf("%d %d", &xPos, &yPos);
        posArray[i].xPos = xPos;
        posArray[i].yPos = yPos;
    }
    
    sort(posArray, posArray + (number), compare);
    
    for(int i = 0; i < number; i++) {
        printf("%d %d\n", posArray[i].xPos, posArray[i].yPos);
    }
    
    return 0;
}