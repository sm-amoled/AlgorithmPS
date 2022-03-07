#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct student {
    string name;
    int korean;
    int english;
    int math;
};

bool cmp(student a, student b) {
    if(a.korean == b.korean) {
        if(a.english == b.english) {
            if(a.math == b.math) {
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.english < b.english;
    }
    return a.korean > b.korean;
}

int main() {
    int count;
    cin >> count;

    vector<student> studV;
    student std;
    int tempKor, tempEng, tempMath;
    string tempName;

    for(int i = 0; i < count; i++) {
        cin >> tempName;
        scanf("%d %d %d", &tempKor, &tempEng, &tempMath);
        std = student {tempName, tempKor, tempEng, tempMath};
        studV.push_back(std);    
    }

    sort(studV.begin(), studV.end(), cmp);

    for(int i = 0; i < count; i++) {
       cout << studV.at(i).name << '\n';
    }
    return 0;
}