/*
https://codingzzangmimi.tistory.com/17 를 보고 공부함!
*/
#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int d[500000];
 
int main() {
 
    int n;
    int bi[8001] = { 0, };
    int sum = 0, bm = 0, cm = 0, dm = 0;
 
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
        sum += d[i];
 
        int x = d[i] + 4000;
        bi[x]++;
    }
 
    sort(d, d + n);
 
    int maximum = 0;
    for (int i = 0; i <= d[n - 1] + 4000; i++)
    {
        if (bi[i] > maximum)
            maximum = bi[i];
    }
 
    vector <int> v;
    for (int i = 0; i <= d[n - 1] + 4000; i++)
    {
        if (bi[i] == maximum)
            v.push_back(i);
    }
 
    float am = float(sum) / float(n);
 
    if (am >= 0)
        am = int(am + 0.5);
    else
        am = int(am - 0.5);
 
    bm = d[n / 2];
 
    if (v.size() > 1)
        cm = v[1] - 4000;
    else
        cm = v[0] - 4000;
 
    dm = d[n - 1] - d[0];
 
    printf("%d\n", int(am));
    printf("%d\n", bm);
    printf("%d\n", cm);
    printf("%d\n", dm);
 
    return 0;
}