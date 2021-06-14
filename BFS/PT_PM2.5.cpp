/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_PM2.5
 * ALGO		: Breadth First Search
 * DATE		: 7 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};
int dist[1111][1111];
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<char>>v(n+1, vector<char>(m+1));
	pair<int, int> start, stop;
	queue<pair<int, int>>q;
	memset(dist, -1, sizeof dist);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> v[i][j];
			if(v[i][j] == 'E'){
				q.emplace(i, j);
				dist[i][j] = 0;
			}
		}
	}	
	int ans = -1;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		int i = now.first, j = now.second;
		for(int k=0; k<4; ++k){
			int ii = i + di[k], jj = j + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(v[ii][jj] == '#' || dist[ii][jj] != -1){
				continue;
			}
			dist[ii][jj] = dist[i][j] + 1;
			if(v[ii][jj] == 'S'){
				ans = dist[ii][jj];
			}
			q.emplace(ii, jj);
		}	
	}
	int l = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(dist[i][j] != -1 && dist[i][j] <= ans && v[i][j] >= '0' && v[i][j] <= '9'){
				l += v[i][j] - '0';
			}
		}
	}
	cout << (ans == -1 ? -1 : l);
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
