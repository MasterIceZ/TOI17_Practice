/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Travelling TOI13
 * ALGO		: Dijkstra
 * DATE		: 23 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<pair<int, int>> adj[10010];
bool visited[10010];
int n, dist_st[10010], dist_ed[10010];

void dijkstra(int start, int *dist){
	priority_queue<Node> pq;
	memset(visited, false, sizeof visited);
//	memset(dist, 0x3f, sizeof dist);
	dist[start] = 0;
	pq.push({start, 0});
	int cnt = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(visited[now.v]){
			continue;
		}
		visited[now.v] = true;
		++cnt;
		if(cnt == n){
			break;
		}
		for(auto x: adj[now.v]){
			if(dist[x.first] > dist[now.v] + x.second){
				dist[x.first] = dist[now.v] + x.second;
				pq.push({x.first, dist[x.first]});
			}
		}
	}
	return ;
}

void solve(){
	int m, x, y, z;
	cin >> n >> m >> x >> y >> z;
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist_st, 0x3f, sizeof dist_st);
	memset(dist_ed, 0x3f, sizeof dist_ed);
	dijkstra(x, dist_st);
	dijkstra(y, dist_ed);
	int a = INT_MIN, b = INT_MAX, c;
	for(int i=0; i<=n; ++i){
		if(dist_st[i] <= z && dist_st[i] >= a && dist_ed[i] < b){
			a = dist_st[i];
			b = dist_ed[i];
			c = i;
		}
	}
	cout << c << " " << a << " " << b ;
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
