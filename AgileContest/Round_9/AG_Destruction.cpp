/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Distruction
 * ALGO		: Dynamic Programming
 * DATE		: 21 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 50050;
ll dp[2][MxN], qs[MxN], dp2[2][MxN];

void solve(){
	memset(dp, 0, sizeof dp);
	memset(dp2, 0, sizeof dp2);
	int n, k, m;
	cin >> n >> k >> m;
	for(int i=1; i<=n; ++i){
		cin >> qs[i];
		qs[i] += qs[i - 1];
	}
	for(int i=1; i<=n; ++i){
		dp2[0][i] = min(dp2[0][i - 1], -qs[i]);
	}
	for(int i=1; i<=k; ++i){
		int cur = i * m + i - 1;
		dp[i % 2][cur - 1] = dp2[i % 2][cur - 1] = 1e18;
		for(int j=cur; j<=n; ++j){
			dp[i % 2][j] = min(dp[i % 2][j - 1], qs[j] + dp2[(i + 1) % 2][j - m]);
			dp2[i % 2][j] = min(dp2[i % 2][j - 1], dp[i % 2][j - 1] - qs[j]);
		}
	}
	cout << qs[n] - dp[k % 2][n];
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
