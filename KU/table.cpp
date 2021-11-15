/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: table
 * ALGO		: Dynamic Programming
 * DATE		: 13 Nov 2021
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

int dp[1010][1010], qs[1010][1010];

void solve(){
	int l, w, n, a, b, x, y;
	cin >> l >> w >> n;
	for(int i=1; i<=n; ++i){
		cin >> a >> b >> x >> y;
		for(int j=a; j<x; ++j){
			for(int k=b; k<y; ++k){
				dp[j][k] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i=2; i<l; ++i){
		for(int j=2; j<w; ++j){
			int cou = 0;
			for(int x=i-2; x<=i; ++x){
				for(int y=j-2; y<=j; ++y){
					cou += dp[x][y];
				}
			}
			cnt += !cou;
		}
	}
//	for(int i=0; i<=l; ++i){
//		for(int j=0; j<=w; ++j){
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
	cout << cnt;
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
