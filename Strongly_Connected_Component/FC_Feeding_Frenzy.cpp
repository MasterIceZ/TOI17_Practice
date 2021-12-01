/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: FC_Feeding Frenzy
 * ALGO		: Strongly Connected Component
 * DATE		: 1 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int sum[5050], comp[5050], hei[5050];
vector<int> adj[5050];

struct SCC{
	vector<int> adj[5050], rev[5050];
	stack<int> st;
	bitset<5050> visited;
	void add(int u, int v){
		adj[u].push_back(v);
		rev[v].push_back(u);
	}
	void dfs(int u, int p){
		visited[u] = true;
		for(auto x: adj[u]){
			if(x == p || visited[x]){
				continue;
			}
			dfs(x, u);
		}
		st.push(u);
	}
	void dfs2(int u, int p, int id){
		visited[u] = true;
		comp[u] = id;
		dbg(u, id);
		for(auto x: rev[u]){
			if(x == p || visited[x]){
				continue;
			}
			dfs2(x, u, id);
		}
	}
	void compute(int n){
		for(int i=0; i<n; ++i){
			if(!visited[i]){
				dfs(i, 0);
			}
		}
		visited = 0;
		int it = 0;
		while(!st.empty()){
			int now = st.top();
			st.pop();
			if(visited[now]){
				continue;
			}
			dfs2(now, 0, ++it);
		}
	}
} scc;

void dfs(int u, int level){
	hei[u] = level;
	dbg(u, level);
	for(auto x: adj[u]){
		if(hei[x] > level){
			continue;
		}
		dfs(x, level + 1);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		scc.add(u, v);
	}
	scc.compute(n);
	for(int i=0; i<n; ++i){
		for(auto x: scc.adj[i]){
			if(comp[i] == comp[x]){
				continue;
			}
			adj[comp[i]].push_back(comp[x]);
			dbg(i, x);
		}
	}
	for(int i=0; i<n; ++i){
		if(hei[comp[i]]){
			continue;
		}
		dfs(comp[i], 1);
	}
	int mx = 0;
	for(int i=0; i<n; ++i){
		dbg(i);
		sum[hei[comp[i]]]++;
		mx = max(hei[comp[i]], mx);
	}
	for(int i=1; i<=mx; ++i){
		cout << sum[i] << " ";
	}
	cout << "\n" << hei[comp[0]] ;
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
