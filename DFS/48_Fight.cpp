/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Fight
 * ALGO		: Depth First Search
 * DATE		: 6 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

#define int long long

vector<pair<int, int>> adj[100010];
int color[100010], a[300010];

bool dfs(int u, int c, int r){
	if(color[u]){
		return color[u] == c;
	}
	color[u] = c;
	for(auto x: adj[u]){
		if(x.second > r){
			continue;
		}
		if(!dfs(x.first, 3-c, r)){
			return false;
		}
	}
	return true;
}

void solve(){
	int v, u, n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
		a[i] = u;
	}
	int l=1, r=m;
	while(l < r){
		memset(color, 0, sizeof color);
		int mid = l + (r - l + 1)/2;
		if(dfs(a[mid], 1, mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l + 1 ;
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
