/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

ll calc(int n){
	string s[5];
	getline(cin, s[0]);
	getline(cin, s[1]);
	getline(cin, s[2]);
	ll sum = 0;
	for(int i=0; i<n*4; i+=4){
		sum *= 10;
		if(s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
		&& s[1][i] == '|' && s[1][i+1] == ' ' && s[1][i+2] == '|'
		&& s[2][i] == '|' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 0;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == ' ' && s[0][i+2] == ' '
				&&	s[1][i] == ' ' && s[1][i+1] == ' ' && s[1][i+2] == '|'
				&&	s[2][i] == ' ' && s[2][i+1] == ' ' && s[2][i+2] == '|'){
			sum += 1;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == ' ' && s[1][i+1] == '_' && s[1][i+2] == '|'
				&&	s[2][i] == '|' && s[2][i+1] == '_' && s[2][i+2] == ' '){
			sum += 2;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == ' ' && s[1][i+1] == '_' && s[1][i+2] == '|'
				&&	s[2][i] == ' ' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 3;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == ' ' && s[0][i+2] == ' '
				&&	s[1][i] == '|' && s[1][i+1] == '_' && s[1][i+2] == '|'
				&&	s[2][i] == ' ' && s[2][i+1] == ' ' && s[2][i+2] == '|'){
			sum += 4;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == '|' && s[1][i+1] == '_' && s[1][i+2] == ' '
				&&	s[2][i] == ' ' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 5;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == '|' && s[1][i+1] == '_' && s[1][i+2] == ' '
				&&	s[2][i] == '|' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 6;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == ' ' && s[1][i+1] == ' ' && s[1][i+2] == '|'
				&&	s[2][i] == ' ' && s[2][i+1] == ' ' && s[2][i+2] == '|'){
			sum += 7;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == '|' && s[1][i+1] == '_' && s[1][i+2] == '|'
				&&	s[2][i] == '|' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 8;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == '|' && s[1][i+1] == '_' && s[1][i+2] == '|'
				&&	s[2][i] == ' ' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 9;
		}
	}
	return sum;
}

void solve(){
	int n, m;
	string t;
	getline(cin, t);
	stringstream ss(t);
	ss >> n >> m;
	dbg(n, m);
	cout << calc(n) + calc(m);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
