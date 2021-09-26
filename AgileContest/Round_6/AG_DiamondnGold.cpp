#include<bits/stdc++.h>
using namespace std;

struct Node{
	int i, j, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};
int a[555][555], dist[5][555][555], r, c;
int dp[5][555][555];
priority_queue<Node> pq;

void dijkstra(int state, int x, int y){
	pq.push({x, y, a[x][y]});
	dist[state][x][y] = a[x][y];
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(int k=0; k<4; ++k){
			int ii = now.i + di[k], jj = now.j + dj[k];
			if(ii < 1 || jj < 1 || ii > r || jj > c){
				continue;
			}
			if(dist[state][ii][jj] > now.w + a[ii][jj]){
				dist[state][ii][jj] = now.w + a[ii][jj];
				pq.push({ii, jj, dist[state][ii][jj]});
			}
		}
	}
}

void DP(int state, int fir, int sec){
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			dp[state][i][j] = dist[fir][i][j] + dist[sec][i][j] - a[i][j];
			pq.push({i, j, dp[state][i][j]});
		}
	}
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(int k=0; k<4; ++k){
			int ii = now.i + di[k], jj = now.j + dj[k];
			if(ii < 1 || jj < 1 || ii > r || jj > c){
				continue;
			}
			if(dp[state][ii][jj] > now.w + a[ii][jj]){
				dp[state][ii][jj] = now.w + a[ii][jj];
				pq.push({ii, jj, dp[state][ii][jj]});
			}
		}
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> r >> c;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> a[i][j];
			dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = dp[3][i][j] = 1e9 + 7;
			dist[0][i][j] = dist[1][i][j] = dist[2][i][j] = dist[3][i][j] = 1e9 + 7;
		}
	}
	dijkstra(0, 1, 1); // Top Left
	dijkstra(1, 1, c); // Top Right
	dijkstra(2, r, c); // Bot Right
	dijkstra(3, r, 1); // Bot Left
	DP(0, 0, 1); // Top
	DP(1, 1, 2); // Right
	DP(2, 2, 3); // Bot
	DP(3, 3, 0); // Left
	int ans = 1e9;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			ans = min({ans, dp[0][i][j] + dp[2][i][j] - a[i][j], dp[1][i][j] + dp[3][i][j] - a[i][j]});
		}
	}
	cout << ans << "\n";
	return 0;
}
