#include <bits/stdc++.h>

using namespace std;
int main(int argc, char** argv) {
    ifstream fin(argv[1]);
    int a,b;
    vector<int> x,y;
    while(fin>>a>>b) {
        x.push_back(a);
        y.push_back(b);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int sum = 0;
    for(int i = 0; i < x.size(); i++) sum += abs(x[i]-y[i]);
    cout<<sum<<endl;
}