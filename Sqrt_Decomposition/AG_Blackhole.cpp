/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Blackhole [P'Mark's Sol]
 * ALGO		: Square Root Decompostition
 * DATE		: 23 Nov 2021
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
vector<int> adj[MxN], timer, holes;
int sz[MxN][3], hole[MxN];
queue<int> qu;

void dfs(int u, int p){
	timer.push_back(u);
	sz[u][0] = timer.size() - 1;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
	}
	timer.push_back(u);
	sz[u][1] = timer.size() - 1;
}

void solve(){
	int n, q, u, v, o, x;
	cin >> n >> q;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	memset(hole, -1, sizeof hole);
	int sq = sqrt(q);
	for(int i=1; i<=q; ++i){
		cin >> o >> x;
		if(o == 0){
			if(hole[x] == -1){
				hole[x] = x;
			}
			holes.push_back(x);
		}
		else{
			for(auto xx:holes){
				if(hole[x] == -1){
					if(sz[xx][0] < sz[x][0] && sz[xx][1] > sz[x][1]){
						hole[x] = xx;
					}
				}
				if(sz[xx][0] < sz[hole[x]][0] && sz[xx][1] > sz[hole[x]][1]){
					hole[x] = xx;
				}
			}
			cout << hole[x] << "\n";
		}
		if(i % sq == 0){
			for(auto xx: timer){
				if(!qu.empty()){
					hole[xx] = qu.front();
				}
				if(!qu.empty() && xx == qu.front()){
					qu.pop();
				}
				else if(xx == hole[xx]){
					qu.push(xx);
				}
			}
			holes.clear();
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
