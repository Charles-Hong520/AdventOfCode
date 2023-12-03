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
	while(query.size()<221) query.push_back("noop");

	int n = query.size();
	int sum = 1;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		stringstream ss(query[i-1]);
		ss>>token;

		// cout<<i<<" "<<sum<<endl;
		if(i%40==20 && i < 221) {
			ans += i*sum;
			cout<<i<<" "<<sum<<endl;
		}
		if(token=="addx") {
			ss>>num;
			sum+=num;
		}
	}
	cout<<ans<<endl;
	return 0;	
}
