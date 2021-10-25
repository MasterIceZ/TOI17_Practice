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

int divide(int bit){
	if(__builtin_popcount(bit) == k){
		return 0;
	}
	if(dp[bit] != -1){
		return dp[bit];
	}
	dbg(bit);
	int res = 1e9 + 10;
	for(int i=0; i<n; ++i){
		if((bit & (1 << i)) == 0){
			continue;
		}
		for(int j=0; j<n; ++j){
			if((bit & (1 << j)) == 0){
				continue;
			}
			if(i == j){
				continue;
			}
			res = min(res, a[i][j] + divide(bit ^ (1 << i)));
			dbg(bit ^ (1 << i), res);
		}
	}
	return dp[bit] = res;
}

void solve(){
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> a[i][j];
		}
	}
	cout << divide((1 << n) - 1);
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
