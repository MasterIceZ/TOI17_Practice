/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Refuel
 * ALGO		: Dijkstra
 * DATE		: 21 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v, w, fuel;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<Node> adj[1111];
int dist[1111][111], a[1111];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	int c, s, e;
	cin >> c >> s >> e;
	priority_queue<Node> pq;
	memset(dist, 0x3f, sizeof dist);
	dist[s][0]  = 0;
	pq.push({s, 0, 0});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.v == e){
			break;
		}
		if(now.fuel < c && now.w + a[now.v] < dist[now.v][now.fuel + 1]){
			dist[now.v][now.fuel + 1] = a[now.v] + now.w;
			pq.push({now.v, dist[now.v][now.fuel + 1], now.fuel + 1});
		}
		for(auto x: adj[now.v]){
			if(now.fuel >= x.w && now.w < dist[x.v][now.fuel - x.w]){
				dist[x.v][now.fuel - x.w] = now.w;
				pq.push({x.v, now.w, now.fuel - x.w});
			}
		}
	}
	int ans = INT_MAX;
	for(int i=0; i<=c; ++i){
		ans = min(ans, dist[e][i]);
	}
	cout << (ans >= 1e9 ? -99 : ans);
	for(int i=0; i<n; ++i){
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
