/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Food Tour
 * ALGO		: Dynamic Programming On Tree
 * DATE		: 24 Aug 2021
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

const int MxN = 40400;
const ll INF = 1e18;

struct Town{
	ll toHotel, toRes[555];
};

Town dp[MxN];

ll food[555];
int m, parent[MxN], comp[MxN];
bool menu[MxN], hotel[MxN];

vector<pair<int, ll>> adj[MxN];

int fr(int u){
	return u == parent[u] ? u : parent[u] = fr(parent[u]);
}

void dfs(int u, int p){
	dbg(u);
	dp[u].toHotel = -INF;
	for(int i=1; i<=m; ++i){
		dp[u].toRes[i] = -INF;
	}
	if(menu[u]){
		dp[u].toRes[comp[fr(u)]] = 0;
	}
	if(hotel[u]){
		dp[u].toHotel = 0;
	}
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		dfs(x.first, u);
		for(int i=1; i<=m; ++i){
			food[i] = max(food[i], dp[u].toHotel + dp[x.first].toRes[i] + x.second);
			food[i] = max(food[i], dp[u].toRes[i] + dp[x.first].toHotel + x.second);
			dp[u].toRes[i] = max(dp[u].toRes[i], dp[x.first].toRes[i] + x.second);
		}
		dp[u].toHotel = max(dp[u].toHotel, dp[x.first].toHotel + x.second);
	}
	return ;
}

void solve(){
	int n, r, k;
	cin >> n >> m >> r >> k;
	for(int i=1, u, v; i<n; ++i){
		ll w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	for(int i=1, u, v; i<=r; ++i){
		cin >> u >> v;
		parent[fr(u)] = fr(v);
		menu[u] = menu[v] = true;
	}
	int idx = 1;
	for(int i=1; i<=n; ++i){
		int ri = fr(i);
		if(menu[i] && !comp[ri]){
			comp[ri] = (idx++);
		}
	}
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		hotel[x] = true;
	}
	dfs(1, -1);
	ll ans = 0;
	for(int i=1; i<=m; ++i){
		ans += food[i];
	}
	cout << ans * 2;
	
	memset(food, 0, sizeof food);
	memset(comp, 0, sizeof comp);
	for(int i=0; i<=n; ++i){
		adj[i].clear();
	}
	memset(hotel, false, sizeof hotel);
	memset(menu, false, sizeof menu);
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
