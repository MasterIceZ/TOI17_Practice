/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Peatt Matter
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

bool dp[55][20020];

void solve(){
	memset(dp, false, sizeof dp);
	int n, sum = 0;
	cin >> n;
	dp[0][10000] = true;
	for(int x, i=1; i<=n; ++i){
		cin >> x;
		sum += x;
		for(int k=n/2; k>=1; --k){
			for(int j=0; j<=20000; ++j){
				if(j - x >= 0 && j - x <= 20000){
					dp[k][j] |= dp[k - 1][j - x];
				}
			}
		}
	}
	int ans = 1e9;
	for(int i=0; i<=20000; ++i){
		if(dp[n / 2][i]){
			ans = min(ans, abs(2 * (i - 10000) - sum));
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
		solve();
		cout << endl;
	}
	return 0;
}
