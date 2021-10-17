/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Jimmy Bond
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

int n;
double a[22][22], dp[22][(1 << 20) + 10];

double divide(int state, int bit){
	if(state == n + 1){
		return 1;
	}
	if(dp[state][bit] != -1){
		return dp[state][bit];
	}
	double res = 0;
	for(int i=0; i<n; ++i){
		if((bit & (1 << i)) == 0){
			res = max(res, a[state][i] * divide(state + 1, bit | (1 << i)));
		}
	}
	return dp[state][bit] = res;
}

void solve(){
	cin >> n;
	for(int i=0; i<=20; ++i){
		for(int j=0; j<=(1 << n); ++j){
			dp[i][j] = -1;
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=0; j<n; ++j){
			cin >> a[i][j];
			a[i][j] /= 100;
		}
	}
	cout << fixed << setprecision(2) << divide(1, 0) * 100;
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
