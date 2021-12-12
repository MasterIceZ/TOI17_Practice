/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o61_oct_c1_patshort
 * ALGO		: Dijkstra
 * DATE		: 12 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v;
	ll w;
	bool operator < (const  Node& o) const{
		return w > o.w;
	}
};

struct Point{
	ll x, y;
};

int m;
ll dist[222];
Point p[222];
vector<pair<int, ll>> adj[222];
priority_queue<Node> pq;

ll calc(Point a, Point b){
	if(a.y == b.y){
		return abs(a.x - b.x);
	}
	if(a.y < b.y){
		swap(a.y, b.y);
	}
	ll dx = abs(a.x - b.x);
	ll dy = a.y - b.y;
	if(dx <= dy){
		return dy + ((dy + dx) % 2); 
	}
	return dx;
}

void solve(){
	cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
	adj[0].emplace_back(1, calc(p[0], p[1]));
	adj[1].emplace_back(0, calc(p[1], p[0]));
	for(int i=1; i<=m; ++i){
		adj[2 * i].emplace_back(0, calc(p[2 * i], p[0]));
		adj[2 * i].emplace_back(1, calc(p[2 * i], p[1]));
		adj[2 * i + 1].emplace_back(1, calc(p[2 * i + 1], p[1]));
		adj[2 * i + 1].emplace_back(0, calc(p[2 * i + 1], p[0]));
		adj[0].emplace_back(2 * i, calc(p[0], p[2 * i]));
		adj[0].emplace_back(2 * i + 1, calc(p[0], p[2 * i + 1]));
		adj[1].emplace_back(2 * i, calc(p[1], p[2 * i]));
		adj[1].emplace_back(2 * i + 1, calc(p[1], p[2 * i + 1]));
	}
	memset(dist, 0x3f, sizeof dist);
	pq.push({0, 0});
	dist[0] = 0;
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
	cout << dist[1];
	adj[0].clear(); adj[1].clear();
	for(int i=1; i<=m; ++i){
		adj[2 * i].pop_back(); adj[2 * i].pop_back();
		adj[2 * i + 1].pop_back(); adj[2 * i + 1].pop_back();
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> p[2 * i].x >> p[2 * i].y >> p[2 * i + 1].x >> p[2 * i + 1].y;
		adj[2 * i].emplace_back(2 * i + 1, 1);
		adj[2 * i + 1].emplace_back(2 * i, 1);
	}
	for(int i=1; i<=m; ++i){
		for(int j=1; j<=m; ++j){
			if(i == j){
				continue;
			}
			adj[2 * i].emplace_back(2 * j, calc(p[2 * i], p[2 * j]));
			adj[2 * i].emplace_back(2 * j + 1, calc(p[2 * i], p[2 * j + 1]));
			adj[2 * i + 1].emplace_back(2 * j, calc(p[2 * i + 1], p[2 * j]));
			adj[2 * i + 1].emplace_back(2 * j + 1, calc(p[2 * i + 1], p[2 * j + 1]));
		}
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
