#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s1,s2,s3;
	int inter, sum = 0;
	while(cin>>s1>>s2>>s3) {
		vector<int> v('z'+1,0);

		for(char c:s1) v[c] |= 0x001;
		for(char c:s2) v[c] |= 0x010;
		for(char c:s3) v[c] |= 0x100;
		for(int i = 0; i < v.size(); i++) {
			if(v[i]==0x111) inter = i;
		}
		if(inter<='Z' && 'A'<=inter) sum += 26-'A';
		else sum -= 'a';
		sum += inter+1;
	}
	cout<<sum<<endl;

	return 0;	
}
