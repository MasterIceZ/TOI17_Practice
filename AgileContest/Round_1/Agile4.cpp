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

struct Edge{
	int v, w, x;
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

int dist[10010][300];
vector<Edge> g[10010];

void solve(){
	
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int a, q;
	cin >> n >> m >> a >> q;
	for(int i=1; i<=m; ++i){
		int u, v, w, x;
		cin >> u >> v >> w >> x;
		g[u].push_back({v, w, x});
		g[v].push_back({u, w, x});
	}
	for(int i=1; I
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
