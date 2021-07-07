/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const{
		return w < o.w;
	}
};
int parent[50050];

int root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = root(parent[u]);
}

void solve(){
	int n, m;
	cin >> n >> m;
	unordered_map<int, int> mp;
	priority_queue<Edge> pq;
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		mp[x] = i;
	}
	int sum = 0;
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		pq.push({mp[u], mp[v], w});
		sum += w;
	}
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		int ru = root(now.u), rv = root(now.v);
		if(ru == rv){
			continue;
		}
		sum -= now.w;
		parent[ru] = rv;
	}
	cout << sum;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
