#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
vector<string> mat;
int n,m;
int brute(int r, int c) {
	int currh = mat[r][c];
	int cnt1=0,cnt2=0,cnt3=0,cnt4 = 0;
	for(int i = r-1; i >= 0; i--) {
		cnt1++;
		if(currh <= mat[i][c]) break;
	}

	for(int i = r+1; i < n; i++) {
		cnt2++;
		if(currh <= mat[i][c]) break;
	}
	for(int j = c-1; j >= 0; j--) {
		cnt3++;
		if(currh <= mat[r][j]) break;
	}

	for(int j = c+1; j < m; j++) {
		cnt4++;
		if(currh <= mat[r][j]) break;
	}
	return cnt1*cnt2*cnt3*cnt4;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string tmp;
	int ans = 0;
	while(cin>>tmp) mat.push_back(tmp);
	n = mat.size();
	m = mat[0].size();
	for(int i = 1; i+1 < n; i++) {
		for(int j = 1; j+1 < m; j++) {
			ans = max(ans,brute(i,j));
		}
	}
	// loop(i,n)loop(j,m)cout<<vis[i][j]<<(j+1==m?"\n":"");
	cout<<ans<<endl;
	return 0;	
}
