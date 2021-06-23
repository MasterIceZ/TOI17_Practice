/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int b[1010], peat[1010], dist[1010][1010];
vector<int> g[1010];

void solve(){
	int n, m, s, e, t, p;
	cin >> n >> m;
	cin >> s >> e >> t >> p;
	for(int i=1; i<=p; ++i){
		cin >> b[i];
	}
	memset(peat, 0x3f, sizeof dist);
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(v), g[v].push_back(u);
		dist[u][v] = dist[v][u] = w;
	}

	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
