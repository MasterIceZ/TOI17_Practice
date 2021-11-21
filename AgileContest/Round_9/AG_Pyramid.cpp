/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Pyramid
 * ALGO		: Dynamic Programming, Math
 * DATE		: 18 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MOD = 1e9 + 7;
const int MxN = 1e7 + 10;

ll dp[MxN];

void solve(){
	int x;
	cin >> x;
	cout << dp[x];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 6;
	for(int i=4; i<=MxN - 10; ++i){
		dp[i] = dp[i - 2] * 3 + dp[i - 1] * 2;
		dp[i] %= MOD;
	}
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
