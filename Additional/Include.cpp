#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

vector<int> adj[1010];
bitset<1010> visited;

int dfs(int u){
	if(visited[u]){
		return 1;
	}
	visited[u] = true;
	int bit = 0;
	for(auto x: adj[u]){
		bit |= dfs(x);
	}
	return bit;
}

void solve(){
	int n;
	cin >> n;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		for(int j=1, y; j<=x; ++j){
			cin >> y;
			adj[i].push_back(y);
		}
	}
	for(int i=1; i<=n; ++i){
		visited = 0;
		int res = dfs(i);
		cout << (res ? "YES": "NO") << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	while(q--){
		solve();
	}
	return 0;
}
