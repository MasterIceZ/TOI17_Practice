/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Blackhole
 * ALGO		: Depth First Search
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

const int MxN = 100100;

vector<int> adj[MxN];
int hei[MxN], mem[MxN], val[MxN], p[MxN];
queue<int> q;

int fr(int u){
	return u == p[u] ? u: p[u] = fr(p[u]);
}

void bfs(){
	q.push(1);
	hei[1] = 1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto x: adj[now]){
			if(hei[x] != 0){
				continue;
			}
			hei[x] = hei[now] + 1;
			q.push(x);
		}
	}
}

void bfs2(int u){
	int ru = fr(u);
	if(ru != u){
		return ;
	}
	mem[u] = u;
	q.push(u);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto x: adj[now]){
			int fx = fr(x);
			if(hei[x] < hei[now] || fx != x){
				continue;
			}
			p[fx] = u;
			q.push(x);
		}
	}
}

void solve(){
	int n, q, u, v;
	cin >> n >> q;
	p[1] = 1;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		p[i] = i;
	}
	bfs();
	memcpy(val, hei, sizeof val);
	while(q--){
		int o, x;
		cin >> o >> x;
		if(o == 0){
			bfs2(x);
		}
		else{
			cout << (mem[fr(x)] == 0 ? -1: mem[fr(x)]) << "\n";	
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
		cout << "\n";
	}
	return 0;
}
