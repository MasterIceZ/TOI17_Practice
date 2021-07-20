/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Durian Binary Tree
 * ALGO		: Dynamic Programming
 * DATE		: 18 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

vector<int> child[111];
vector<pair<int, int>> adj[111];
int dp[111][111], val[111];

void dfs(int u){
	for(auto x: adj[u]){
		if(val[x.first] != -1){
			continue ;
		}
		val[x.first] = x.second;
		child[u].push_back(x.first);
		dfs(x.first);
	}
}

int query(int u, int k){
	if(dp[u][k] != -1){
		return dp[u][k];
	}
	if(k == 0){
		return 0;
	}
	if(child[u].size() == 0){
		return val[u];
	}
	if(child[u].size() == 1){
		return dp[u][k] = query(child[u][0], k - 1) + val[u];
	}
	for(int i=0; i<=k - 1; ++i){
		dp[u][k] = max(dp[u][k], query(child[u][0], i) + query(child[u][1], k - i - 1) + val[u]);
	}
	return dp[u][k];
}

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=1, u, v, w; i<n; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	}
	val[1] = 0;
	dfs(1);
	cout << query(1, k+1);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		memset(dp, -1, sizeof dp);
		memset(val, -1, sizeof val);
		solve();
		cout << endl;
	}
	return 0;
}
