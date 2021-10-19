/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Stairs
 * ALGO		: Dynamic Programming
 * DATE		: 19 Oct 2021
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

const int MxN = 50050;
int a[MxN], dp[3][2 * MxN];

void solve(){
	int l, r, ans, ans2;
	cin >> l >> r;
	ans = dp[0][r] - dp[0][max(0, l - 1)];
	ans2 = dp[1][r] - dp[1][max(0, l - 1)];
	dbg(l, r, ans, ans2);
	cout << ans << " " << ans2;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q = 1;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	cin >> q;
	for(int i=2; i<=n; ++i){
		int l = min(a[i], a[i - 1]) + 1;
		int r = max(a[i], a[i - 1]) - 1;
		if(l > r){
			continue;
		}
		if(l % 2){
			dp[1][l] += 1;
			dp[0][l + 1] += 1;
		}
		else{
			dp[0][l] += 1;
			dp[1][l + 1] += 1;
		}
		if(r % 2){
			dp[1][r + 2] -= 1;
			dp[0][r + 1] -= 1;
		}
		else{
			dp[1][r + 1] -= 1;
			dp[0][r + 2] -= 1;
		}
	}
	for(int i=2; i<=100000; ++i){
		dp[0][i] += dp[0][i - 2];
		dp[1][i] += dp[1][i - 2];
	}
	for(int i=1; i<=100000; ++i){
		dp[0][i] += dp[0][i - 1];
		dp[1][i] += dp[1][i - 1];
	}
	for(int i=1; i<=10; ++i){
		dbg(dp[0][i], dp[1][i], i);
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
