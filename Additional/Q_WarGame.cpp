/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Q_War Game
 * ALGO		: Dijkstra
 * DATE		: 19 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v, w;
	bool used;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<pair<int, int>> adj[100100];
int dist[100100][3];
bool visited[100100][3];

void solve(){
	int n, m, s, t, u, v, w, qs = 0;
	cin >> n >> m >> s >> t;
	while(m--){
		cin >> u >> v >> w;
		qs += w;
		adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	priority_queue<Node> pq;
	pq.push({s, 0, false});
	dist[s][0] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(visited[now.v][now.used]){
			continue;
		}
		visited[now.v][now.used] = true;
		for(auto x: adj[now.v]){
			if(!now.used && dist[x.first][1] > dist[now.v][0] && !visited[x.first][1]){
				dist[x.first][1] = dist[now.v][0];
				pq.push({x.first, dist[x.first][1], 1});
			}
			if(dist[x.first][now.used] > x.second + dist[now.v][now.used] && !visited[x.first][now.used]){
				dist[x.first][now.used] = x.second + dist[now.v][now.used];
				pq.push({x.first, dist[x.first][now.used], now.used});
			}
		}
	}
	cout << qs - dist[t][1];
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
