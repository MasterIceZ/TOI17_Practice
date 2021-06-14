/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Fence TOI9
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int dp[555][555];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=k; ++i){
		int x, y;
		cin >> x >> y;
		dp[x+1][y+1] = 1;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	int ans = -1, sz = min(n, m);
	for(int k=1; k<=sz; ++k){
		for(int i=k; i<=n; ++i){
			for(int j=k; j<=m; ++j){
				int out = dp[i][j] + dp[i-k][j-k] - dp[i][j-k] - dp[i-k][j];
				int in = dp[i-1][j-1] + dp[i-k+1][j-k+1] - dp[i-1][j-k+1] - dp[i-k+1][j-1];
				if(in == out){
					ans = max(ans, k);
				}
			}
		}
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 2;
//	cin >> q;
	while(q--){
		memset(dp, 0, sizeof dp);
		solve();
		cout << endl;
	}
	return 0;
}
