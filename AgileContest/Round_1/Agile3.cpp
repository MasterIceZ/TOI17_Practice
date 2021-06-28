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
	int v, w, s;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;
const int MxS = (1 << 8) + 3;

vector<Node> g[10010];
int dist[10010][MxS];

void solve(){
	int b, k;
	cin >> b >> k;
	int cannot = 0;
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		cannot |= 1 << (x - 1);
	}
	int ans = 1e9 + 2;
	for(int i=0; i<8; ++i){
		if((cannot & i) == 0){
			ans = min(ans, dist[b][i]);
		}
	}
	cout << (ans == 1e9 ? -1 : ans);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int a, q = 1;
//	memset(dist, 0x3f, sizeof dist);
	for(int i=0; i<=10000; ++i){
		for(int j=0; j<=MxS; ++j){
			dist[i][j] = 1e9;
		}
	}
	cin >> n >> m >> a >> q;
	for(int i=1; i<=m; ++i){
		int u, v, w, x;
		cin >> u >> v >> w >> x;
		int officer = 1 << (x-1);
		g[u].push_back({v, w, officer});
		g[v].push_back({u, w, officer});
	}
	priority_queue<Node> pq;
	pq.push({a, 0, 0});
	dist[a][0] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		int ns = now.s;
		for(auto x: g[now.v]){
			int nx = ns | x.s;
			if(dist[x.v][nx] > dist[now.v][ns] + x.w){
				dist[x.v][nx] = dist[now.v][ns] + x.w;
				pq.push({x.v, dist[x.v][nx], nx});
			}
		}
	}
	
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
