#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

vector<int> adj[100100];
int color[100100];

bool dfs(int u, int c){
	if(color[u]){
		return (color[u] == c);
	}
	color[u] = c;
	for(auto x: adj[u]){
		if(!dfs(x, 3 - c)){
			return false;
		}
	}
	return true;
}

void solve(){
	memset(color, 0, sizeof color);
	for(int i=0; i<=100000; ++i){
		adj[i].clear();
	}
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n; ++i){
		if(color[i]){
			continue;
		}
		if(!dfs(i, 1)){
			cout << "Gay found!";
			return ;
		}
	}
	cout << "Gay not found!";
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
