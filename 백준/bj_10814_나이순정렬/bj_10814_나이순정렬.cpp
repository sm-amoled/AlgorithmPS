#include <iostream>
#include <algorithm>
using namespace std;

struct member {
    int age;
    char* name;
};

bool compare(member a, member b) {
    return a.age < b.age;
}

int main() {
    int number, age, nameIndex;
    char name[101];
    char* tempName;
    cin >> number;
    
    member* memberList = new member[number];
    
    for(int i = 0; i < number; i++) {
        nameIndex = 0;
        
        scanf("%d %s", &age, name);
        memberList[i].age = age;
        
        tempName = new char[(int)sizeof(name)/(int)sizeof(char)];
        while(name[nameIndex] != 0) {
            tempName[nameIndex] = name[nameIndex];
            nameIndex++;
        }
        
        tempName[nameIndex]=0;
        memberList[i].name = tempName;
}
    
    // sort(memberList, memberList+number, compare);
    stable_sort(memberList, memberList+number, compare);
    
    for(int i = 0; i < number; i++) {
        printf("%d %s\n", memberList[i].age, memberList[i].name);
    }
    
    return 0;
}