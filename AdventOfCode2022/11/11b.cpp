#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(ll i = 0; i < n; i++)
typedef unsigned long long ll;
ll doOp(ll old, const char op, ll num) {
	if(op=='+') return old + num;
	if(op=='*') return old * num;
	if(op=='^') return old * old;
}
void reset(std::stringstream& stream)
{
    const static std::stringstream initial;
    
    stream.str(std::string());
    stream.clear();
    stream.copyfmt(initial);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n = 8;
	vector<char> ops = {'*', '+', '+', '+', '+', '*', '^', '+'};
	vector<ll> nums = {2,   3,   6,   5,   8,   5,   2,   4};
	// ll n = 4;
	// vector<char> ops = {'*', '+', '^', '+'};
	// vector<ll> nums = {19, 6, 2, 3};
	vector<ll> div(n),t(n),f(n);
	vector<queue<ll>> v(n);
	string tmp,line;
	ll bruh = 0;
	loop(i,n) {
		bruh = i*100;
		getline(cin,line); //Monkey #
		getline(cin,line); //start 
		stringstream ss(line);
		ss>>tmp>>tmp; //starting items:
		while(ss>>tmp) { //takes in numbers
			v[i].push(stoll(tmp));
			// cout<<stoll(tmp)<<endl;
		}
		getline(cin,line); //operation
		reset(ss); 
		ss<<line;
		ss>>tmp>>tmp>>tmp>>tmp; //Operation: new = old
		ss>>tmp>>tmp; //operator, number (hard coded)

		getline(cin,line); //test
		reset(ss);
		ss<<line;
		ss>>tmp>>tmp>>tmp; //Test: divisible by
		ss>>tmp;
		div[i]=stoll(tmp);

		getline(cin,line); //if true
		reset(ss);
		ss<<line;
		ss>>tmp>>tmp>>tmp>>tmp>>tmp; //if true: throw to monkey
		ss>>tmp;
		t[i]=stoll(tmp);
		getline(cin,line); //if false
		reset(ss);
		ss<<line;
		ss>>tmp>>tmp>>tmp>>tmp>>tmp; // if false: throw to monkey
		ss>>tmp;
		f[i]=stoll(tmp);
		getline(cin,line);
	}
	vector<ll> touch(n,0);
	loop(z,10000) {
		loop(i,n) {
			while(!v[i].empty()) {
				touch[i]++;
				ll worry = v[i].front();
				v[i].pop();
				worry = doOp(worry, ops[i], nums[i]);
				ll mod = 9699690;
				if(worry%div[i]==0) {
					v[t[i]].push(worry%mod);
				} else {
					v[f[i]].push(worry%mod);
				}
			}
		}
	}
	for(ll i = 0; i < n; i++) {
		cout<<"Monkey "<<i<<": ";
		while(v[i].empty()==0) {
			cout<<v[i].front()<< " ";
			v[i].pop();
		}
		cout<<endl;
	}
	std::sort(touch.rbegin(), touch.rend());
	cout<<touch[0]*touch[1]<<endl;
	return 0;	
}
