/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Equipped
 * ALGO		: Dynamic Programming with Bitmask
 * DATE		: 17 Oct 2021
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

int dp[333];

void solve(){
	int n, k;
	cin >> n >> k;
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i=1, w; i<=n; ++i){
		cin >> w;
		int bit = 0;
		for(int j=0, x; j<k; ++j){
			cin >> x;
			bit *= 2;
			bit += x;
		}
		for(int j=0; j<(1 << k); ++j){
			dp[j | bit] = min(dp[j | bit], dp[j] + w);
		}
	}
	cout << dp[(1 << k) - 1];
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
