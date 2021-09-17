/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Inversion Count
 * ALGO		: Fenwick Tree
 * DATE		: 17 Sep 2021
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

const int MxN = 1e5+ 10;
ll tree[MxN], a[MxN];

map<ll, ll> mp;

void update(ll idx, ll val){
	for(; idx < MxN; idx += ((-idx) & idx)){
		tree[idx] += val;
		dbg(tree[idx]);
	}
}

ll query(ll idx){
	ll res = 0;
	for(; idx; idx -= ((-idx) & idx)){
		res += tree[idx];
	}
	dbg(res);
	return res;
}

void solve(){
	ll n;
	cin >> n;
	for(ll i=1; i<=n; ++i){
		cin >> a[i];
		mp[a[i]] = 1;
	}
	ll cou = 0, it = 0;
	for(auto x: mp){
		mp[x.first] = ++it;
	}
	for(ll i=n; i>=1; --i){
//		dbg(mp[i]);
		update(mp[a[i]], 1);
		cou += query(mp[a[i]] - 1);
	}
	cout << cou;
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
