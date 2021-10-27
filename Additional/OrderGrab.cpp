#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v;
	ll w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<pair<int, ll>> adj[30150];
bool rest[30150];
ll dist[30150];

ll dijkstra(int st, int ed){
	priority_queue<Node> pq;
	pq.push({st, 0});
	memset(dist, 0x3f, sizeof dist);
	dist[st] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.v == ed){
			return now.w;
		}
		for(auto x: adj[now.v]){
			ll nxt = now.w + x.second;
			if(dist[x.first] > nxt){
				dist[x.first] = nxt;
				pq.push({x.first, nxt});
			}
		}
	}
	return dist[ed];
}

void solve(){
	int st, re, ed;
	cin >> st >> re >> ed;
	cout << dijkstra(st, re) + dijkstra(re, ed);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, k, q = 1;
	cin >> n >> m >> k >> q;
	for(int i=1; i<=m; ++i){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		rest[x] = true;
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
