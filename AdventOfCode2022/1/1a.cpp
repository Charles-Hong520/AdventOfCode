#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	int n,mx=0;
	ifstream fin("1.txt");

	while(!fin.eof()) { 
		int sum = 0;
		while(getline(fin,s)) {
			if(s.empty() || s=="") break;
			n = std::stoi(s);
			sum += (int) n;
		}
		mx = max(sum,mx);
	}
	fin.close();
	cout<<mx<<endl;
};