/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Cable Car TOI12
 * ALGO		: Minimum Spanning Tree
 * DATE		: 28 July 2021
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

int parent[2555];
int fr(int u){
	return u == parent[u] ? u : parent[u] = fr(parent[u]);
}

void solve(){
	int n, m, s, p, d;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	priority_queue<Edge> pq;
	for(int i=1; i<=m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		pq.push({u, v, w});
	}
	cin >> s >> d >> p;
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		int ru = fr(now.u), rv = fr(now.v);
		if(ru == rv){
			continue;
		}
		parent[ru] = rv;
		if(fr(s) == fr(d)){
			cout << fixed << setprecision(0) << ceil((double)p/(now.w - 1));
			return ;
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
		cout << endl;
	}
	return 0;
}
