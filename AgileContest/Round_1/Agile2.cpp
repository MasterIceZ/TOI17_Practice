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

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

const int MxN = 500050;

struct A{
	ll r, v;
	bool operator < (const A& o) const{
		if(r != o.r){
			return r < o.r;
		}
		return v > o.v;
	}
};
struct B{
	ll r, v;
	bool operator < (const B& o) const{
		if(r != o.r){
			return r < o.r;
		}
		return v < o.v;
	}
};

int parent[MxN], a[MxN], b[MxN];

A inc[MxN];
B dec[MxN];

int root(int u){
	if(parent[u] == u){
		return u;
	}
	return parent[u] = root(parent[u]);
}

int n, m;
vector<ll> comp;
ll qs[MxN];

void solve(){
	
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q = 1;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		p[i] = i;
		cin >> a[i] >> b[i];
	}
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		int ru = root(u), rv = root(v);
		parent[ru] = rv;
	}
	for(int i=1; i<=n; ++i){
		int r = root(i);
		inc[i] = {r, a[i]};
		dec[i] = {r, b[i]};
	}
	sort(inc + 1, inc + n + 1);
	sort(dec + 1, dec + n + 1);
	for(int i=1; i<=n; ++i){
		qs[i] += qs[i-1] + (inc[i].v - dec[i].v);
	} 
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
