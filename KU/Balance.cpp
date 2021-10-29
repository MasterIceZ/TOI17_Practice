/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Balance
 * ALGO		: Depth First Search
 * DATE		: 29 Oct 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

vector<pair<int, int>> adj[1010];
int n, ans;

int dfs(int u, int type){
	if(type == 1){
		return u;
	}
	int l = dfs(adj[u][0].first, adj[u][0].second);
	int r = dfs(adj[u][1].first, adj[u][1].second);
	if(l != r){
		ans += max(l, r) - min(l, r);
	}
	return max(l, r) * 2;
}

void solve(){
	int opr, x;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> opr >> x;
		adj[i].emplace_back(x, opr);
		cin >> opr >> x;
		adj[i].emplace_back(x, opr);
	}
	dfs(1, 0);
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
