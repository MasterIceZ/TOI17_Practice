/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Punch Nun
 * ALGO		: Dynamic Programming
 * DATE		: 3 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 2020;
int a[MxN], dp[MxN][MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - a[i]);
		for(int j=1; j<=i; ++j){
			dp[i][j] = max(dp[i - 1][j + 2] - a[i], dp[i - 1][j - 1] + a[i]);
		}
	}
	cout << dp[n][0];
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
