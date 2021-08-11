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

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

map<set<pair<int, int>>, int> mp;
set<pair<int, int>> now;

void solve(){
	int m;
	cin >> m;
	for(int i=1, u, v; i<m; ++i){
		cin >> u >> v;
		now.emplace(min(u, v), max(u, v));
	}
	cout << mp[now];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q = 1;
	cin >> n >> q;
	for(int i=1, m; i<=n; ++i){
		cin >> m;
		for(int j=0, u, v; j<m - 1; ++j){
			cin >> u >> v;
			now.emplace(min(u, v), max(u, v));
		}
		dbg(now.size());
		mp[now] += 1;
		now.clear();
	}
	while(q--){
		solve();
		cout << endl;
		now.clear();
	}
	return 0;
}
