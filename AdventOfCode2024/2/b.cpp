#include <bits/stdc++.h>

using namespace std;

bool fsafe(const vector<int>& v) {
    bool flag = 1;
    for(int i = 1; i < v.size() && flag; i++) {
        if(!(v[i]-v[i-1] <= 3 && v[i]-v[i-1] >= 1)) flag = 0;
    }
    return flag;
}

bool bsafe(const vector<int>& v) {
    bool flag = 1;
    for(int i = 1; i < v.size() && flag; i++) {
        if(!(v[i-1]-v[i] <= 3 && v[i-1]-v[i] >= 1)) flag = 0;
    }
    return flag;
}
int main(int argc, char** argv) {
    ifstream fin(argv[1]);
    string line;
    int sum = 0;
    while(getline(fin, line)) {
        stringstream ss(line);
        int num;
        vector<int> v,tmp;
        while(ss >> num) {
            v.push_back(num);
        }

        bool flag = fsafe(v) || bsafe(v);
        for(int i = 0; i < v.size(); i++) {
            tmp = v;
            tmp.erase(tmp.begin() + i);
            flag = flag || fsafe(tmp) || bsafe(tmp);
        }
        sum += flag;

    }
    cout<<sum<<endl;
}