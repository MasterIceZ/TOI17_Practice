/*
 * AUTHOR	: Hydrolyzed~
 * TASK		: Tension6
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

struct Deg{
	int val, cnt = 0;
	bool operator < (const Deg& o) const{
		return cnt > o.cnt;
	}
};

vector<int> g[100100];
bool visited[100100];
int parent[100100];
Deg deg[100100];
vector<pair<int, int>> tmp;

int root(int u){
	if(u == parent[u]){
		return u;
	}
	return root(parent[u]);
}

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		deg[i].val = i;
		parent[i] = i;
	}
	for(int i=1; i<n; ++i){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		parent[v] = root(u);
		deg[u].cnt++;
	}
	for(int i=1; i<=n; ++i){
		deg[parent[i]].cnt += deg[i].cnt;
	}
	sort(deg + 1, deg + n + 1);
	for(int i=1; i<=n; ++i){
		int start = deg[i].val;
		if(visited[start]){
			continue;
		}
		queue<int> q;
		q.push(start);
		int vis = 0;
		while(!q.empty()){
			int now = q.front();
			q.pop();
			if(visited[now]){
				continue;
			}
			visited[now] = true;
			++vis;
			for(auto x: g[now]){
				if(!visited[x]){
					q.push(x);
				}
			}
		}
		tmp.emplace_back(vis, start);
	}
//	cout << tmp.size() << endl;
//	for(auto x: tmp){
//		cout << x.first << " " << x.second << endl;
//	}
	sort(all(tmp));
	cout << (tmp.size() - 1) << " " << tmp[0].second; 
	return ;
}

int32_t main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
