#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
int myRes(int n1,int n2) {
	if(n1==n2) return 3;
	if((n1+1)%3 == n2%3) return 6;
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<char,int> mp;
	mp['A'] = 1; //rock
	mp['B'] = 2; //paper
	mp['C'] = 3; //scissor
	mp['X'] = 1; //rock
	mp['Y'] = 2; //paper
	mp['Z'] = 3; //scissor
	ifstream fin("2a.txt");
	char ch1,ch2;
	int sum = 0;
	while(fin>>ch1>>ch2) {
		sum+=mp[ch2]+myRes(mp[ch1],mp[ch2]);
	}
	cout<<sum<<endl;
	return 0;	
}
