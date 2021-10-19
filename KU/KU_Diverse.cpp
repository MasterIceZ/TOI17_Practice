/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Diverse
 * ALGO		: Dynamic Programming
 * DATE		: 19 Oct 2021
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

int a[55][55], dp[55][55][11];

void solve(){
	memset(dp, 0, sizeof dp);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			dp[i][j][a[i][j]] = 1;
			for(int k=0; k<=9; ++k){
				dp[i][j][k] += dp[i][j - 1][k] + dp[i - 1][j][k] - dp[i - 1][j - 1][k];
			}
		}
	}
	int ans = 0;
	for(int i=5; i<=n; ++i){
		for(int j=5; j<=m; ++j){
			int cou = 0;
			for(int k=0; k<=9; ++k){
				cou += (dp[i][j][k] - dp[i - 5][j][k] - dp[i][j - 5][k] + dp[i - 5][j - 5][k] > 0);
			}
			ans += (cou >= 5);
		}
	}
	cout << ans;
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
