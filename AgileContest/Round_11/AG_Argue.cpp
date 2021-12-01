/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Argue
 * ALGO		: Depth First Search
 * DATE		: 29 Nov 2021
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
const ll MOD = 1e9 + 7;
vector<int> adj[MxN];
bool visited[MxN];
int deg[MxN];

pair<ll, ll> dfs(int u, int p){
	visited[u] = true;
	pair<int, int> cur = {1, deg[u]};
	for(auto x: adj[u]){
		if(x == p || visited[x]){
			continue;
		}
		auto xx = dfs(x, u);
		cur.first += xx.first;
		cur.second += xx.second;
	}	
	return cur;
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	ll ans = 1;
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			auto cur = dfs(i, 0);
			if(cur.first == cur.second / 2){
				ans *= 2;
			}
			else if(cur.first - (cur.second / 2) == 1){
				ans *= cur.first;
			}
			else{
				ans = 0;
			}
			ans %= MOD;
			dbg(cur.first, cur.second / 2);
		}
	}
	cout << ans;
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
