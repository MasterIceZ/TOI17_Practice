#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

vector<int> adj[100100], rev[100100];
bitset<100100> closed, visited, visited2;

void dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(x == p || closed[x] || visited[x]){
			continue;
		}
		dfs(x, u);
	}
}

void dfs2(int u, int p){
	visited2[u] = true;
	for(auto x: rev[u]){
		if(x == p || closed[x] || visited2[x]){
			continue;
		}
		dfs2(x, u);
	}
}

void solve(){
	stack<pair<int, int>> offline;
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		rev[v].push_back(u);
	}
	while(q--){
		int t, x;
		cin >> t >> x;
		if(t == 1){
			closed[x] = true;
		}
		offline.emplace(t, x);
	}
	dfs(1, 0);
	dfs2(n, 0);
	stack<int> answer;
	while(!offline.empty()){
		pair<int, int> now = offline.top();
		offline.pop();
		if(now.first == 1){
			closed[now.second] = false;
//			dfs(now.second, 0);
//			dfs2(now.second, 0);
			for(auto x: rev[now.second]){
				if(!visited[x]){
					continue;
				}
				dfs(x, 0);
			}
			for(auto x: adj[now.second]){
				if(!visited2[x]){
					continue;
				}
				dfs2(x, 0);
			}
		}
		else{
			answer.push(visited[now.second ] && visited2[now.second]);
		}
	}
	while(!answer.empty()){
		cout << answer.top() << "\n";
		answer.pop();
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
