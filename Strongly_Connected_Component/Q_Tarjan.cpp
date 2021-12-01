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

vector<int> adj[100100];
int idx[100100], low[100100], comp[100100];
bool onstack[100100];
int id, cnt;
stack<int> st;

void dfs(int u){
	idx[u] = low[u] = ++id;
	onstack[u] = true;
	st.push(u);
	for(auto x: adj[u]){
		if(!idx[x]){
			dfs(x);
			low[u] = min(low[u], low[x]);
		}
		else if(onstack[x]){
			low[u] = min(low[u], idx[x]);
		}
	}
	if(idx[u] != low[u]){
		return ;
	}
	++cnt;
	while(!st.empty() && st.top() != u){
		onstack[st.top()] = false;
		comp[st.top()] = cnt;
		st.pop();
	}
	onstack[u] = false;
	comp[u] = cnt;
	st.pop();
}

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1, o, x; i<=n; ++i){
		cin >> o;
		while(o--){
			cin >> x;
			adj[i].push_back(x);
		}
	}
	for(int i=1; i<=n; ++i){
		if(!idx[i]){
			dfs(i);
		}
	}
	while(q--){
		int u, v;
		cin >> u >> v;
		cout << (comp[u] == comp[v] ? "yes\n": "no\n");
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
