/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Binary Lemon Tree
 * ALGO		: Dynamic Programming
 * DATE		: 6 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MOD = 909091;

ll dp[10010];

void solve(){
	ll a;
	cin >> a;
	dp[0] = 1;
	for(int i=1; i<=a; ++i){
		for(int j=0; j<i; ++j){
			dp[i] += (dp[j] * dp[i - j - 1]) % MOD;
			dp[i] %= MOD;
		}
	}
	cout << dp[a];
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
