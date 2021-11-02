#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v;
	ll w;
	int bit;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

int go[222];
ll dist[222][(1 << 15)], w, fw[222][222];
vector<pair<int, ll>> adj[222];
priority_queue<Node> pq;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> kk;
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		go[x] = i;
		kk.push_back(x);
	}
	memset(fw, 0x3f, sizeof fw);
	for(int i=1; i<=n; ++i){
		fw[i][i] = 0;
	}
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v >> w;
		fw[u][v] = fw[v][u] = min(fw[u][v], w);
	}
	for(int x=1; x<=n; ++x){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				fw[i][j] = min(fw[i][j], fw[i][x] + fw[x][j]);
			}
		}
	}
	for(auto x: kk){
		adj[1].emplace_back(x, fw[1][x]);
		adj[x].emplace_back(1, fw[x][1]);
		adj[n].emplace_back(x, fw[n][x]);
		adj[x].emplace_back(n, fw[x][n]);
	}
	for(int i=0; i<kk.size(); ++i){
		for(int j=i+1; j<kk.size(); ++j){
			adj[kk[i]].emplace_back(kk[j], fw[kk[i]][kk[j]]);
			adj[kk[j]].emplace_back(kk[i], fw[kk[j]][kk[i]]);
		}
	}
	memset(dist, 0x3f, sizeof dist);
	pq.push({1, 0, 0});
	dist[1][0] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.v == n && now.bit == (1 << (k)) - 1){
			cout << now.w;
			return ;
		}
		for(auto x: adj[now.v]){
			ll nxt = now.w + x.second;
			int nxt_bit = now.bit;
			if(go[x.first]){
				nxt_bit |= (1 << (go[x.first] - 1));
			}
			if(dist[x.first][nxt_bit] > nxt){
//				cerr << now.v << " " << x.first << " " << nxt << " " << nxt_bit << "\n";
				pq.push({x.first, nxt, nxt_bit});
				dist[x.first][nxt_bit] = nxt;
			}
		}
	}
	return ;
}

int main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
