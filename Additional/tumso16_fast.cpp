#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 10010;
int visited[MxN], deg[MxN];
vector<int> adj[MxN];

void solve(){
	int n, k, u, v;
	cin >> n >> k;
	vector<pair<int, int>> edges;
	for(int i=1; i<=k; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		deg[u]++, deg[v]++;
		edges.emplace_back(u, v);
	}
	queue<int> q;
	for(int i=1; i<=n; ++i){
		if(deg[i] == 1){
			q.push(i);
		}
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		visited[now] = true;
		for(auto x: adj[now]){
			if(visited[x]){
				continue ;
			}
			if(--deg[x] == 1){
				q.push(x);
				visited[x] = true;
			}
		}
	}
	bool ok = true;
	for(auto x: edges){
		int a = x.first;
		int b = x.second;
		if((visited[a] ^ visited[b]) == 1){
			cout << a << " " << b << "\n";
			ok = false;
		}
	}
	if(ok){
		cout << "OK!" << "\n";
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
