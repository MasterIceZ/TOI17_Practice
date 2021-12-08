/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_CEO Peatt
 * ALGO		: Dynamic Programming, Stars and Bars
 * DATE		: 6 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MOD = 9901;
int Cnr[1010][1010];
int qs[1010];

void solve(){
	memset(qs, 0, sizeof qs);
	int n, k, x;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> qs[i];
		qs[i] += qs[i - 1];
	}
	vector<int> ep;
	ep.push_back(1);
	while(k--){
		cin >> x;
		ep.push_back(x);
	}
	ep.push_back(qs[n]);
	dbg(ep);
	int ans = 1;
	for(int i=0; i<ep.size() - 1; ++i){
		int l = lower_bound(qs + 1, qs + n + 1, ep[i]) - (qs + 1);
		int r = lower_bound(qs + 1, qs + n + 1, ep[i + 1]) - (qs + 1);
		dbg(l, r);
		ans *= Cnr[ep[i + 1] - ep[i]][r - l];
		ans %= MOD;
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	Cnr[0][0] = 1;
	Cnr[1][0] = 1;
	Cnr[1][1] = 1;
	for(int i=2; i<=1000; ++i){
		for(int j=0; j<=i; ++j){
			Cnr[i][j] = Cnr[i - 1][j - 1] + Cnr[i - 1][j];
			Cnr[i][j] %= MOD;
		}
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
