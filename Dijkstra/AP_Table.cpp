/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Table
 * ALGO		: Dijkstra
 * DATE		: 23 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int i, j, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

char a[33][33];
int x, y;
vector<Node> adj[33][33];
int dist[33][33];
bool visited[33][33];

void solve(){
	int n;
	cin >> n >> x >> y;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i - 1 >= 1){
				adj[i][j].push_back({i-1, j, a[i][j] == a[i-1][j] ? x : y});
			}
			if(j - 1 >= 1){
				adj[i][j].push_back({i, j-1, a[i][j] == a[i][j-1] ? x : y});
			}
			if(i + 1 <= n){
				adj[i][j].push_back({i+1, j, a[i][j] == a[i+1][j] ? x : y});
			}
			if(j + 1 <= n){
				adj[i][j].push_back({i, j+1, a[i][j] == a[i][j+1] ? x : y});
			}
		}
	}
	int nax = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			memset(visited, false, sizeof visited);
			memset(dist, 0x3f, sizeof dist);
			priority_queue<Node> pq;
			pq.push({i, j, 0});
			dist[i][j] = 0;
			while(!pq.empty()){
				Node now = pq.top();
				pq.pop();
				if(visited[now.i][now.j]){
					continue;
				}
				visited[now.i][now.j] = true;
				for(auto x: adj[now.i][now.j]){
					if(dist[x.i][x.j] >= dist[now.i][now.j] + x.w){
						dist[x.i][x.j] = dist[now.i][now.j] + x.w;
						pq.push({x.i, x.j, dist[x.i][x.j]});
					}
				}
			}
			for(int k=1; k<=n; ++k){
				for(int l=1; l<=n; ++l){
					nax = max(nax, dist[k][l]);
				}
			}
		}
	}
	cout << nax;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			adj[i][j].clear();
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
