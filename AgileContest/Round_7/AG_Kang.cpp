/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Kang
 * ALGO		: Dynamic Programming
 * DATE		: 9 Oct 2021
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

ll a[222], b[222], c[222];
ll dp[444][444], cst[444][444];

ll divide(int l, int r){
	if(dp[l][r] != -1){
		dbg(l, r, dp[l][r]);
		return dp[l][r];
	}
	if(l == r - 1){
		dbg(l, r, cst[l][r]);
		return dp[l][r] = cst[l][r];
	}
	ll nax = -1e10;
	for(int i=l+1; i<r; ++i){
		nax = max(nax, divide(l, i) + divide(i, r));
	}
	dbg(l, r, nax);
	return dp[l][r] = nax + cst[l][r];
}

void solve(){
	int n;
	cin >> n;
	vector<ll> v;
	unordered_map<ll, int> mp;
	memset(dp, -1, sizeof dp);
	memset(cst, 0, sizeof cst);
	for(int i=1; i<=n; ++i){
		cin >> a[i] >> b[i] >> c[i];
		if(mp[a[i]] != 1){
			mp[a[i]] = 1;
			v.push_back(a[i]);
		}
		if(mp[b[i]] != 1){
			mp[b[i]] = 1;
			v.push_back(b[i]);
		}
	}
	sort(all(v));
	int it = 0;
	for(auto x: v){
		mp[x] = ++it;
	}
	for(int i=1; i<=n; ++i){
		cst[mp[a[i]]][mp[b[i]]] = c[i];
	}
	cout << divide(1, it);
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
