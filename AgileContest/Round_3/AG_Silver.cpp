#include<bits/stdc++.h>
using namespace std;

vector<int> adj[300300];
int ans, dp[300300][3], p[300300], mx[300300];
bool visited[300300];

int fr(int u){
	return p[u] == u ? u : p[u] = fr(p[u]);
}

void merge(int u, int v){
	int ru = fr(u), rv = fr(v);
	if(ru == rv){
		return ;
	}
	p[rv] = ru;
}

void dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		merge(u, x);
		if(dp[x][0] + 1 > dp[u][0]){
			dp[u][1] = dp[u][0];
			dp[u][0] = dp[x][0] + 1;
		}
		else if(dp[x][0] + 1 > dp[u][1]){
			dp[u][1] = dp[x][0] + 1;
		}
	}
	ans = max(ans, dp[u][0] + dp[u][1]);
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		p[i] = i;
	}
	while(m--){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			ans = 0;
			dfs(i, 0);
			mx[i] = ans;
		}
	}
	while(q--){
		int opr, x, y;
		cin >> opr;
		if(opr == 1){
			cin >> x;
			cout << mx[fr(x)] << "\n";
		}
		else{
			cin >> x >> y;
			int px = fr(x), py = fr(y);
			if(px == py){
				continue;
			}
			mx[px] = max({(mx[px] + 1) / 2 + (mx[py] + 1) / 2 + 1, mx[px], mx[py]});
			merge(px, py);
		}
	}
	return 0;
}
