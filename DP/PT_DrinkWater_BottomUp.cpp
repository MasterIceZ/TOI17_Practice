/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Drink Water
 * ALGO		: Dynamic Programming with Bitmasks
 * DATE		: 24 Oct 2021
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

int a[22][22], k, n;
int dp[1 << 21];

void solve(){
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> a[i][j];
		}
	}
	memset(dp, 0x3f, sizeof dp);
	dp[(1 << n) - 1] = 0;
	int ans = 1e9 + 10;
	for(int i=(1 << n) - 1; i>=0; --i){
		for(int j=0; j<n; ++j){
			if((i & (1 << j)) == 0){
				continue;
			}
			for(int k=0; k<n; ++k){
				if((i & (1 << k)) == 0 || k == j){
					continue;
				}
				dp[i ^ (1 << j)] = min(dp[i ^ (1 << j)], a[j][k] + dp[i]);
			}
		}
		if(__builtin_popcount(i) <= k){
			ans = min(ans, dp[i]);
		}
	}
//	int ans = 1e9 + 10;
//	for(int i=(1 << n) - 1; i>=0; --i){
//		if(__builtin_popcount(i) == k){
//			ans = min(ans, dp[i]);
//		}
//	}
	cout << ans;
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
