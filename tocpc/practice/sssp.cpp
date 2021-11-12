/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: SSSP
 * ALGO		: Dijkstra
 * DATE		: 10 Nov 2021
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
	int v;
	ll w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

const int MxN = 100100;
vector<pair<int, ll>> adj[MxN];
ll dist[MxN];

void solve(){
	int n, m, u, v;
	ll w;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	priority_queue<Node> pq;
	pq.push({1, 0});
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			ll nxt = now.w + x.second;
			if(dist[x.first] > nxt){
				pq.push({x.first, nxt});
				dist[x.first] = nxt;
			}
		}
	}
	for(int i=1; i<=n; ++i){
		cout << dist[i] << " ";
	}
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
