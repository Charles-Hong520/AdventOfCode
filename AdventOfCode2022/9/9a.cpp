#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
#define n 1001
#define y first
#define x second

bool vis[n][n];

bool nir(const pair<int,int>& h, const pair<int,int>& t) {
	return (abs(t.y - h.y)>1 || abs(t.x - h.x)>1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	loop(i,n) loop(j,n) vis[i][j]=false;
	vis[500][500] = true;
	char ch; int dist;
	pair<int,int> t = {500,500};
	pair<int,int> h = {500,500};
	pair<int,int> p;
	while(cin>>ch>>dist) {
		if(ch=='R') p={0,1}; 
		else if(ch=='L') p={0,-1};
		else if(ch=='D') p={1,0};
		else if(ch=='U') p={-1,0};
		else cout<<"bruh moment"<<endl;
		for(int i = 0; i < dist; i++) {
			h.x += p.x;
			h.y += p.y;
			if(nir(h,t)) {
				if(abs(h.x-t.x)==1) t.x=h.x;
				else if(h.x-t.x==2) t.x++;
				else if(h.x-t.x==-2) t.x--;

				if(abs(h.y-t.y)==1) t.y=h.y;
				else if(h.y-t.y==2) t.y++;
				else if(h.y-t.y==-2) t.y--;
			}
			vis[t.y][t.x]=true;
		}
	}
	int cnt = 0;
	loop(i,n) loop(j,n) cnt += vis[i][j];
	cout<<cnt<<endl;
	return 0;	
}
