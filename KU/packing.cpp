/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

void solve(){
	ll w, l, m, n;
	cin >> w >> l >> m >> n;
	ll area = w * l, lef = 1e9 + 10;
	for(ll i=m; i<=n; ++i){
		ll aleft = w % i;
		ll cur = aleft * (l % i);
		lef = min(lef, cur);
		dbg(cur);
	}
	cout << lef;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
