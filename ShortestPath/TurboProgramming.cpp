/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Turbo Programming
 * ALGO		: Dijkstra
 * DATE		: 9 Aug 2021
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
	int u, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<pair<int, int>> adj[100100];
int dist[100100];
bool visited[100100];

void solve(){
	int x;
	cin >> x;
	cout << dist[x];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q, u, v, w;
	cin >> n >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);	
	}
	memset(dist, -1, sizeof dist);
	priority_queue<Node> pq;
	pq.push({1, 0});
	dist[1] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(visited[now.u]){
			continue;
		}
		visited[now.u] = true;
		dist[now.u] = now.w;
		for(auto x: adj[now.u]){
			pq.push({x.first, now.w + x.second});
		}
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
