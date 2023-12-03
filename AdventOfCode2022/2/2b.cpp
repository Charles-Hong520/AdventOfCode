#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
int myShape(int n1,int n2) {
	int ans = 0;
	if(n2==0) { //lose
		ans = n1+2;
	} else if(n2==3) { //draw
		ans = n1;
	} else { //win
		ans = n1+1;
	}
	if(ans>3) ans-=3; 
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<char,int> mp;
	mp['A'] = 1; //rock
	mp['B'] = 2; //paper
	mp['C'] = 3; //scissor
	mp['X'] = 0; //lose
	mp['Y'] = 3; //draw
	mp['Z'] = 6; //win
	ifstream fin("2a.txt");
	char ch1,ch2;
	int sum = 0;
	while(fin>>ch1>>ch2) {
		sum+=mp[ch2]+myShape(mp[ch1],mp[ch2]);
	}
	cout<<sum<<endl;
	return 0;	
}
