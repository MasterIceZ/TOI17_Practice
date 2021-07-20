/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_TreeSubset
 * ALGO		: Dynamic Programming
 * DATE		: 18 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

bool visited[100100];
ll a[100100], dp[100100][3];
vector<ll> adj[100100];

void dfs(int u){
	visited[u] = true;
	dp[u][1] = a[u];
	for(auto x: adj[u]){
		if(visited[x]){
			continue ;
		}
		dfs(x);
		dp[u][0] += max(dp[x][1], dp[x][0]);
		dp[u][1] += dp[x][0];
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll u, v;
	for(int i=1; i<n; ++i){
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
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
		cout << endl;
		memset(dp, 0, sizeof dp), memset(visited, false, sizeof visited);
	}
	return 0;
}
