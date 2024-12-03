#include <bits/stdc++.h>

using namespace std;
int main(int argc, char** argv) {
    ifstream fin(argv[1]);
    string line;
    int sum = 0;
    while(getline(fin, line)) {
        stringstream ss(line);
        int num;
        vector<int> v;
        while(ss >> num) {
            v.push_back(num);
        }
        bool flag = 1;
        for(int i = 1; i < v.size() && flag; i++) {
            if(!(v[i]-v[i-1] <= 3 && v[i]-v[i-1] >= 1)) flag = 0;
        }
        if(flag) {
            sum ++;
            continue;
        }
        flag = 1;
        for(int i = 1; i < v.size() && flag; i++) {
            if(!(v[i-1]-v[i] <= 3 && v[i-1]-v[i] >= 1)) flag = 0;
        }
        sum += flag;
    }
    cout<<sum<<endl;
}