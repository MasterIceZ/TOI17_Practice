/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 0/1 KnapSack
 * ALGO		: Dynamic Programming
 * DATE		: 16 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int dp[10010][10010];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		int v, w;
		cin >> v >> w;
		for(int j=1; j<w; ++j){
			dp[i][j] = dp[i-1][j];
		}
		for(int j=w; j<=m; ++j){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
		}
	}
	cout << dp[n][m];
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
