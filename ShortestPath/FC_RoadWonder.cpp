/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: FC_Road Wonder
 * ALGO		: Bellman Ford
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

struct Edge{
	int u, v, w;
};

vector<Edge> edge;
int n, dist[1111], dist2[1111];

void solve(){
	int s;
	cin >> s;
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	for(int i=0; i<n-1; ++i){
		for(auto x: edge){
			dist[x.v] = min(dist[x.v], dist[x.u] + x.w);
		}
	}
	memcpy(dist2, dist, sizeof dist);
	for(auto x: edge){
		dist2[x.v] = min(dist2[x.v], dist2[x.u] + x.w);
	}
	for(int i=1; i<=n; ++i){
		if(dist[i] != dist2[i] || dist[i] >= 1e9){
			cout << -1;
		}
		else{
			cout << dist[i];
		}
		cout << " ";
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int m, k, q, u, v, w;
	cin >> n >> m >> k >> q;
	for(int i=0; i<m; ++i){
		cin >> u >> v >> w;
		edge.push_back({u, v, w});
	}
	for(int i=0; i<k; ++i){
		cin >> u >> v >> w;
		edge.push_back({u, v, -w});
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
