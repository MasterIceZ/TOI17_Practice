/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: THACO_SuperBridge
 * ALGO		: Minimum Spanning Tree
 * DATE		: 11 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Edge{
	int u, v;
	ll w;
	int idx;
	bool operator < (const Edge& o) const{
		return w > o.w;
	}
};

struct Edge2{
	int u, v;
	ll w;
	int type;
	bool operator < (const Edge& o) const{
		return w > o.w;
	}
}

int p[100100];

int fr(int u){
	if(p[u] == u){
		return u;
	}
	return p[u] = fr(p[u]);
}

void solve(){
	int n, m, k, u, v;
	ll w;
	cin >> n >> m >> k;
	priority_queue<Edge> pq;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		pq.push({u, v, w, i});
	}
	for(int i=1; i<=n; ++i){
		p[i] = i;
	}
	vector<Edge2> uses;
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		int ru = fr(now.u), rv = fr(now.v);
		if(ru == rv){
			continue;
		}
		uses.push_back({now.u, now.v, now.w, now.idx});
		p[ru] = rv;
	}
	for(int i=1; i<=n; ++i){
		cin >> u >> v;

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
