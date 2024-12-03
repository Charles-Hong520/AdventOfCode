#include <bits/stdc++.h>

using namespace std;
int main(int argc, char** argv) {
    ifstream fin(argv[1]);
    int x,y;
    vector<int> a;
    map<int,int> b;
    while(fin>>x>>y) {
        a.push_back(x);
        b[y]++;
    }
    int sum = 0;
    for(int i = 0; i < a.size(); i++) {
        sum += a[i] * b[a[i]];
    }
    cout<<sum<<endl;
}