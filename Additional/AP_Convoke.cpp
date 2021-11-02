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

struct Node{
	int v;
	ll w;
	int bit;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

ll dist[222][1 << 17];
vector<pair<int, ll>> adj[222];
ll floyd[222][222];
int go[222];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> ks;
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		go[x] = i;
		ks.push_back(x);
	}
	memset(floyd, 0x3f, sizeof floyd);
	for(int i=1; i<=n; ++i){
		floyd[i][i] = 0;
	}
	for(int i=1; i<=m; ++i){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		floyd[u][v] = floyd[v][u] = min(w, floyd[v][u]);
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				floyd[i][j] = min(floyd[i][k] + floyd[k][j], floyd[i][j]);
			}
		}
	}
	for(auto x: ks){
		adj[1].emplace_back(x, floyd[1][x]);
		adj[x].emplace_back(1, floyd[1][x]);
		adj[n].emplace_back(x, floyd[x][n]);
		adj[x].emplace_back(n, floyd[x][n]);
	}
	for(int i=0; i<ks.size(); ++i){
		for(int j=i+1; j<ks.size(); ++j){
			int u = ks[i], v = ks[j];
			adj[u].emplace_back(v, floyd[u][v]);
			adj[v].emplace_back(u, floyd[v][u]);
		}
	}
	memset(dist, 0x3f, sizeof dist);
	priority_queue<Node> pq;
	pq.push({1, 0, 0});
	dist[1][0] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.v == n && (1 << (1 + k)) - 2 == now.bit){
			cout << now.w;
			return ;
		}
		for(auto x: adj[now.v]){
			ll nxt = x.second + now.w;
			int nxt_bit = now.bit;
			if(go[x.first]){
				nxt_bit |= (1 << go[x.first]);
			}
			if(dist[x.first][nxt_bit] > nxt){
				dist[x.first][nxt_bit] = nxt;
				pq.push({x.first, nxt, nxt_bit});
			}
		}
	}
	cout << dist[n][(1 << (1 + k)) - 2];
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
