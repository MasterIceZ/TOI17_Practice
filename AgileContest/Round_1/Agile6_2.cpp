/*
 * AUTHOR	: Hydrolyzed~
 * TASK		:
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

vector<int> g[100100];
int parent[100100];
bool visited[100100];

void dfs(int u, int p){
	for(auto x: g[u]){
		if(x != p){
			dfs(x, u);
		}
	}
}

void solve(){
	cin >> n;
	for(int i=1, u, v; i<n; ++i){
		cin >> u >> v;
		g[u].push_back(v);
	}
	dfs(1, 1);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
