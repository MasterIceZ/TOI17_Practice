/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Fair
 * ALGO		: Dijkstra
 * DATE		: 21 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	ll v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

ll shop[50050];
ll dist[111][50050];

vector<int> Shop[110];
vector<Node> adj[50050];

void solve(){
	int n, m, a;
	cin >> n >> m >> a;
	for(int i=1; i<=n; ++i){
		cin >> shop[i];
		Shop[shop[i]].push_back(i);
	}
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	memset(dist, 0x3f, sizeof dist);
	for(int i=1; i<=100; ++i){
		priority_queue<Node> pq;
		for(auto x: Shop[i]){
			pq.push({x, 0});
			dist[i][x] = 0;
		}
		while(!pq.empty()){
			Node now = pq.top();
			pq.pop();
			for(auto x: adj[now.v]){
				if(dist[i][x.v] > now.w + x.w){
					dist[i][x.v] = now.w + x.w;
					pq.push({x.v, now.w + x.w});
				}
			}
		}
	}
	ll ans = LLONG_MAX;
	for(int i=1; i<=n; ++i){
		vector<ll> tmp;
		for(int j=1; j<=100; ++j){
			tmp.push_back(dist[j][i]);
		}
		sort(tmp.begin(), tmp.end());
		ll sum = 0;
		for(int j=0; j<a; ++j){
			if(tmp[j] >= 4e18){
				sum = LLONG_MAX;
				break;
			}
			sum += tmp[j];
		}
		ans = min(ans, sum);
	}
	cout << (ans == LLONG_MAX ? -1: ans);
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
	for(int i=1; i<=100; ++i){
		Shop[i].clear();
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
