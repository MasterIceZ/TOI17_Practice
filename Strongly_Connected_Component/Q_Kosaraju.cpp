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

vector<int> adj[100100], rev[100100];
bool visited[100100];
stack<int> st;
int comp[100100];

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
	for(auto x: rev[u]){
		if(x == p || visited[x]){
			continue;
		}
		dfs2(x, u, id);
	}
}

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1, v; i<=n; ++i){
		int o;
		cin >> o;
		while(o--){
			cin >> v;
			adj[i].push_back(v);
			rev[v].push_back(i);
		}
	}
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			dfs(i, 0);
		}
	}
	memset(visited, false, sizeof visited);
	int it = 0;
	while(!st.empty()){
		int now = st.top();
		st.pop();
		if(visited[now]){
			continue;
		}
		dfs2(now, 0, ++it);
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << (comp[x] == comp[y] ? "yes\n" : "no\n");
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
