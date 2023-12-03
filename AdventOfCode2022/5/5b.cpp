#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<string> v= {
		"","DTWFJSHN","HRPQTNBG","LQV","NBSWRQ",
		"NDFTVMB","MDBVHTR","DBQJ","DNJVRZHQ","BNHMS"
	};
	string fills,newstr="";
	int cnt,src,dst;
	while(cin>>fills>>cnt>>fills>>src>>fills>>dst) {
		newstr = "";
		int n = v[src].size();
		for(int i = 0; i < cnt; i++) {
			newstr += v[src].back();
			v[src].pop_back();
		}
		reverse(newstr.begin(),newstr.end());
		v[dst] += newstr;
	}
	for(string s:v)cout<<s.back();
	return 0;	
}
