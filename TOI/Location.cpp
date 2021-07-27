/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Location TOI8
 * ALGO		: Dynamic Programming
 * DATE		: 21 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;
int dp[1111][1111];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> dp[i][j];
			dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
		}
	}
	int nax = 0;
	for(int i=k; i<=n; ++i){
		for(int j=k; j<=m; ++j){
			nax = max(nax, dp[i][j] + dp[i-k][j-k] - dp[i-k][j] - dp[i][j-k]);
		}
	}
	cout << nax;
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
