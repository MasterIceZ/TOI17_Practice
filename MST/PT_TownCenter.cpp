/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

#define int long long

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const{
		return w > o.w;
	}
};

int deg[1010], parent[1010];

int root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = root(parent[u]);
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	priority_queue<Edge> pq;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			int w;
			cin >> w;
			if(i < j){
				pq.push({i, j, w});
			}
		}
	}
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		int ru = root(now.u), rv = root(now.v);
		if(ru == rv){
			continue;
		}
		deg[now.u]++, deg[now.v]++;
		parent[ru] = rv;
	}
	int ans, cnt;
	cnt = INT_MIN;
	for(int i=1; i<=n; ++i){
		if(deg[i] > cnt){
			ans = i;
			cnt = deg[i];
		}
//		cout << deg[i] << " ";
	}
//	cout << endl;
	cout << ans << " " << cnt ;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
		memset(deg, 0, sizeof deg);
	}
	return 0;
}
