/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Food Web
 * ALGO		: Lowest Common Ancestor
 * DATE		: 23 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;
const int LG = 22;
vector<int> adj[MxN];
int in[MxN], level[MxN];
int dp[LG][MxN];

void dfs(int u, int p){
	level[u] = level[p] + 1;
	dp[0][u] = p;
	for(auto x: adj[u]){
		dfs(x, u);
	}
}

void solve(){
	int n, q, u, v;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		in[v]++;
	}
	for(int i=1; i<=n; ++i){
		if(!in[i]){
			dfs(i, 0);
		}
	}
	for(int k=1; k<LG; ++k){
		for(int i=1; i<=n; ++i){
			dp[k][i] = dp[k - 1][dp[k - 1][i]];
		}
	}
	cin >> q;
	while(q--){
		cin >> u >> v;
		if(level[u] > level[v]){
			swap(u, v);
		}
		for(int k=20; k>=0; --k){
			if(level[u] > level[dp[k][v]]){
				continue;
			}
			v = dp[k][v];
		}
		if(u == v){
			cout << u << "\n";
			continue;
		}
		for(int k=20; k>=0; --k){
			if(dp[k][u] != dp[k][v]){
				u = dp[k][u];
				v = dp[k][v];
			}
		}
		cout << dp[0][u] << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
