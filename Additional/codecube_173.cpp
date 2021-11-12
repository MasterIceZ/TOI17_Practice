#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Edge{
	int u, v;
	ll w;
	bool operator < (const Edge& o) const{
		return w < o.w;
	}
};

int p[100100];
ll a[100100];

int fr(int u){
	if(u == p[u]){
		return u;
	}
	return p[u] = fr(p[u]);
}

void solve(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		p[i] = i;
	}
	priority_queue<Edge> pq;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		pq.push({u, v, a[u] + a[v]});
	}
	ll sum = 0;
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		int ru = fr(now.u), rv = fr(now.v);
		if(ru == rv){
			continue;
		}
		sum += now.w;
		p[ru] = rv;
	}
	cout << sum;
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
