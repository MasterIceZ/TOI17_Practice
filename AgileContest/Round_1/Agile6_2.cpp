/*
 * AUTHOR	: Hydrolyzed~
 * TASK		:
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

vector<pii> g[100100];
int dp[100100];

void dfs(int u, int p){
	int sm = 0;
	for(auto x: g[u]){
		if(x.first != p){
			dfs(x.first, u);
			sm += dp[x.first] + x.second;
		}
	}
	dp[u] = sm;
	return ;
}

void dfs2(int u, int p){
	for(auto x: g[u]){
		if(x.first != p){
			dp[x.first] = dp[u];
			dp[x.first] -= (x.second == 1 ? 1 : -1);
			dfs2(x.first, u);
		}
	}
	return ;
}

void solve(){
	cin >> n;
	for(int i=1, u, v; i<n; ++i){
		cin >> u >> v;
		g[u].emplace_back(v, 0);
		g[v].emplace_back(u, 1);
	}
	dfs(1, 1);
	dfs2(1, 1);
	int cnt = 1e9 + 7, ans = n;
	for(int i=1; i<=n; ++i){
//		cout << "DBG : " << i << ", " << dp[i] << endl;
		if(cnt > dp[i]){
			ans = i;
			cnt = dp[i];
		}
	}
	cout << cnt << " " << ans;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
