/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Robot
 * ALGO		: Breadth First Search
 * DATE		: 9 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll dist[2222][2222];
char v[2222][2222];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void solve(){
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;
	memset(dist, -1, sizeof dist);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> v[i][j];
			if(v[i][j] == 'X'){
				v[i][j] = 'E';
				dist[i][j] = 0;
				q.emplace(i, j);
			}
		}
	}
	ll cnt = 0, d = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(v[now.first][now.second] == 'A'){
			cnt++;
			d += dist[now.first][now.second] * 2;
		}
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k], jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(dist[ii][jj] != -1 || v[ii][jj] == 'W'){
				continue;
			}
			q.emplace(ii, jj);
			dist[ii][jj] = dist[now.first][now.second] + 1;
		}
	}
	cout << cnt << " " << d;
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
