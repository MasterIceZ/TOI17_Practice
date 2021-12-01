/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int a[33][33];
bool visited[33][33];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

void solve(){
	int n, maxx = -1e9;
	pair<int, int> st;
	cin >> n >> st.second >> st.first;
	queue<pair<int, int>> q;
	q.emplace(st);
	visited[st.first][st.second] = true;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		maxx = max(maxx, a[now.first][now.second]);
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > n){
				continue;
			}
			if(a[ii][jj] == 100 || a[ii][jj] <= a[now.first][now.second] || visited[ii][jj]){
				continue;
			}
			q.emplace(ii, jj);
			visited[ii][jj] = true;
		}
	}
	cout << maxx;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
