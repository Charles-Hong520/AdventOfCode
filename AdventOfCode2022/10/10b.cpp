#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string token,line;
	int num;
	vector<string> query;
	while(getline(cin,line)) {
		if(line=="q") break;
		if(line!="noop") {
			query.push_back("noop");
		}
		query.push_back(line);
	}
	while(query.size()<240) query.push_back("noop");

	int n = query.size();
	int sum = 1; //center of sprite
	int ans = 0;
	char board[6][40];
	char todraw;
	for(int i = 0; i < n; i++) {
		//i is position
		//i+1 is cycle
		stringstream ss(query[i]);
		ss>>token;

		// cout<<i<<" "<<sum<<endl;
		int r = i/40;
		int c = i%40;
		board[r][c] = (abs(i%40-sum) <= 1)  ? '#' : '.';
		//after
		if(token=="addx") {
			ss>>num;
			sum+=num;
		}
	}
	loop(i,6) loop(j,40) cout<<board[i][j]<<(j+1==40?"\n":"");
	return 0;	
}
