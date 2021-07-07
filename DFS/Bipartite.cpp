/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Bipartite Graph Check
 * ALGO		: Depth First Search
 * DATE		: 6 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int color[100010];
vector<int> adj[100010];

bool dfs(int u, int c){
	if(color[u] != 0 && color[u] == c){
		return true;
	}
	if(color[u] != 0 && color[u] != c){
		return false;
	}
	color[u] = c;
	for(auto x: adj[u]){
		if(!dfs(x, 3-c)){
			return false;
		}
	}
	return true;
}

void solve(){
	int u, v, n, m;
	cin >> n >> m;
	while(m--){
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	cout << (dfs(1, 1) ? "yes" : "no");
	memset(color, 0, sizeof color);
	for(int i=0; i<=n; ++i){
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
		cout << endl;
	}
	return 0;
}
