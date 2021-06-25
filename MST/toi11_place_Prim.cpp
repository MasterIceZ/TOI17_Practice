/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi11_place
 * ALGO		: Minimum Spanning Tree
 * DATE		: 25 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

#define int long long

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w < o.w;
	}
};

vector<pair<int, int>> adj[200200];
bool visited[200200];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	priority_queue<Node> pq;
	pq.push({1, 1});
	int sum = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(visited[now.v]){
			continue;
		}
		visited[now.v] = true;
		sum += now.w - 1;
		for(auto x: adj[now.v]){
			if(!visited[x.first]){
				pq.push({x.first, x.second});
			}
		}
	}
	cout << sum;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
