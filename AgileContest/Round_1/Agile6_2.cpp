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
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

vector<int> g[100100];
int parent[100100];
bool visited[100100];

int root(int u){
	if(parent[u] == u){
		return u;
	}
	return parent[u] = root(parent[u]);
}

int bfs(int u){
	memset(visited, false, sizeof visited);
	queue<int> q;
	q.push(u);
	int cnt = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(visited[now]){
			continue;
		}
		visited[now] = true;
		++cnt;
		for(auto x: g[now]){
			if(!visited[x]){
				q.push(x);
			}
		}
	}
	
	return cnt;
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	for(int i=1; i<n; ++i){
		int u, v;
		cin >> u >> v ;
		g[u].push_back(v);
		parent[v] = root(u);
	}
	set<int> cnt;
	for(int i=1; i<=n; ++i){
		cnt.insert(root(i));
	}
	int ans = -1, IT = -1;
	for(set<int>::iterator it = cnt.begin(); it != cnt.end(); ++it){
		int now = bfs(*it);
//		cout << *it << endl;
		if(now > ans){
			ans = now;
			IT = *it;
		}
	}
	cout << (cnt.size() - 1) << " " << IT;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
