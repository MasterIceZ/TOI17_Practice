/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: BUU Opposite
 * ALGO		: Breadth First Search
 * DATE		: 10 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char v[44][44];
int dist[44][44][44][44];
int dist2[44][44][44][44];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1 ,0};

void solve(){
	int n, m;
	cin >> n >> m;
	pair<int, int> A, B;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> v[i][j];
			if(v[i][j] == 'A'){
				A = make_pair(i, j);
			}
			else if(v[i][j] == 'B'){
				B = make_pair(i, j);
			}
		}
	}
	memset(dist, -1, sizeof dist);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			queue<pair<int, int>> q;
			q.emplace(i, j);
			dist[i][j][i][j] = 0;
			while(!q.empty()){
				pair<int, int> now = q.front();
				q.pop();
				for(int k=0; k<4; ++k){
					int ii = now.first + di[k], jj = now.second + dj[k];
					if(ii < 1 || jj < 1 || ii > n || jj > m){
						continue;
					}
					if(v[ii][jj] == '#' || dist[i][j][ii][jj] != -1){
						continue;
					}
					dist[i][j][ii][jj] = dist[i][j][now.first][now.second] + 1;
					q.emplace(ii, jj);
				}	
			}
		}
	}
	if(dist[A.first][A.second][B.first][B.second] == -1){
		cout << -1 << " " << 0;
		return ;
	}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	memset(dist2, -1, sizeof dist2);
	dist2[A.first][A.second][B.first][B.second] = 0;
	q.emplace(A, B);
	
	int step, diff;
	step = diff = INT_MAX;

	while(!q.empty()){
		pair<pair<int, int>, pair<int, int>> now = q.front();
		q.pop();

		if( abs(now.first.first - now.second.first) + abs(now.first.second - now.second.second) <= step){
			if(dist[now.first.first][now.first.second][now.second.first][now.second.second] < step){
				step = dist[now.first.first][now.first.second][now.second.first][now.second.second];
				diff = dist2[now.first.first][now.first.second][now.second.first][now.second.second] + 1;
			}
			else if(dist[now.first.first][now.first.second][now.second.second][now.second.second] == step){
				diff = min(diff, dist2[now.first.first][now.first.second][now.second.first][now.second.second]);
			}
		}

		for(int k=0; k<4; ++k){
			int aii = now.first.first + di[k];
			int ajj = now.first.second + dj[k];
			int bii = now.second.first - di[k];
			int bjj = now.second.second - dj[k];
			bool okA, okB;
			okA = okB = true;
			if(aii < 1 || ajj < 1 || aii > n || ajj > m || v[aii][ajj] == '#'){
				okA = false;
			}
		if(bii < 1 || bjj < 1 || bii > n || bjj > m || v[bii][bjj] == '#'){
				okB = false;
			}
			if(okA && okB){
				if(dist2[aii][ajj][bii][bjj] != -1){
					continue;
				}
				dist2[aii][ajj][bii][bjj] = dist2[now.first.first][now.first.second][now.second.first][now.second.second] + 1;
				q.emplace(make_pair(aii, ajj), make_pair(bii, bjj));
			}
			else if(okA && !okB){
				if(dist2[aii][ajj][now.second.first][now.second.second] != -1){
					continue;
				}
				dist2[aii][ajj][now.second.first][now.second.second] = dist2[now.first.first][now.first.second][now.second.first][now.second.second] + 1;
				q.emplace(make_pair(aii, ajj), now.second);
			}
			else if(!okA && okB){
				if(dist2[now.first.first][now.first.second][bii][bjj] != -1){
					continue;
				}
				dist2[now.first.first][now.first.second][bii][bjj] = dist2[now.first.first][now.first.second][now.second.first][now.second.second] + 1;
				q.emplace(now.first, make_pair(bii, bjj));
			}
		}
	}
	cout << step << " " << diff-1;
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
