/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Groovy
 * ALGO		:
 * DATE		:
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
	int u, v;
	ll w;
	bool operator < (const Edge& o) const{
		return w > o.w;
	}
};

int parent[100100];

int fr(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = fr(parent[u]);
}

void solve(){
	int n, m, k, u, v;
	cin >> n >> m >> k;
	ll w;
	priority_queue<Edge> edge;
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		edge.push({u, v, w});
	}
	priority_queue<ll> uses;
	ll sum = 0;
	while(!edge.empty()){
		Edge now = edge.top();
		edge.pop();
		int ru = fr(now.u), rv = fr(now.v);
		if(ru == rv){
			continue;
		}
		parent[ru] = rv;
		sum += now.w;
		uses.push(now.w);
	}
	for(int i=1; i<=k; ++i){
		sum -= uses.top();
		uses.pop();
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
