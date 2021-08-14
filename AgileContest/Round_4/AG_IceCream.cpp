/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Ice Cream
 * ALGO		: Dijkstra
 * DATE		: 14 Aug 2021
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

struct Node{
	int v, w, amt, last;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<pair<int, int>> adj[80800];
int dist[10][80800];

void solve(){
	int n, m, p, q, u, v, w;
	cin >> n >> m >> p >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	set<int> sp;
	for(int i=1, a; i<=p; ++i){
		cin >> a;
		sp.insert(a);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[0][1] = 0;
	priority_queue<Node> pq;
	pq.push({1, 0, 0, -1});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			int next = x.first, dis = x.second / (1 << now.amt);
			if(now.last != next && now.amt + 1 <= q && sp.count(next) && dist[now.amt + 1][next] > now.w + dis){
				dist[now.amt + 1][next] = now.w + dis;
				pq.push({next, dist[now.amt + 1][next], now.amt + 1, next});
			}
			if(dist[now.amt][next] > now.w + dis){
				dist[now.amt][next] = now.w + dis;
				pq.push({next, dist[now.amt][next], now.amt, now.last});
			}
		}
	}
	int ans = 1e9 + 10;
	for(int i=0; i<=q; ++i){
		dbg(dist[i][n]);
		ans = min(ans, dist[i][n]);
	}
	cout << ans;
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
