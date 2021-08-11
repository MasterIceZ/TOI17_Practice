/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Taep in Dragon Castle
 * ALGO		: Dynamic Programming
 * DATE		: 10 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[33][33], dp[33][33];

void solve(){
	int r, c, k, mod;
	cin >> r >> c >> k >> mod;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			a[i][j] = 1;
		}
	}
	for(int i=1; i<k; ++i){
		for(int i=1; i<=r; ++i){
			for(int j=1; j<=c; ++j){
				dp[i][j] = (a[i][j] + a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1]) % mod;
			}
		}
		memcpy(a, dp, sizeof dp);
	}
	int ans = 0;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			ans += a[i][j];
			ans %= mod;
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
		memset(a, 0, sizeof a);
		memset(dp, 0, sizeof dp);
		solve();
		cout << endl;
	}
	return 0;
}
