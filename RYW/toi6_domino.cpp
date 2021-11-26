/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi6_domino
 * ALGO		: Brute Force
 * DATE		: 25 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int n;

void rec(int x, vector<string> v){
	if(x == n){
		for(auto x: v){
			cout << x << "\n";
		}
		cout << "E\n";
		return ;
	}
	if(x + 1 <= n){
		v.push_back("--");
		rec(x + 1, v);
		v.pop_back();
	}
	if(x + 2 <= n){
		v.push_back("||");
		rec(x + 2, v);
		v.pop_back();
	}
}

void solve(){
	cin >> n;
	rec(0, {});
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
