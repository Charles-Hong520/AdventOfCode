#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<char,int> mp;
	string s;
	cin>>s;
	int distinct = 4;
	distinct--;
	for(int i = 0; i < distinct; i++) mp[s[i]]++;
	for(int i = distinct; i < s.size(); i++) {
		mp[s[i]]++;
		if(mp.size()==distinct+1) {
			cout<<i+1<<endl;
			return 0;
		}
		if(--mp[s[i-distinct]]==0) mp.erase(s[i-distinct]);
	}
}
