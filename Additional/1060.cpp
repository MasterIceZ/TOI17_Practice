#include<bits/stdc++.h>
using namespace std;

int n;
int a[33][33];
const int di[] = {-1,0,0,1}, dj[] = {0,-1,1,0};
bool visited[33][33];

int bfs(int stx, int sty){
	int nax = -1e9;
	queue<pair<int, int>> q;
	q.push(make_pair(stx, sty));
	visited[stx][sty] = true;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		nax = max(nax, a[now.first][now.second]);
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k], jj = now.second + dj[k];
			if(ii<0 || jj<0 || ii>n || jj>n || visited[ii][jj] || a[ii][jj] <= a[now.first][now.second] || a[ii][jj] == 100){
				continue;
			}
			q.push(make_pair(ii, jj));
			visited[ii][jj] = true;
		}
	}
	return nax;
}

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int stx, sty;
	cin >> sty >> stx;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	cout <<	bfs(stx, sty) << endl;
	return 0;

}
