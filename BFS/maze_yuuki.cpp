#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};
char v[222][222];

void solve(){
	int n, m;
	cin >> n >> m;
	pair<int, int> start, stop;
	cin >> start.first >> start.second;
	cin >> stop.first >> stop.second;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> v[i][j];
		}
	}
	vector<vector<vector<int>>> dist(n+1, vector<vector<int>>(m+1, vector<int>(3, INT_MAX)));
	for(int k=0; k<2; ++k){
		queue<pair<pair<int, int>, int>>q;
		if(k == 0){
			q.emplace(start, 0);
		}
		else{
			q.emplace(stop, 0);
		}
		while(!q.empty()){
			pair<pair<int, int>, int> now = q.front();
			q.pop();
			if(dist[now.first.first][now.first.second][k] != INT_MAX){
				continue;
			}
			dist[now.first.first][now.first.second][k] = now.second;
			for(int l=0; l<4; ++l){
				int ii = now.first.first + di[l], jj = now.first.second + dj[l];
				if(ii < 1 || jj < 1 || ii > n || jj > m){
					continue;
				}
				if(dist[ii][jj][k] != INT_MAX){
					continue;
				}
				if(v[ii][jj] == '0'){
					dist[ii][jj][k] = now.second + 1;
				}
				if(v[ii][jj] == '1'){
					q.emplace(make_pair(ii, jj), now.second+1);
				}
			}
		}
	}
	int cnt = 0;
	int nin = INT_MAX;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(v[i][j] == '0' && dist[i][j][0] != INT_MAX && dist[i][j][1] != INT_MAX){
				++cnt;
				nin = min(nin, 1 + dist[i][j][0] + dist[i][j][1]);
			}
		}
	}
	cout << cnt << endl;
	cout << nin;
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
