#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	long long sum = 0;
	while(cin>>s) {
		int half = s.size()/2;
		vector<char> inter(10,' ');
		sort(s.begin(), s.begin()+half);
		sort(s.begin()+half, s.end());
		auto it = set_intersection(s.begin(),s.begin()+half,s.begin()+half,s.end(),inter.begin());
		if(inter[0]<='Z' && 'A'<=inter[0]) sum += 26-'A';
		else sum -= 'a';
		sum += inter[0]+1;
	}
	cout<<sum<<endl;

	return 0;	
}
