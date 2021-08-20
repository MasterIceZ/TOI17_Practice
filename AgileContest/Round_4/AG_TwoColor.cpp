/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Two Colour
 * ALGO		: Matrix Exponential
 * DATE		: 16 Aug 2021
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

const ll MOD = 98765431;
ll dp[66][4][4], ans[4][4], tmp[4][4];

ll tmx[4][4] = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}};
ll t[4][4] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 0}};


void solve(){
	ll n;
	cin >> n;
	memcpy(ans, tmx, sizeof tmx);
	n -= 1;
	for(int state=60; state>=0; --state){
		if(n & (1ll << state)){
			for(int i=0; i<3; ++i){
				for(int j=0; j<3; ++j){
					tmp[i][j] = 0;
					for(int k=0; k<3; ++k){
						tmp[i][j] += dp[state][i][k] * ans[k][j];
						tmp[i][j] %= MOD;
					}
				}
			}
			memcpy(ans, tmp, sizeof tmp);
		}
	}
	cout << (ans[0][0] + ans[1][0] + ans[2][0]) % MOD;
				
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	memcpy(dp[0], t, sizeof t);
	for(int state=1; state<=60; ++state){
		for(int i=0; i<3; ++i){
			for(int j=0; j<3; ++j){
				for(int k=0; k<3; ++k){
					dp[state][i][j] += dp[state - 1][i][k] * dp[state - 1][k][j];
					dp[state][i][j] %= MOD;
				}
			}
		}
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
