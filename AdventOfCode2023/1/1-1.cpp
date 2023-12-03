#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(ll i = 0; i < n; i++)
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string str;
	ifstream fin("i2.txt");
	long long sum = 0;
	while(getline(fin,str)) {
		vector<char> v;
		for(char c : str) {
			if(c <= '9' && c >= '0') v.push_back(c);
		}
		sum += (v[0]-'0') * 10 + v.back()-'0';
	}
	cout<<sum<<endl;
}
