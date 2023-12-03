#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string tmp;
	vector<string> mat;
	while(cin>>tmp) mat.push_back(tmp);
	int n = mat.size();
	int m = mat[0].size();
	bool vis[n][m];
	loop(i,n)loop(j,m)vis[i][j]=false;
	for(int i = 0; i < n; i++) {
		vis[i][0] = vis[i][m-1] = true;
	}
	for(int i = 0; i < m; i++) {
		vis[0][i] = vis[n-1][i] = true;
	}
	char tall;
	for(int i = 1; i+1 < n; i++) {
		tall = mat[i][0];
		for(int j = 1; j+1 < m; j++) {
			if(tall < mat[i][j]) vis[i][j]=true;
			tall = max(tall,mat[i][j]);
		}
		tall = mat[i][m-1];
		for(int j = m-2; j > 0; j--) {
			if(tall < mat[i][j]) vis[i][j]=true;
			tall = max(tall,mat[i][j]);
		}
	}
	for(int j = 1; j+1 < m; j++) {
		tall = mat[0][j];
		for(int i = 1; i+1 < n; i++) {
			if(tall < mat[i][j]) vis[i][j]=true;
			tall = max(tall,mat[i][j]);
		}
		tall = mat[n-1][j];
		for(int i = n-2; i > 0; i--) {
			if(tall < mat[i][j]) vis[i][j]=true;
			tall = max(tall,mat[i][j]);
		}
	}
	int cnt = 0;
	loop(i,n)loop(j,m)if(vis[i][j]) cnt++;
	// loop(i,n)loop(j,m)cout<<vis[i][j]<<(j+1==m?"\n":"");
	cout<<cnt<<endl;
	return 0;	
}
