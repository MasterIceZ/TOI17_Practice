/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Budget
 * ALGO		: Minimum Spanning Tree
 * DATE		: 3 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const{
		return w > o.w;
	}
};

int parent[3333];

int root(int u){
	if(parent[u] == u){
		return u;
	}
	return parent[u] = root(parent[u]);
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<=3000; ++i){
		parent[i] = i;
	}
	priority_queue<Edge> pq;
	for(int i=1; i<=m; ++i){
		int u, v, w, s;
		cin >> u >> v >> w >> s;
		if(s == 1){
			w = 0;
		}
		pq.push({u, v, w});
	}
	int x;
	cin >> x;
	vector<pair<int, int>> cost;
	for(int i=1, a, b; i<=x; ++i){
		cin >> a >> b;
		cost.emplace_back(a, b);
	}
	cost.emplace_back(0, 0);
	sort(all(cost));
	for(int i = x - 1; i >= 0; --i){
		cost[i].second = min(cost[i].second, cost[i + 1].second);
	}
	int ans = 0;
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		int ru = root(now.u), rv = root(now.v);
		if(ru != rv){
			parent[ru] = rv;
			ans += cost[lower_bound(all(cost), make_pair(now.w, INT_MIN)) - cost.begin()].second;
		}
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
