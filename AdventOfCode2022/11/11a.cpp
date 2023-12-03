#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
int doOp(int old, const char op, int num) {
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
	int n = 8;
	vector<char> ops = {'*', '+', '+', '+', '+', '*', '^', '+'};
	// vector<char> ops = {'*', '+', '^', '+'};
	vector<int> nums = {2,   3,   6,   5,   8,   5,   2,   4};
	// vector<int> nums = {19, 6, 2, 3};
	vector<int> div(n),t(n),f(n);
	vector<queue<int>> v(n);
	string tmp,line;
	int bruh = 0;
	loop(i,n) {
		bruh = i*100;
		getline(cin,line); //Monkey #
		getline(cin,line); //start 
		stringstream ss(line);
		ss>>tmp>>tmp; //starting items:
		while(ss>>tmp) { //takes in numbers
			v[i].push(stoi(tmp));
			// cout<<stoi(tmp)<<endl;
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
		div[i]=stoi(tmp);

		getline(cin,line); //if true
		reset(ss);
		ss<<line;
		ss>>tmp>>tmp>>tmp>>tmp>>tmp; //if true: throw to monkey
		ss>>tmp;
		t[i]=stoi(tmp);
		getline(cin,line); //if false
		reset(ss);
		ss<<line;
		ss>>tmp>>tmp>>tmp>>tmp>>tmp; // if false: throw to monkey
		ss>>tmp;
		f[i]=stoi(tmp);
		getline(cin,line);
	}
	vector<int> touch(n,0);
	loop(z,20) {
		loop(i,n) {
			while(!v[i].empty()) {
				touch[i]++;
				int worry = v[i].front();
				v[i].pop();
				worry = doOp(worry, ops[i], nums[i]);
				worry /= 3;
				if(worry%div[i]==0) {
					v[t[i]].push(worry);
				} else {
					v[f[i]].push(worry);
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
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
