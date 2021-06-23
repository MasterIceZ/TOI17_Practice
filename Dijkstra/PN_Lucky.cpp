/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Lucky
 * ALGO		: Dijkstra
 * DATE		: 23 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v, w, state;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

int luck[50050], dist[50050][111];
vector<pair<int, int>> adj[50050];

void solve(){
	int n, m, l, s, t;
	cin >> n >> m >> l >> s >> t;
	for(int i=1; i<=n; ++i){
		cin >> luck[i];
	}
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	memset(dist, 0x3f, sizeof dist);
	priority_queue<Node> pq;
	pq.push({s, 0, 0});
	dist[s][0] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			if(now.state + 1 == luck[x.first] && dist[x.first][now.state + 1] > now.w + x.second){
				dist[x.first][now.state + 1] = now.w + x.second;
				pq.push({x.first, dist[x.first][now.state + 1], now.state + 1});
			}
			else if(dist[x.first][now.state] > now.w + x.second){
				dist[x.first][now.state] = now.w + x.second;
				pq.push({x.first, dist[x.first][now.state], now.state});
			}
		}
	}
	/*
	cerr << "Start Debug" << endl;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cerr << (dist[i][j] >= 1e9 ? -1 : dist[i][j]) << " " ;
		}
		cerr << endl;
	}
	cerr << "End Debug" << endl;
	*/
	cout << (dist[t][l] >= 1e9 ? -1 : dist[t][l]);
	for(int i=0; i<=50000; ++i){
		adj[i].clear();
	}
	memset(luck, 0, sizeof luck);
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
