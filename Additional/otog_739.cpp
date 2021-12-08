#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

vector<int> adj[100100], adj2[100100];
int comp[100100], hei[100100];
bitset<100100> visited;

struct Scc{
	vector<int> rev[100100];
	stack<int> st;
	void dfs(int u, int p){
		visited[u] = true;
		for(auto x: adj[u]){
			if(x == p || visited[x]){
				continue;
			}
			dfs(x, u);
		}
		st.push(u);
	}
	void dfs2(int u, int p, int id){
		comp[u] = id;
		visited[u] = true;
		for(auto x: rev[u]){
			if(visited[x] || x == p){
				continue;
			}
			dfs2(x, p, id);
		}
	}
	void compute(int n){
		for(int i=1; i<=n; ++i){
			if(visited[i]){
				continue;
			}
			dfs(i, 0);
		}
		int id = 0;
		visited = 0;
		while(!st.empty()){
			int now = st.top();
			st.pop();
			if(visited[now]){
				continue;
			}
			dfs2(now, 0, ++id);
		}
	}
} scc;

void dfs(int u, int lvl){
	hei[u] = lvl;
	for(auto x: adj2[u]){
		if(hei[x] > lvl){
			continue;
		}
		dfs(x, lvl + 1);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i){
		char x;
		cin >> u >> v >> x;
		if(x == '<' || x == '='){
			adj[u].push_back(v);
			scc.rev[v].push_back(u);
		}
		if(x == '>' || x == '='){
			adj[v].push_back(u);
			scc.rev[u].push_back(v);
		}
	}
	scc.compute(n);
	for(int i=1; i<=n; ++i){
		for(auto x: adj[i]){
			if(comp[x] == comp[i]){
				continue;
			}
			adj2[comp[i]].push_back(comp[x]);
		}
	}
	for(int i=1; i<=n; ++i){
		if(hei[comp[i]]){
			continue;
		}
		dfs(comp[i], 1);
	}
	for(int i=1; i<=n; ++i){
		cout << hei[comp[i]] << "\n";
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
