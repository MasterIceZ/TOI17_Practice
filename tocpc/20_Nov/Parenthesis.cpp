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

const int MxN = 100100;
int type[MxN], dist[2][MxN];
vector<int> adj[MxN];

void bfs(int u, int state){
	memset(dist[state], -1, sizeof dist);
	queue<int> q;
	q.push(u);
	while(!q.empty()){

	}
}

void solve(){
	int n, s, t, u, v;
	cin >> n >> s >> t;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	string s;
	cin >> s;
	for(int i=0; i<s.size(); ++i){
		type[i + 1] = (s[i] == '(' ? 1: -1);
	}
	bfs(s, 0);
	bfs(t, 1);
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
