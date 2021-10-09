/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Kong
 * ALGO		: Topological Sort
 * DATE		: 9 Oct 2021
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

const int MxN = 100100;
vector<int> adj[MxN];
int in[MxN];
bool visited[MxN];

void solve(){
	int n, m, u, v;
	cin >> n >> m;
	memset(in, 0, sizeof in);
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
		in[u]++, in[v]++;
	}
	memset(visited, false, sizeof visited);
	queue<int> q;
	for(int i=1; i<=n; ++i){
		if(in[i] == 1){
			visited[i] = true;
			q.push(i);
		}
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto x: adj[now]){
			if(!visited[x] && --in[x] == 1){
				visited[x] = true;
				q.push(x);
			}
		}
	}
	memset(visited, false, sizeof visited);
	for(int i=1; i<=n; ++i){
		if(in[i] > 1){
			 q.push(i);
			 visited[i] = true;
		 }
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto x: adj[now]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
			}
		}
	}
	set<pair<int, int>> st;
	for(int i=1; i<=n; ++i){
		for(auto x: adj[i]){
			dbg(i, adj[i].size());
			if(!visited[i] && adj[i].size() == 1){
				st.emplace(min(i, x), max(i, x));
			}
			if(visited[i] && in[i] > 1 && in[x] == 1){
				st.emplace(min(i, x), max(i, x));
			}
		}
	}
	cout << st.size() << "\n";
	for(auto x: st){
		cout << x.first << " " << x.second << "\n";
	}
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
