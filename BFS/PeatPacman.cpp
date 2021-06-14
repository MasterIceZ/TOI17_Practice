/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PeaTT_Pacman
 * ALGO		: Breadth First Search
 * DATE		: 13 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char a[777][777];
int dist[777][777];
bool visited[777][777];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void solve(){
	memset(dist, 0x3f, sizeof dist);
	memset(visited, false, sizeof visited);

	int n, m, N, t;
	pair<int, int> start;
	cin >> n >> m >> N >> t >> start.first >> start.second;
	start.first += 1, start.second += 1;
	queue<pair<int, int>> q;
	for(int i=1; i<=N; ++i){
		int ghost, x, y;
		cin >> ghost >> x >> y;
		x += 1, y += 1;
		if(dist[x][y] > ghost){
			dist[x][y] = ghost;
			q.emplace(x, y);
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k], jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m || a[ii][jj] == '#'){
				continue;
			}
			if(dist[now.first][now.second] + 1 < dist[ii][jj]){
				dist[ii][jj] = dist[now.first][now.second] + 1;
				q.emplace(ii, jj);
			}
		}
	}
	int nax = 0;
	visited[start.first][start.second] = true;
	queue<pair<pair<int, int>, int>> qq;
	qq.emplace(start, 0);
	while(!qq.empty()){
		pair<pair<int, int>, int> now = qq.front();
		qq.pop();
		nax = max(nax, dist[now.first.first][now.first.second]);
		for(int k=0; k<4; ++k){
			int ii = now.first.first + di[k];
			int jj = now.first.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m || a[ii][jj] == '#'){
				continue;
			}
			if(dist[ii][jj] <= now.second + 1 || visited[ii][jj]){
				continue;
			}
			visited[ii][jj] = true;
			qq.emplace(make_pair(ii, jj), now.second + 1);
		}
	}
	if(nax - t > 0){
		cout << "YES";
	}
	else{
		cout << "NO" << " " << nax - 1;
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
