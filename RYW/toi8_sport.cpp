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

int n;

void rec(int w, int l, string s){
	if(w == n || l == n){
		for(auto x: s){
			cout << x << " ";
		}
		cout << "\n";
		return ;
	}
	s += 'W';
	rec(w + 1, l, s);
	s.back() = 'L';
	rec(w, l + 1, s);
}

void solve(){
	int w, l;
	cin >> n >> w >> l;
	rec(w, l, "");
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
