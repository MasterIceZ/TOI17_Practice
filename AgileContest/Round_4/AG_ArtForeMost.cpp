/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Art ForeMost
 * ALGO		: Dynamic Programming
 * DATE		: 14 Aug 2021
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
const int MOD = 1e9 + 7;

int dp[111][111];

void solve(){
	memset(dp, 0, sizeof dp);
	dp[2][1] = dp[1][2] = 1;
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(dp[i][j] != 0){
				continue;
			}
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			dp[i][j] %= MOD;
			for(int x=i-1; x>=1; --x){
				if(i-x > k){
					break;
				}
				dp[i][j] += dp[x - 1][j - 1] + 1;
				dp[i][j] %= MOD;
			}
			for(int x=j-1; x>=1; --x){
				if(j - x > k){
					break;
				}
				dp[i][j] += dp[i - 1][x - 1] + 1;
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[n][n] ;
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
