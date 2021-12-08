/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Dualfuel
 * ALGO		: Sliding Windows
 * DATE		: 2 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 2000200;
ll a[3][MxN];

void solve(){
	ll n, v;
	cin >> n >> v;
	for(int i=0; i<n; ++i){
		cin >> a[0][i];
	}
	for(int i=0; i<n; ++i){
		cin >> a[1][i];
	}
	ll ans = 0;
	for(int k=0; k<2; ++k){
		deque<pair<ll, ll>> dq; // (idx, val)
		dq.emplace_back(0, a[k][0]);
		for(int i=1; i<=n; ++i){
			while(!dq.empty() && v + dq.front().first < i){
				dq.pop_front();
			}
			ans += dq.front().second;
			dbg(dq.front().first, dq.front().second, i);
			while(!dq.empty() && dq.back().second > a[k][i]){
				dq.pop_back();
			}
			dq.emplace_back(i, a[k][i]);
		}
	}
	cout << ans;
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
