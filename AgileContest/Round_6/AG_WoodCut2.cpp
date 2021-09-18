/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Wood Cut
 * ALGO		: Dynamic Programming
 * DATE		: 18 Sep 2021
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

const ll MOD = 1e9 + 7;
ll qs[100100], dp[100100], a[100100];

void solve(){
	int l, r;
	cin >> l >> r;
	ll lhs = (MOD + qs[r] - qs[l - 1]) % MOD;
	lhs = (lhs * qs[r]) % MOD;
	ll rhs = (MOD + dp[r] - dp[l - 1]) % MOD;
	cout << (lhs - rhs + MOD) % MOD;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1, n;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		qs[i] = qs[i - 1] + a[i];
		qs[i] %= MOD;
		dp[i] = dp[i - 1] + (a[i] * qs[i]) % MOD;
		dp[i] %= MOD;
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
