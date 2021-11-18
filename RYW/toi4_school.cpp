/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi4_school
 * ALGO		: Brute Force
 * DATE		: 17 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int n, m;
int dp[66][66];
char a[66][66];
bool visited[66][66];

void land(int i, int j){
	queue<pair<int, int>> q;
	q.emplace(i, j);
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
			if(visited[ii][jj] || a[ii][jj] != 'P'){
				continue;
			}
			q.emplace(ii, jj);
		}
	}
}

int calc(int x, int y, int k){
	int cnt = 0 ;
	memset(visited, false, sizeof visited);
	for(int i=x; i<=x+k-1; ++i){
		for(int j=y; j<=y+k-1; ++j){
			if(a[i][j] == 'P' && !visited[i][j]){
				land(i, j);
				cnt++;
			}	
		}
	}
	return cnt;
}

void solve(){
	cin >> m >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'T'){
				dp[i][j] = 1;
			}
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	int sz = min(n, m);
	bool ok = false;
	int res = 1e9;
	for(int k=sz; k>=1; --k){
		for(int i=k; i<=n; ++i){
			for(int j=k; j<=m; ++j){
				int tree = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
				if(!tree){
					ok = true;
					dbg(i, j, k);
					res = min(res, calc(i - k + 1, j - k + 1, k));
				}
			}
		}
		if(ok){
			cout << k * k << " " << res;
			return ;
		}
	}
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
