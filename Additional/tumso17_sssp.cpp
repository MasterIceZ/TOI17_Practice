#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int v;
	double w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<pair<int, double>> adj[100100];
double dist[100100], w;
int parent[100100];

void solve(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v >> w;
		w = log2(w);
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=0; i<=n; ++i){
		dist[i] = 1e9 + 10;
	}
	dist[s] = 0;
	priority_queue<Node> pq;
	pq.push({s, 0});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.v == t){
			break;
		}
		for(auto x: adj[now.v]){
			double nxt = now.w + x.second;
			if(dist[x.first] > nxt){
				dist[x.first] = nxt;
				pq.push({x.first, nxt});
				parent[x.first] = now.v;
			}
		}
	}
	cout << s << " ";
	stack<int> st;
	int cur = t;
	while(cur != s){
		st.push(cur);
		cur = parent[cur];
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
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
