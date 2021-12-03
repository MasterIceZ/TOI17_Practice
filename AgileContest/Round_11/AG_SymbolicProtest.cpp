/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Symbolic Protest
 * ALGO		: Dynamic Programming
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

const ll MOD = 1e9 + 7;
const int MxN = 1000100;
ll dp[MxN], qs[MxN], sum[MxN], m;

ll mod(ll n){
	return ((n % MOD) + MOD) % MOD;
}

void solve(){
	int n, k;
	cin >> n >> m >> k;
	sum[0] = 1;
	for(int i=1; i<k; ++i){
		sum[i] = mod(sum[i - 1] * m);
		dp[i] = sum[i];
		qs[i] = mod(qs[i - 1] + sum[i]);
	}
	for(int i=k; i<=n; ++i){
		dp[i] = mod((m - 1) * mod(qs[i - 1] - qs[i - k]));
		sum[i] = mod(sum[i - 1] * m);
		qs[i] = mod(qs[i - 1] + dp[i]);
	}
	cout << mod(sum[n] - dp[n]);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
