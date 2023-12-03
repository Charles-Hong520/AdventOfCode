#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int l1,l2,r1,r2,cnt=0;
	char c;
	while(cin>>l1) {
		cin.get(c);
		cin>>r1;
		cin.get(c);
		cin>>l2;
		cin.get(c);
		cin>>r2;
		if((l1<=l2 && r2<=r1) || (l2<=l1 && r1<=r2)) cnt++;
	}
	cout<<cnt<<endl;

	return 0;	
}
