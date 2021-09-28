/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Shark
 * ALGO		: Dynamic Programming on Tree
 * DATE		: 28 Sep 2021
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

int a[1010], sum = 0, visited[1010];
vector<int> adj[1010];

void dfs(int u, int now){
	sum += a[u];
	visited[u] = now;
	for(auto x: adj[u]){
		if(visited[x] != now){
			dfs(x, now);
		}
	}
}

void solve(){
	int u, v, n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
	}
	int nax = -1e9, pos;
	for(int i=1; i<=n; ++i){
		sum = 0;
		dfs(i, i);
		if(sum > nax){
			nax = sum;
			pos = i;
		}
	}
	cout << pos << " " << nax;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
