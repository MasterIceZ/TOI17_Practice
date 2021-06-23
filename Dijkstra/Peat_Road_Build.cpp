/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Peat Road Build
 * ALGO		: Dijkstra
 * DATE		: 23 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v, w, cnt;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

struct Edge{
	int v, w, idx;
};

vector<Edge> adj[1010];
int mid, n, m, mkr, dist[1010][3];

bool generate(bool state){
	memset(dist, 0x3f, sizeof dist);
	dist[1][1] = 0;
	priority_queue<Node> pq;
	pq.push({1, 0, 1});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			if(x.idx > mid){
				continue;
			}
			if(dist[x.v][(1 + now.cnt) % 2] > now.w + x.w){
				dist[x.v][(1 + now.cnt) % 2] = now.w + x.w;
				pq.push({x.v, dist[x.v][(1 + now.cnt) % 2], (1 + now.cnt) % 2});
			}
		}
	}
	if(state){
		return mkr = dist[n][0];
	}
	else{
		return dist[n][0] == mkr;
	}
}

void solve(){
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w, i});
		adj[v].push_back({u, w, i});
	}
	mid = m;
	generate(true);
	int l = 1, r = m;
	while(l < r){
		mid = (l + r) / 2;
		if(generate(false)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l << " " << mkr;
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
