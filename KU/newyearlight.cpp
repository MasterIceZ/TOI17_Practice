/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: newyearlight
 * ALGO		: Topological Sort 
 * DATE		: 13 Nov 2021
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

const int MxN = 100100;
int edges[MxN];
vector<pair<int, int>> adj[MxN];
bool mark[MxN];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1, x, y, u; i<=m; ++i){
		cin >> x;
		edges[i] = x;
		vector<int> v;
		while(x--){
			cin >> y;
			v.push_back(y);
		}
		cin >> u;
		for(auto x: v){
			adj[x].emplace_back(u, i);
		}
	}
	queue<int> q;
	q.push(1);
	mark[1] = 1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		mark[now] = 1;
		for(auto x: adj[now]){
			if(--edges[x.second] == 0 && !mark[x.first]){
				mark[x.first] = 1;
				q.push(x.first);
			}
		}
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		cnt += mark[i];
	}
	cout << cnt;
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
