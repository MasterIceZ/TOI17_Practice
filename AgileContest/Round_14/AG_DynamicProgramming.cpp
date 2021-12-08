/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Dynamic Programming
 * ALGO		: Dijkstra
 * DATE		: 6 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Node{
	int v; 
	ll w;
	int state;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

priority_queue<Node> pq;
vector<pair<int, ll>> adj[100100];
ll dist[3][100100];

void solve(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	ll w;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	for(int i=1; i<=n; ++i){
		dist[0][i] = dist[1][i] = 1e18;
	}
	dist[0][s] = 0;
	pq.push({s, 0, 0});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(dist[now.state][now.v] != now.w){
			continue;
		}
		if(now.state == 1 && now.v == t){
			cout << now.w;
			return ;
		}
		dbg(now.v, now.w, now.state);
		for(auto x: adj[now.v]){
			ll nxt = now.w + x.second;
			if(now.state == 0){
				if(dist[0][x.first] == 1e18){
					pq.push({x.first, nxt, 0});
					dist[0][x.first] = nxt;
				}
				else if(dist[0][x.first] > nxt){
					pq.push({x.first, dist[0][x.first], 1});
					pq.push({x.first, nxt, 0});
					dist[1][x.first] = dist[0][x.first];
					dist[0][x.first] = nxt;
				}
				else if(dist[1][x.first] > nxt){
					pq.push({x.first, nxt, 1});
					dist[1][x.first] = nxt;
				}
			}
			else{
				if(dist[1][x.first] > nxt){
					pq.push({x.first, nxt, 1});
					dist[1][x.first] = nxt;
				}
			}	
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
