/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_pipe
 * ALGO		: Minimum Spanning Tree
 * DATE		: 4 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const{
		return w > o.w;
	}
};

int a[15050], b[15050], parent[15050];
pair<int, int> pos[15050];

int create(int x, int y){
	return abs(pos[x].first - pos[y].first) + abs(pos[x].second - pos[y].second);
}

int root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = root(parent[u]);
}

void solve(){
	int n, k;
	cin >> n >> k;
	priority_queue<Edge> pq;
	for(int i=1; i<=n; ++i){
		cin >> a[i] >> b[i];
		pos[i] = {a[i], b[i]};
		for(int j=i-1; j>=1; --j){
			pq.push({i, j, create(i, j)});
		}
		parent[i] = i;
	}
	// N Vertex -> N-k Edges
	int cntE = 0, ans = 0;
	while(!pq.empty() && cntE < n - k){
		Edge now = pq.top();
		pq.pop();
		int ru = root(now.u), rv = root(now.v);
		if(ru == rv){
			continue ;
		}
		++cntE;
		parent[ru] = rv;
		ans += now.w;
	}
	cout << ans ;
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
