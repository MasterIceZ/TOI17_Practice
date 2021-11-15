/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: next
 * ALGO		: Depth First Search
 * DATE		: 12 Nov 2021
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

bitset<100100> visited;
int cnt = 0;
vector<int> adj[100100];

void dfs(int u){
	visited[u] = true;
	for(auto x: adj[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
	cnt++;
}

void solve(){
	int n, v, res = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> v;
		adj[i].push_back(v);
	}
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			cnt = 0;
			dfs(i);
			res = max(res, cnt);
		}
	}
	cout << res;
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
