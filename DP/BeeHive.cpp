/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int dp[1010][1010], cnt[1010][1010];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> dp[i][j];
			if(i == 1){
				cnt[i][j] = 1;
			}
		}
	}
	for(int i=2; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(i % 2){
				dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
				if(dp[i-1][j] == dp[i-1][j-1]){
					cnt[i][j] += cnt[i-1][j] + cnt[i-1][j-1];
				}
				else if(dp[i-1][j] > dp[i-1][j-1]){
					cnt[i][j] += cnt[i-1][j];
				}
				else{
					cnt[i][j] += cnt[i-1][j-1];
				}
			}
			else{
				dp[i][j] += max(dp[i-1][j], dp[i-1][j+1]);
				if(dp[i-1][j] == dp[i-1][j+1]){
					cnt[i][j] += cnt[i-1][j] + cnt[i-1][j+1];
				}
				else if(dp[i-1][j] > dp[i-1][j+1]){
					cnt[i][j] += cnt[i-1][j];
				}
				else{
					cnt[i][j] += cnt[i-1][j+1];
				}
			}
		}
	}
	int nax = -1, ans = 0;
	for(int i=1; i<=m; ++i){
		if(dp[n][i] > nax){
			nax = dp[n][i];
			ans = 0;
		}
		if(nax == dp[n][i]){
			ans += cnt[n][i];
		}
	}
	cout << nax << " " << ans ;
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
