/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Room
 * ALGO		: Breadth First Search
 * DATE		: 23 Oct 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

char a[33][33];
bool visited[33][33], used[33][33];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

void solve(){
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'A' || a[i][j] == 'W'){
				q.emplace(i, j);		
			}
		}
	}
	memset(used, false, sizeof visited);
	memset(visited, false, sizeof visited);
	int cnt = 0;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		visited[now.first][now.second] = true;
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(visited[ii][jj] || a[ii][jj] == '#'){
				continue;
			}
			if(a[ii][jj] == '*' && !used[ii][jj]){
				cnt++;
				used[ii][jj] = true;
			}
			q.emplace(ii, jj);
			dbg(ii, jj);
		}
	}
	cout << cnt;
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
