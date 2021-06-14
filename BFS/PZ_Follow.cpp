/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Follower
 * ALGO		: Breadth First Search
 * DATE		: 7 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

vector<pair<int, int>> g[111];
bool can[111][1111];

void solve(){
	memset(can, false, sizeof can);
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	for(int i=1; i<=m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	queue<pair<int, int>>q;
	q.emplace(s, 0);
	can[s][0]  = true;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(auto x: g[now.first]){
			int ii = x.first, val = x.second;
			if(can[ii][val ^ now.second]){
				continue;
			}
			can[ii][val ^ now.second] = true;
			q.emplace(ii, val ^ now.second);
		}
	}
	int ans = -1;
	for(int i=0; i<=1024; ++i){
		if(can[e][i]){
			ans = i;
			break;
		}
	}
	cout << ans;
	for(int i=0; i<=100; ++i){
		g[i].clear();
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
