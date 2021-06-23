/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Follow
 * ALGO		: Dijkstra + Depth First Search
 * DATE		: 23 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v, w, idx;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<Node> adj[1010];
int dist[1010];

void solve(){
	for(int i=1; i<=1010; ++i){
		adj[i].clear();
	}
	unordered_map<int, pair<int, int>> path;
	int n, m, s, ed, t, k;
	cin >> n >> m >> s >> ed >> t >> k;
	vector<int> peat;
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		peat.push_back(x);
	}
	for(int i=1; i<=m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(Node{v, w, i});
		adj[v].push_back(Node{u, w, i});
	}
	stack<pair<int ,int>> st;
	st.emplace(peat[0], 0);
	int it = 0;
	while(!st.empty()){
		pair<int, int> now = st.top();
		st.pop();
		if(it == peat.size() - 1){
			break;
		}
		for(auto x: adj[now.first]){
			if(x.v == peat[it + 1]){
				path[x.idx] = make_pair(now.second, now.second + x.w);
				st.emplace(x.v, now.second + x.w);
				++it;
				break;
			}
		}
	}
	memset(dist, 0x3f, sizeof dist);
	dist[s] = t;
	priority_queue<Node> pq;
	pq.push({s, t});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.v == ed){
			cout << now.w - t;
			return ;
		}
		for(auto x: adj[now.v]){
			int newW = now.w + x.w;
			if(path.find(x.idx) != path.end() && now.w >= path[x.idx].first && now.w < path[x.idx].second){
				newW = path[x.idx].second + x.w;
			}
			if(dist[x.v] > newW){
				dist[x.v] = newW;
				pq.push({x.v, newW});
			}
		}
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
