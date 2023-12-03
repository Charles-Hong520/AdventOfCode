#include <bits/stdc++.h> //only use this for Comp-Prog

using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
ll sum = 0;
int dircnt = 0;
int lscnt = 0;

struct Node {
	string name;
	ll fs,ds;//file size, directory size
	Node* par;
	vector<Node*> dirs;
	Node() {fs=0;}
	Node(const string& n) {name=n;fs=0;}
	Node(const string& n, Node* p) {name=n;par=p;fs=0;}

	ll setSum() {
		ds=fs;
		for(Node* n : dirs) {
			this->ds += n->setSum();
		}
		return ds;
	}
	void print() {
		cout<<name<<" "<<ds<<endl;
		dircnt++;
		for(Node* n : dirs) n->print();
	}
	Node* findChild(const string& token) {
		for(Node* n : dirs) if(n->name==token) return n;
		cout<<"Bruh "<<token<<endl;
		return nullptr;
	}
};


void sumAtMost106(Node* n) {
	if(n->ds<=100000) sum+=n->ds;
	for(Node* node : n->dirs) sumAtMost106(node);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string line,token;
	getline(cin,line);
	Node* root = new Node("/");
	root->par = root;
	Node* curr = root;
	while(getline(cin, line)) {
		stringstream ss(line);
		ss>>token;
		if(token=="$") {
			//command
			ss>>token;	
			if(token=="cd") {
				ss>>token;
				if(token=="..") curr = curr->par;
				else {
					Node* next = curr->findChild(token);
					if(next) curr = next;
					else cout<<"huh? "<<token<<endl;
				}
			} else {
				lscnt++;
			}
			//ls doesn't do anything
		} else {
			//these lines are followed by ls
			if(token=="dir") {
				ss>>token; //dir name
				curr->dirs.push_back(new Node(token,curr));
			} else {
				//number
				ll sz = std::stoll(token);
				curr->fs += sz;
				ss>>token; //name of file, irrelevant
			}
		}
	}
	// ll tot = root->setSum();
	// root->print();
	sumAtMost106(root);
	cout<<sum<<" "<<lscnt<< " " << dircnt<<endl;
	return 0;	
}
