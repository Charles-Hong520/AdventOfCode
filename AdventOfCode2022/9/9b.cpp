#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
#define n 2000
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
	vis[n/2][n/2] = true;
	char ch; int dist;
	vector<pair<int,int>> v(10,{n/2,n/2});
	pair<int,int> p;
	int iter = 0;
	while(cin>>ch>>dist) {

		if(ch=='R') p={0,1}; 
		else if(ch=='L') p={0,-1};
		else if(ch=='D') p={1,0};
		else if(ch=='U') p={-1,0};
		else cout<<"bruh moment"<<endl;
		for(int j = 0; j < dist; j++) {
			v[0].x += p.x;
			v[0].y += p.y;
			for(int i = 0; i < 9; i++) {
				if(nir(v[i],v[i+1])) {
					if(abs(v[i].x-v[i+1].x)==1) v[i+1].x=v[i].x;
					else if(v[i].x-v[i+1].x==2) v[i+1].x++;
					else if(v[i].x-v[i+1].x==-2) v[i+1].x--;

					if(abs(v[i].y-v[i+1].y)==1) v[i+1].y=v[i].y;
					else if(v[i].y-v[i+1].y==2) v[i+1].y++;
					else if(v[i].y-v[i+1].y==-2) v[i+1].y--;
				}
			}
			vis[v[9].y][v[9].x]=true;

			// char toprint[n][n];
			// loop(i,n) loop(j,n) toprint[i][j]='.';
			// for(int i = 9; i >= 0; i--) {
			// 	toprint[v[i].y][v[i].x]=(i+'0');
			// }
			// loop(i,n) loop(j,n) cout<<toprint[i][j]<<((j+1==n)?"\n":"");
			// cout<<endl<<endl;


		}
	}
	int cnt = 0;
	loop(i,n) loop(j,n) cnt += vis[i][j];
	cout<<cnt<<endl;
	return 0;	
}
