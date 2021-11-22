/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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
	int u;
	ll w;
	int state;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

ll a[333][333], v[333];
ll dist[333][333];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	ll cur = 0;
	for(int i=1; i<=m; ++i){
		cin >> v[i];
		if(i >= 2){
			cur += a[v[i - 1]][v[i]];
		}
	}
	if(m <= k){
		cout << 0;
		return ;
	}
	else if(k == 0){
		cout << cur;
		return ;
	}
	priority_queue<Node> pq;
	pq.push({0, 0, 0});
	memset(dist, 0x3f, sizeof dist);
	dist[0][0] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.u == m + 1){
			cout << dist[now.u][now.state];
			return ;
		}
		for(int i = now.u + 1; i<=m + 1; ++i){
			int nxt_state = now.state + (i - now.u - 1);
			if(nxt_state > k){
				break;
			}
			ll nxt = now.w + a[v[i]][v[now.u]];
			if(dist[i][nxt_state] > nxt){
				dist[i][nxt_state] = nxt;
				pq.push({i, nxt, nxt_state});
				dbg(i, nxt, nxt_state);
			}
		}
	}
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
