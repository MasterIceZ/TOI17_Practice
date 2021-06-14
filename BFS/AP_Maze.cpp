/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Maze
 * ALGO		: Breadth First Search
 * DATE		: 7 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char laser[333][333][5];
int dist[333][333][5];

const int di[] = {-1, 1, 0 , 0}, dj[] = {0, 0, -1, 1};

char next(char x){
	if(x == '-'){
		return '\\';
	}
	if(x == '\\'){
		return '|';
	}
	if(x == '|'){
		return '/';
	}
	if(x == '/'){
		return '-';
	}
	return x;
}

void solve(){
	memset(laser, '\0', sizeof laser);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(n+1, vector<char>(m+1));
	vector<pair<int, int>> laser_pos;
	pair<int, int> start, stop;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> v[i][j];
			if(v[i][j] == 'E'){
				stop = make_pair(i, j);
			}
			else if(v[i][j] == 'S'){
				start = make_pair(i ,j);
			}
			laser[i][j][0] = v[i][j];
			laser[i][j][1] = next(v[i][j]);
			laser[i][j][2] = next(laser[i][j][1]);
			laser[i][j][3] = next(laser[i][j][2]);	
		}
	}
	int ii, jj;
	for(int k=0; k<4; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				if(laser[i][j][k] == '-'){
					ii = i, jj = j + 1;
					while(jj <= m && (laser[ii][jj][k] == '.' || laser[ii][jj][k] == '*')){
						laser[ii][jj][k] = '*';
					   	jj += 1;	
					}
					ii = i, jj = j - 1;
					while(jj > 0 && (laser[ii][jj][k] == '.' || laser[ii][jj][k] == '*')){
						laser[ii][jj][k] = '*';
						jj -= 1;
					}
				}
				else if(laser[i][j][k] == '/'){
					ii = i - 1, jj = j + 1;
					while(jj <= m && ii > 0 && (laser[ii][jj][k] == '.' || laser[ii][jj][k] == '*')){
						laser[ii][jj][k] = '*';
						jj += 1, ii -= 1;
					}
					ii = i + 1, jj = j - 1;
					while(jj > 0 && ii <= n && (laser[ii][jj][k] == '.' || laser[ii][jj][k] == '*')){
						laser[ii][jj][k] = '*';
						jj -= 1, ii += 1;
					}
				}
				else if(laser[i][j][k] == '|'){
					ii = i + 1, jj = j;
					while(ii <= n && (laser[ii][jj][k] == '.' || laser[ii][jj][k] == '*')){
						laser[ii][jj][k] = '*';
						ii += 1;
					}
					ii = i - 1, jj = j;
					while(ii > 0 && (laser[ii][jj][k] == '.' || laser[ii][jj][k] == '*')){
						laser[ii][jj][k] = '*';
						ii -= 1;
					}
				}
				else if(laser[i][j][k] == '\\'){
					ii = i - 1, jj = j - 1;
					while(jj > 0 && ii > 0 && (laser[ii][jj][k] == '.' || laser[ii][jj][k] == '*')){
						laser[ii][jj][k] = '*';
						jj -= 1, ii -= 1;
					}
					ii = i + 1, jj = j + 1;
					while(jj <= m && ii <= n && (laser[ii][jj][k] == '.' || laser[ii][jj][k] == '*')){
						laser[ii][jj][k] = '*';
						jj += 1, ii += 1;
					}
				}
			}
		}
	}
	memset(dist, -1, sizeof dist);
	queue<pair<pair<int, int>, int>>q;
	q.emplace(start, 0);
	dist[start.first][start.second][0] = 0;
	bool visited = false;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(now.first == stop){
			visited = true;
			cout << dist[now.first.first][now.first.second][(now.second) % 4];
			break;
		}
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first.first, jj = dj[k] + now.first.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(dist[ii][jj][(now.second + 1) % 4] != -1){
				continue;
			}
			int Q = (now.second+1) % 4;
			if(laser[ii][jj][Q] == 'S' || laser[ii][jj][Q] == '.' || laser[ii][jj][Q] == 'E'){
				dist[ii][jj][(now.second + 1) % 4] = now.second + 1;
				q.emplace(make_pair(ii, jj), now.second + 1);
			}
		}
	}
	if(!visited){
		cout << -1;
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
