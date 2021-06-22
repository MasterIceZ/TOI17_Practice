/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Logistic TOI14
 * ALGO		: Dijkstra
 * DATE		: 21 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v, w, fuel, s;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<pair<int, int>> adj[111];
int fuel[111];
int dist[111][111][3];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> fuel[i];
	}
	int s, e, c;
	cin >> s >> e >> c ;
	int m;
	cin >> m;
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	priority_queue<Node> pq;
	pq.push({s, 0, 0, 0});
	dist[s][0][0] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.fuel + 1 <= c && dist[now.fuel + 1][now.v][now.s] > now.w + fuel[now.v]){
			dist[now.fuel + 1][now.v][now.s] = now.w + fuel[now.v];
			pq.push({now.v, dist[now.fuel + 1][now.v][now.s], now.fuel + 1, now.s});
		}
		if(now.s == 0 && dist[c][now.v][1] > now.w){
			dist[c][now.v][1] = now.w;
			pq.push({now.v, now.w, c, 1});
		}
		for(auto x: adj[now.v]){
			if(now.fuel - x.second >= 0 && dist[now.fuel - x.second][x.first][now.s] > now.w){
				dist[now.fuel - x.second][x.first][now.s] = now.w;
				pq.push({x.first, now.w, now.fuel - x.second, now.s});
			}
		}
	}
	cout << dist[c][e][1];
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
