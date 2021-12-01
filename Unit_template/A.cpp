/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#define warn(...) 0
#endif

using ll = long long;

const int MxN = 10010;
vector<int> adj[MxN];
int deg[MxN];
bool visited[MxN];

pair<int, int> dfs(int u, int p){
	visited[u] = true;
	pair<int, int> sum = {0, 0};
	for(auto x: adj[u]){
		if(x == p || visited[x]){
			continue;
		}
		auto cur = dfs(x, u);
		sum.first += cur.first;
		sum.second += cur.second;
	}
	return {sum.first + 1, sum.second + deg[u]};
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
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			auto x = dfs(i, 0);
			dbg(x.first, x.second / 2);
		}
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
