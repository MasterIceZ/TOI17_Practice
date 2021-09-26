/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Castle Stair
 * ALGO		: Dynamic Programming
 * DATE		: 26 Sep 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const ll MOD = 95959;
ll a[100100], dp[100100];

void solve(){
	ll n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	dp[1] = 1;
	for(int i=2; i<=n; ++i){
		int idx = lower_bound(a + 1, a + n + 1, a[i] - k) - (a + 1);
		dp[i] = 2 * dp[i - 1] - dp[idx] + MOD;
		dp[i] %= MOD; 
	}
	cout << (dp[n] - dp[n - 1] + MOD) % MOD;
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
