/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Supernova
 * ALGO		: Topological Sort
 * DATE		: 20 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;
const int MxN = 100010;

vector<pair<int, int>> adj[MxN];
pair<int, int> edge[MxN];
int subtree[MxN];
ll ans[MxN];

void dfs(int u, int p, int idx){
	subtree[u] = 1;
	for(auto x: adj[u]){
		if(x.first != p && deg[x.first] == 0){
			dfs(x.first, u, x.second);
			subtree[u] += subtree[x.first];
		}
	}
	ans = (ll)(n - subtree[u]) * subtree[u];
}

void solve(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
		edge[i] = make_pair(u, v);
		deg[u]++, deg[v]++;
	}
	queue<int> pq;
	for(int i=1; i<=n; ++i){
		if(deg[u] == 1){
			pq.push(i);
		}
	}
	while(!pq.empty()){
		int now = pq.front();
		pq.pop();
		for(auto x: adj[now]){
			if(deg[x.first]){
				deg[u] -= 1;
				if(deg[u] - 1 == 1){
					deg[u] -= 1;
					q.push(x.first);
				}
			}
		}
	}
	for(int i=1; i<=n; ++i){
		if(deg[i] == 2){
			dfs(u, 0, 0);
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
