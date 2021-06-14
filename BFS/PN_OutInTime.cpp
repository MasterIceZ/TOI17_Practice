/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_OutInTime
 * ALGO		: Breadth First Search
 * DATE		: 8 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void solve(){
	int n, m, nax;
	cin >> n >> m >> nax;
	vector<vector<char>>v(n+1, vector<char>(m+1));	
	vector<vector<int>>dist(n+1, vector<int>(m+1, -1));
	vector<vector<bool>>visited(n+1, vector<bool>(m+1, false));
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> v[i][j];
		}
	}
	pair<int, int>start, stop;
	cin >> start.first >> start.second >> stop.first >> stop.second;
	queue<pair<int, int>> q;
	set<pair<int, int>> s;
	q.emplace(start);
	dist[start.first][start.second] = 0;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		visited[now.first][now.second] = true;
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k], jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(v[ii][jj] == '.' && !visited[ii][jj]){
				s.emplace(ii, jj);
				q.emplace(ii, jj);
				dist[ii][jj] = dist[now.first][now.second] + 1;
			}
		}
	}
	if(dist[stop.first][stop.second] > nax || dist[stop.first][stop.second] == -1){
		cout << -1;
	}
	else{
		cout << (1 + min((nax - dist[stop.first][stop.second]) / 2 + dist[stop.first][stop.second], (int)s.size()));
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
