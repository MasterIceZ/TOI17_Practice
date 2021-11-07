/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Insurnce
 * ALGO		: Disjoint Set Union
 * DATE		: 6 Nov 2021
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

const int MxN = 100100;

struct Edge{
	int u, v;
	ll w;
	bool operator < (const Edge& o) const{
		return w < o.w;
	}
};

ll qs[MxN], cnt[MxN][111];
int parent[MxN];

int fr(int u){
	return parent[u] == u ? u : parent[u] = fr(parent[u]);
}

void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		parent[i] = i;
		cnt[i][x] = 1;
	}
	vector<Edge> edges;
	for(int i=2; i<=n; ++i){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	sort(all(edges));
	vector<ll> v;
	int ptr = 1;
	for(auto x: edges){
		v.push_back(x.w);
		int u = fr(x.u), v = fr(x.v);
		ll All = 0;
		for(int i=1; i<=100; ++i){
			All += cnt[u][i];
		}
		ll res = 0;
		for(int i=1; i<=100; ++i){
			res += (All - cnt[u][i]) * cnt[v][i];
		}
		parent[v] = u;
		for(int i=1; i<=100; ++i){
			cnt[u][i] += cnt[v][i];
		}
		qs[ptr] = qs[ptr - 1] + res;
		++ptr;
	}
	dbg(v);
	while(q--){
		ll x;
		cin >> x;
		cout << 2 * qs[upper_bound(all(v), x) - v.begin()] << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
