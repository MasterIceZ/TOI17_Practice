<<<<<<< HEAD
/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Cute Company
 * ALGO		: Dynamic Programming
 * DATE		: 24 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MOD = 1e9 + 7;

int dp[10010];

void solve(){
	int n, m, k;
	memset(dp, 0, sizeof dp);
	cin >> n >> k >> m;
	if(m != 1){
		return ;
	}
	dp[0] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=min(k, n); ++j){
			dp[i] += dp[i - j];
			dp[i] %= MOD;
		}
	}
	cout << dp[n];
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
=======
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

int dp[10010];
int n;

int DP(int k){
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=min(i, k); ++j){
			dp[i] += dp[i-j];
			dp[i] %= MOD;
		}
	}
	return dp[n];
}

void query(){
	int k, m;
	cin >> n >> k >> m;
	cout << (DP(k) - DP(m-1) + MOD) % MOD;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		query();
		cout << "\n";
	}	
	return 0;
}
>>>>>>> 080028add9a8426e7da1b959769b0909645958cc
