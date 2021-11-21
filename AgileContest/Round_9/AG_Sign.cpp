/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Sign 
 * ALGO		: Brute Force
 * DATE		: 18 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 555;

int l, r;
ll cnt;
int a[MxN];

void dfs(int u){
	dbg(u);
	if(u == r){
		if(u != 1){
			a[u] = -a[u];
		}
		++cnt;
		return ;
	}
	cnt++;
	if(u != 1){
		a[u] = -a[u];
		dfs(u - a[u]);
	}
	else{
		dfs(u + a[u]);
	}
}

void solve(){
	int n, q;
	cin >> n >> q;
	assert(n <= 500 && q <= 500);
	for(int i=1; i<=n; ++i){
		a[i] = 1;
	}
	while(q--){
		cin >> l >> r;
		cnt = 0;
		dfs(l);
		cout << cnt << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
