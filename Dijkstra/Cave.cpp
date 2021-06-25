/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Cave TOI15
 * ALGO		: Dijkstra
 * DATE		: 25 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v, w, t;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<pair<int, int>> adj[2020];
int dist[2020][2020], ed, n;

void solve(){
//	Print Ans
	int x, ans = dist[ed][0];
	cin >> x;
	for(int i=0; i<n; ++i){
		ans = min(ans, dist[ed][i] + (i * x));
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int p, st;
	cin >> n >> st >> ed >> p;
	while(p--){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
//	memset(dist, 0x3f, sizeof dist);
	for(int i=0; i<=2000; ++i){
		for(int j=0; j<=2000; ++j){
			dist[i][j] = 1e9 + 100;
//			dist[i][j] = 0x3f;
		}
	}
	priority_queue<Node> pq;
	dist[st][0] = 0;
	pq.push({st, 0, 0});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			// Case u or v is Start Point -> Not Increase Time!
			if(now.v == st){
				if(dist[x.first][now.t] > dist[now.v][now.t] + x.second){
					dist[x.first][now.t] = dist[now.v][now.t] + x.second;
					pq.push({x.first, dist[x.first][now.t], now.t});
				}
			}
			// Other Case
			else if(now.v != st && x.first != st){
				if(dist[x.first][now.t + 1] > dist[now.v][now.t] + x.second){
					dist[x.first][now.t + 1] = dist[now.v][now.t] + x.second;
					pq.push({x.first, dist[x.first][now.t + 1], now.t + 1});
				}
			}
		}
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
//		cout << endl;
		cout << " ";
	}
	return 0;
}
