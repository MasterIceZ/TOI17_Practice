/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 333;
int dp[MxN];

void solve(){
	int n, l, h, r;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> l >> h >> r;
		for(int j=l; j<r; ++j){
			dp[j] = max(h, dp[j]);
		}
	}
	int cur = 0;
	for(int i=1; i<=255; ++i){
		if(dp[i] != cur){
			cout << i << " " << dp[i] << " ";
			cur = dp[i];
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
