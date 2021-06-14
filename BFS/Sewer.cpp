/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sewer
 * ALGO		: Breadth First Search
 * DATE		: 9 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int layer[111][111];
vector<pair<int, int>>adj[111][111];

void solve(){
	memset(layer, -1, sizeof layer);
	int n, m;
	char x;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> x;
			if(x == 'B' || x == 'R'){
				adj[i][j].emplace_back(i, j+1);
				adj[i][j+1].emplace_back(i, j);
			}
			if(x == 'B' || x == 'D'){
				adj[i][j].emplace_back(i+1, j);
				adj[i+1][j].emplace_back(i, j);
			}
		}
	}
	queue<pair<int, int>> q;
	layer[1][1] = 1;
	q.emplace(1, 1);
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(auto x: adj[now.first][now.second]){
			if(layer[now.first][now.second] + 1 > layer[x.first][x.second] && layer[x.first][x.second] != -1){
				continue;
			}
			if(layer[now.first][now.second] + 1 == layer[x.first][x.second]){
				cout << layer[x.first][x.second] << endl;
				cout << x.first << " " << x.second;
				return ;
			}
			layer[x.first][x.second] = 1 + layer[now.first][now.second];
			q.emplace(x.first, x.second);
		}
	}
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
