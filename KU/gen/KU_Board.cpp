/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Board
 * ALGO		: Array
 * DATE		: 23 Oct 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

ll v[2222][2222];

void solve(){
	ll s, n, m;
	cin >> n >> m >> s;
	for(ll i=1; i<=n; ++i){
		for(ll j=1; j<=m; ++j){
			cin >> v[i][j];
			v[i][j] += s * i;
		}
	}
	ll cnt = 0;
	for(ll j=1; j<=m; ++j){
		for(ll i=1; i<=n; ++i){
			cnt += (v[i][j] <= v[i - 1][j]);
			v[i][j] = max(v[i][j], v[i - 1][j]);
		}
	}
	cout << n * m - cnt;
	memset(v, 0, sizeof v);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
