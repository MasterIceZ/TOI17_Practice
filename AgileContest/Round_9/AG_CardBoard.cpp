/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_CardBoard
 * ALGO		: Miniumum Spanning Tree
 * DATE		: 18 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const{
		return w > o.w;
	}
};

const int MxN = 1010;
int red[MxN], green[MxN], p[MxN];

int fr(int u){
	return u == p[u] ? u: p[u] = fr(p[u]);
}

priority_queue<Edge> edges;

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> red[i];
		p[i] = i;
	}
	for(int i=1; i<=n; ++i){
		cin >> green[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			int cur1 = red[i] ^ green[j];
			int cur2 = green[i] ^ red[j];
			edges.push({i, j, min(cur1, cur2)});
			dbg(cur1, cur2);
		}
	}
	int sum = 0;
	while(!edges.empty()){
		Edge now = edges.top();
		edges.pop();
		int ru = fr(now.u), rv = fr(now.v);
		if(ru == rv){
			continue;
		}
		sum += now.w;
		p[ru] = rv;
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
		cout << "\n";
	}
	return 0;
}
