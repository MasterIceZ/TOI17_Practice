/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_weakpoint
 * ALGO		: Topological Sort
 * DATE		: 4 Oct 2021
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

const int MxN = 500500;
int in[MxN], dp[MxN];
bool cycle[MxN], visited[MxN], mark[MxN];
vector<int> adj[MxN];

void solve(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		in[u]++, in[v]++;
		cycle[i] = true;
	}
	queue<int> topo;
	for(int i=1; i<=n; ++i){
		if(in[i] == 1){
			topo.push(i);
			mark[i] = true;
		}
	}
	while(!topo.empty()){
		int now = topo.front();
		topo.pop();
		cycle[now] = false;
		for(auto x: adj[now]){
			if(mark[x]){
				continue;
			}
			dbg(x, in[x]);
			if(--in[x] == 1){
				mark[x] = true;
				topo.push(x);
			}
			dp[x] += dp[now] + 1;
		}
	}
	dbg(cycle[m] ? "true" : "false");
	if(cycle[m]){
		int nax = -1, idx = 0;
		for(int i=1; i<=n; ++i){
			if(dp[i] > nax && i != m){
				nax = dp[i];
				idx = i;
			}
			dbg(i, dp[i]);
		}
		cout << idx << "\n" << nax;
	}
	else{
		queue<int> q;
		visited[m] = true;
		int nax = -1, idx = 0;
		for(auto a: adj[m]){
			q.push(a);
			int sum = -1;
			visited[a] = true;
			while(!q.empty()){
				int now = q.front();
				q.pop();
				sum += 1;
				for(auto x: adj[now]){
					if(visited[x] || x == m){
						continue;
					}
					q.push(x);
					visited[x] = true;
				}
			}
			dbg(a);
			if(sum > nax){
				nax = sum;
				idx = a;
			}
			if(sum == nax){
				idx = min(idx, a);
			}
		}
		cout << idx << "\n" << nax;
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
