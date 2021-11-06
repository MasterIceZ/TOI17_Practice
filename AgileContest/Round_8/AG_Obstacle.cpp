/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Obstacle
 * ALGO		: Dynamic Programming
 * DATE		: 2 Nov 2021
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

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> row(n + 10, vector<int> (m + 10, 0)), col(n + 10, vector<int>(m + 10, 0));
	vector<vector<int>> dr(n + 10, vector<int> (m + 10, 1e9 + 10)), ul(n + 10, vector<int>(m + 10, 1e9 + 10));
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m - 1; ++j){
			cin >> col[i][j];
		}
	}
	for(int i=1; i<=n - 1; ++i){
		for(int j=1; j<=m; ++j){
			cin >> row[i][j];
		}
	}
	dr[1][0] = dr[0][1] = 0;
	dbg("dr");
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			dr[i][j] = min(dr[i - 1][j] + row[i - 1][j], dr[i][j - 1] + col[i][j - 1]);
		}
	}
	ul[n + 1][m] = ul[n][m + 1] = 0;
	dbg("ul");
	for(int i=n; i>=1; --i){
		for(int j=m; j>=1; --j){
			ul[i][j] = min(ul[i + 1][j] + row[i][j], ul[i][j + 1] + col[i][j]); 
		}
	}
	vector<vector<int>> dp(n + 10, vector<int> (m + 10, 1e9 + 10));
	dbg("dp");
	for(int i=n; i>=1; --i){
		for(int j=m; j>=1; --j){
			dp[i][j] = min(dp[i + 1][j], dr[i][j] + ul[i][j]);
		}
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		if(l >= n - 1 || r == 0){
			cout << -1 ;
		}
		else{
			cout << dp[l + 2][r];
		}
		cout << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
