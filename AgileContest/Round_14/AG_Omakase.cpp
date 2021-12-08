/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Omakase
 * ALGO		: Dynamic Programming 
 * DATE		: 7 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;
int dp[33][33][33][33];
int mp[9090], tmp[9090], v[33][33], m;

void clear(int *a){
	for(int i=1; i<=m; ++i){
		a[i] = 0;
	}
}

int rec(int a, int b, int c, int d){
	dbg(a, b, c, d);
	if(dp[a][b][c][d] != -1){
		return dp[a][b][c][d];
	}
	if(a > c || b > d){
		return dp[a][b][c][d] = 0;
	}
	if(a == c || b == d){
		int res = 0;
		clear(tmp);
		for(int i=a; i<=c; ++i){
			for(int j=b; j<=d; ++j){
				tmp[v[i][j]]++;
				if(mp[v[i][j]] == tmp[v[i][j]]){
					res++;
				}
			}
		}
		return dp[a][b][c][d] = res;
	}
	
	int A = rec(a, b + 1, c, d) + rec(a, b, c, b);
	int B = rec(a, b, c, d - 1) + rec(a, d, c, d);
	int C = rec(a + 1, b, c, d) + rec(a, b, a , d);
	int D = rec(a, b, c - 1, d) + rec(c, b, c, d);

	return dp[a][b][c][d] = max({A, B, C, D});
}

void solve(){
	memset(dp, -1, sizeof dp);
	memset(mp, 0, sizeof mp);
	int r, c;
	cin >> r >> c >> m;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> v[i][j];
			mp[v[i][j]]++;
		}
	}
	cout << rec(1, 1, r, c);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
