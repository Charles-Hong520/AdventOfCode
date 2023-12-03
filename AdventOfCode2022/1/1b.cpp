#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	string s;
	int n,mx=0;
	ifstream fin("2.txt");
	vector<int> v;
	while(!fin.eof()) { 
		int sum = 0;
		while(getline(fin,s)) {
			if(s.empty() || s=="") break;
			n = std::stoi(s);
			sum += (int) n;
		}
		v.push_back(sum);
	}
	sort(v.rbegin(), v.rend());
	fin.close();
	cout<<v[0]+v[1]+v[2]<<endl;
	return 0;	
}
