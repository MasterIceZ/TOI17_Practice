/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Lazanta
 * ALGO		: Dijkstra with Bitmask
 * DATE		: 14 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v;
	ll w;
	int state;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

const int MxN = 50500;
ll w, dist[1 << 5][MxN];
vector<pair<int, ll>> adj[MxN];
int cur[MxN];

void solve(){
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	s = " " + s;
	t = "  " + t;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}	
	unordered_map<char, int> mp;
	mp['X'] = (1 << 3);
	mp['M'] = (1 << 2);
	mp['A'] = (1 << 1);
	mp['S'] = (1 << 0);
	int res = (mp[s[1]] | mp[s[2]] | mp[s[3]] | mp[s[4]]);
	for(int i=2; i<=n; ++i){
		cur[i] = mp[t[i]];
	}
	memset(dist, 0x3f, sizeof dist);
	priority_queue<Node> pq;
	pq.push({n, 0, res | cur[n]});
	dist[res | cur[n]][n] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			ll nxt = x.second + now.w;
			int nxt_state = now.state | cur[x.first];
			if(dist[nxt_state][x.first] > nxt){
				pq.push({x.first, nxt, nxt_state});
				dist[nxt_state][x.first] = nxt;
			}
		}
	}
	cout << dist[(1 << 4) - 1][1];
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
