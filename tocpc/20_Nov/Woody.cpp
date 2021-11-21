/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Woody
 * ALGO		: Dynamic Programming
 * DATE		: 20 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1010;
ll dp[555][555];
tuple<int, int, ll> a[MxN];

void solve(){
	int n, X, Y, u, v;
	ll w;
	cin >> n >> X >> Y;
	for(int i=0; i<=X; ++i){
		for(int j=0; j<=Y; ++j){
			dp[i][j] = 1e18 + 10;
		}
	}
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i){
		cin >> u >> v >> w;
		a[i] = make_tuple(u, v, w);
	}
	for(int k=1; k<=n; ++k){
		tie(u, v, w) = a[k];
//		for(int i=0; i<=X; ++i){
//			for(int j=0; j<=Y; ++j){
//				dp[i][j] = min(dp[i][j], dp[max(0, i - u)][max(0, j - v)] + w);
//			}
//		}
		for(int i=X; i>=0; --i){
			for(int j=Y; j>=0; --j){
				dp[i][j] = min(dp[i][j], dp[max(0, i - u)][max(0, j - v)] + w);
			}
		}
	}
//	for(int i=0; i<=X; ++i){
//		for(int j=0; j<=Y; ++j){
//			cout << (dp[i][j] >= 1e9 ? -1: dp[i][j]) << " ";
//		}
//		cout << "\n";
//	}
	cout << (dp[X][Y] == 1e18 + 10 ? -1: dp[X][Y]);
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
