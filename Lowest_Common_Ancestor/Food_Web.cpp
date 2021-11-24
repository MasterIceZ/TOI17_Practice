/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Food web
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
int dp[LG][MxN];
int level[MxN], in[MxN];

void dfs(int u, int p){
	level[u] = level[p] + 1;
	dp[0][u] = p;
	for(auto x: adj[u]){
		dfs(x, u);
	}
}


void solve(){
	int n, u, v, q;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		in[v]++;
		adj[u].push_back(v);
	}
	for(int i=1; i<=n; ++i){
		if(in[i] == 0){
			dfs(i, 0);
		}
	}
	for(int i=1; i<LG; ++i){
		for(int j=1; j<=n; ++j){
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		if(level[a] > level[b]){
			swap(a, b);
		}
		for(int i=20; i>=0; --i){
			if(level[dp[i][b]] < level[a]){
				continue;
			}
			b = dp[i][b];
		}
		if(a == b){
			cout << a << "\n";
			continue ;
		}
		for(int i=20; i>=0; --i){
			if(dp[i][a] != dp[i][b]){
				a = dp[i][a];
				b = dp[i][b];
			}
		}
		cout << dp[0][a] << "\n";
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
