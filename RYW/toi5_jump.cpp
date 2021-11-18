/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi5_jump
 * ALGO		: Dynamic Programming
 * DATE		: 17 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int dp[99999], a[30300];

void solve(){
	int n, k, res = 0;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[a[i]] += 1;
	}
	for(int i=1; i<=90000; ++i){
		dp[i] += dp[i - 1];
	}
	for(int i=1; i<=n; ++i){
		res = max(res, dp[a[i] + k] - dp[a[i]]);
	}
	cout << res;
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
