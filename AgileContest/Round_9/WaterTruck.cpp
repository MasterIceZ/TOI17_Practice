/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi16_watertruck
 * ALGO		: Dijkstra, Dynamic Programming with Bitmasks, Topological Sort
 * DATE		: 20 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Node{
	int u, w, bit;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

const int MxN = 100500;
vector<pair<int, int>> adj[MxN];
vector<Node> adj2[MxN];
int deg[MxN], use[MxN];
bool visited[MxN];

unordered_map<int, int> comp;
map<vector<int>, int> comp_edge;
priority_queue<Node> pq;

void solve(){
	int n, m, u, v, w, ans = 0;
	cin >> m >> n;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		deg[u]++, deg[v]++;
	}
	queue<int> q;
	for(int i=1; i<n; ++i){
		if(deg[i] == 1){
			q.push(i);
		}
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		visited[now] = true;
		for(auto x: adj[now]){
			if(visited[x.first]){
				continue;
			}
			ans += x.second * 2;
			if(--deg[x.first] == 1 && x.first != 0){
				q.push(x.first);
			}
		}
	}
	int it = 1, it2 = 0;
	use[0] = true;
	for(int i=1; i<n; ++i){
		if(!visited[i] && deg[i] > 2){
			use[i] = true;
			comp[i] = it++;
		}
	}
	for(int i=0; i<n; ++i){
		if(!use[i]){
			continue;
		}
		int loop = 0;
		for(auto x:  adj[i]){
			int v = x.first, w = x.second;
			if(visited[v]){
				continue;
			}
			vector<int> pth;
			pth.push_back(i);
			pth.push_back(v);
			int cur = v, sum = w, last = i;
			while(!use[cur]){
				for(auto y: adj[cur]){
					if(visited[y.first] || y.first == last){
						continue;
					}
					sum += y.second;
					last = cur;
					cur = y.first;
					break;
				}
				pth.push_back(cur);
			}
			if(i == cur){
				loop += sum;
				continue;
			}
			int l = comp[i], r = comp[cur];
			if(l > r){
				reverse(pth.begin(), pth.end());
			}
			if(comp_edge.find(pth) == comp_edge.end()){
				comp_edge[pth] = it2++;
			}
			adj2[l].push_back({r, sum, comp_edge[pth]});
		}
		ans += loop / 2;
	}
	vector<vector<int>> dist(it, vector<int> (1 << it2, 1e9 + 10));
	dist[0][0] = 0;
	pq.push({0, 0, 0});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(dist[now.u][now.bit] != now.w){
			continue;
		}
		for(auto x: adj2[now.u]){
			int nxt_bit = now.bit | (1 << x.bit);
			int nxt = now.w + x.w;
			if(dist[x.u][nxt_bit] > nxt){
				dist[x.u][nxt_bit] = nxt;
				pq.push({x.u, nxt, nxt_bit});
			}
		}
	}
	cout << ans + dist[0][(1 << it2) - 1];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
