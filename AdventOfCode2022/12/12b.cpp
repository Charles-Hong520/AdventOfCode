#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
#define r first
#define c second
#define pt pair<int,int>
int n,m;
int displace[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool isIn(int i, int j) {return (i>=0 && i<n && j>=0 && j<m);}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	
	string line;
	vector<string> mat;
	while(getline(cin,line)) mat.push_back(line);
	n = mat.size();
	m = mat[0].size();
	vector<vector<int>> vis(n,vector<int>(m,0));
	vector<vector<int>> dist(n,vector<int>(m,0));
	pt S,E;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++) {
		if(mat[i][j]=='S') {
			S={i,j};
			mat[i][j]='a';
		}
		if(mat[i][j]=='E') {
			E={i,j};
			mat[i][j]='z';
		}
	}
	queue<pt> q;
	vis[E.r][E.c]=1;
	q.push(E);
	while(!q.empty()) {
		pt curr = q.front();
		q.pop();

		for(auto mv:displace) {
			int nr = curr.r + mv[0];
			int nc = curr.c + mv[1];
			if(isIn(nr,nc) && vis[nr][nc]==0 
			&& (mat[nr][nc] >= mat[curr.r][curr.c] || mat[curr.r][curr.c] == mat[nr][nc]+1)) {
				//is in range and not visited and is reachable
				vis[nr][nc] = 1;
				dist[nr][nc] = 1 + dist[curr.r][curr.c];
				q.push({nr,nc});
			}
		}
	}
	// loop(i,n)loop(j,m)cout<<dist[i][j]<<(j+1==m ? "\n":"");
	int mindist = INT_MAX;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(mat[i][j]=='a') if(mindist > dist[i][j] && dist[i][j]>0) mindist=dist[i][j];
		}
	}
	cout<<mindist<<endl;
	return 0;	
}
