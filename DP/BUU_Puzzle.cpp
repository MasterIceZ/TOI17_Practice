/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: BUU Puzzle
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

const int state[] = {0, 1, 2, 4, 5, 8, 9, 10, 16, 17, 18, 20, 21};

int a[10][50500], dp[33][50500];

void solve(){
	memset(dp, 0, sizeof dp);
	int n;
	cin >> n;
	for(int i=0; i<5; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	for(int j=1; j<=n; ++j){
		for(int i=0; i<13; ++i){
			int res = 0;
			for(int k=0; k<5; ++k){
				if(state[i] & (1 << k)){
					res += a[k][j];
				}
			}
			for(int k=0; k<13; ++k){
				if(!(state[i] & state[k])){
					dp[i][j + 1] = max(dp[i][j + 1], dp[k][j] + res);
				}
			}
		}
	}
	int nax = 0;
	for(int i=0; i<13; ++i){
		nax = max(nax, dp[i][1 + n]);
	}
	cout << nax;
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
