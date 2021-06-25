/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi11_place
 * ALGO		: Minimum Spanning Tree
 * DATE		: 25 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

#define int long long

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const{
		return w < o.w;
	}
};

int parent[200200];

int root(int u){
	if(parent[u] == u){
		return u;
	}
	return parent[u] = root(parent[u]);
}

void solve(){
	for(int i=0; i<=200000; ++i){
		parent[i] = i;
	}
	int n, m;
	cin >> n >> m;
	priority_queue<Edge> pq;
	for(int i=1; i<=m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		pq.push({u, v, w});
	}
	int ans = 0;
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		int ru = root(now.u), rv = root(now.v);
		if(ru == rv){
			continue;
		}
		parent[ru] = rv;
		ans += now.w - 1;
	}
	cout << ans;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
