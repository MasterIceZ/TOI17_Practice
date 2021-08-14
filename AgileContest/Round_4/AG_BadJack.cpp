/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Bad Jack
 * ALGO		: Data Structure
 * DATE		: 14 Aug 2021
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

const ll MxN = 1e6 + 10;
ll dpr[MxN], dpc[MxN], qsr[MxN], qsc[MxN];

void solve(){
	ll x, n, m, k, d;
	cin >> n >> m >> k >> d;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> x;
			qsr[i] += x, qsc[j] += x;
		}
	}
	priority_queue<ll> pqr, pqc;
	// ROW
	for(int i=1; i<=n; ++i){
		pqr.push(qsr[i]);
	}
	for(int i=1; i<=k; ++i){
		ll nowr = pqr.top();
		pqr.pop();
		dpr[i] = dpr[i - 1] + nowr;
		pqr.push(nowr - m * d);
	}
	// COLUMN
	for(int j=1; j<=m; ++j){
		pqc.push(qsc[j]);
	}
	for(int i=1; i<=k; ++i){
		ll nowc = pqc.top();
		pqc.pop();
		dpc[i] = dpc[i - 1] + nowc;
		pqc.push(nowc - n * d);
	}
	ll ans = -1e18;
	for(int i=0; i<=k; ++i){
		ans = max(ans, dpr[i] + dpc[k - i] - (i * (k - i) * d));
	}
	cout << ans;
	// Clear
	memset(qsr, 0, sizeof qsr), memset(dpr, 0, sizeof dpr);
	memset(qsc, 0, sizeof qsc), memset(dpc, 0, sizeof dpc);
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
