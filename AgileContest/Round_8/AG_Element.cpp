/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Element
 * ALGO		: Depth First Search
 * DATE		: 2 Nov 2021
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

const int MxN = 1010;
vector<int> adj[MxN];
int in[MxN], rk[MxN], have[MxN][64];
int now[64], nax = -1;
// Max Rank -> 60

void dfs(int u, int v){
	rk[u] = v;
	nax = max(nax, v);
	for(auto x: adj[u]){
		dfs(x, v + 1);
	}
}

void solve(){
	int n, x;
	memset(now, 0, sizeof now);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> x;
		for(int j=0; j<60; ++j){
			now[j] += have[x][j];
		}
	}
	for(int i=0; i<nax; ++i){
		if(now[i] % 2 == 1){
			cout << i ;
			return ;
		}
//		dbg(i);
		now[i + 1] += now[i] / 2;
	}
	cout << nax - 1;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int u, v, n, m, k, q = 1;
	cin >> n >> m >> k >> q;
	// 0 -> Greatest uwu
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[v].push_back(u);
	}
	// always can go to `0`
	dfs(0, 1);
//	dbg(nax);
	for(int i=0; i<n; ++i){
//		dbg(rk[i]);
		rk[i] = nax - rk[i];	
	}
	for(int i=0, xx; i<m; ++i){
		cin >> xx;
		for(int j=1, x; j<=xx; ++j){
			cin >> x;
			have[i][rk[x]] += 1;
		}
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
