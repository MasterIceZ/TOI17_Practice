/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pot
 * ALGO		: Dynamic Programming
 * DATE		: 10 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MOD = 2009;
int dp[100100];

void solve(){
	int n, k;
	cin >> n >> k;
	dp[0] = 1;
	for(int i=1; i<=n; ++i){
		dp[i] += 2 * dp[i - 1];
		dp[i] %= MOD;
		if(i > k){
			dp[i] -= dp[i - k - 1];
		}
		dp[i] += MOD;
		dp[i] %= MOD;
	}
	cout << (dp[n] - dp[n - 1] + MOD) % MOD;
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
