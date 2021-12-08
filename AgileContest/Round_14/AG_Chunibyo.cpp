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
#endif

using ll = long long;

const int MxN = 300300;
char o;
vector<int> adj[MxN], rev[MxN], adj2[MxN];
bitset<MxN> visited, ok, ok2;
stack<int> st;
int comp[MxN], level[MxN], max_current, n;

void scc_dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(x == p || visited[x]){
			continue;
		}
		scc_dfs(x, u);
	}
	st.push(u);
}

void scc_dfs2(int u, int p, int id){
	comp[u] = id;
	visited[u] = true;
	for(auto x: rev[u]){
		if(x == p || visited[x]){
			continue;
		}
		scc_dfs2(x, u, id);
	}
}

void dfs(int u, int lvl){
	level[u] = lvl;
	visited[u] = true;
	for(auto x: adj2[u]){
		dfs(x, lvl + 1);
	}
}

void solve(){
	int m, _;
	scanf("%d %d %d", &n, &m, &_);
	for(int i=1, u, v; i<=_; ++i){
		scanf("%d%c%d", &u, &o, &v);
		if(o == '>' || o == '='){
			adj[u].push_back(v);
			rev[v].push_back(u);
		}
		if(o == '<' || o == '='){
			rev[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	for(int i=1; i<=m; ++i){
		if(!visited[i]){
			scc_dfs(i, 0);
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
		scc_dfs2(now, 0, ++it);
	}
//	dbg(to_vector(comp, 1, m));
	for(int i=1; i<=m; ++i){
		for(auto x: adj[i]){
			if(comp[x] == comp[i]){
				continue;
			}
			adj2[comp[i]].push_back(comp[x]);
		}
	}
	visited = 0;
	for(int i=1; i<=m; ++i){
		if(visited[comp[i]]){
			continue;
		}
		dfs(comp[i], 1);
	}
//	for(int i=1; i<=m; ++i){
//		cerr << (n + 1 -level[comp[i]]) << "\n";
//	}
	for(int i=1; i<=m; ++i){
		if(level[comp[i]] == 1 && adj2[comp[i]].size() == 0){
			printf("?");
		}
		else{
			printf("K%d", n + 1 - level[comp[i]]);
		}
		printf("\n");
	}
	return ;
}

int main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();	
	//		cout << "\n";
	}
	return 0;
}
