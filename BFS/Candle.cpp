/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Candle
 * ALGO		: Breadth First Search
 * DATE		: 9 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1}, dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

char v[2222][2222];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> v[i][j];
		}
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(v[i][j] == '1'){
				cnt++;
				queue<pair<int, int>>q;
				q.emplace(i, j);
				while(!q.empty()){
					pair<int, int> now = q.front();
					q.pop();
					for(int k=0; k<8; ++k){
						int ii = now.first + di[k], jj = now.second + dj[k];
						if(v[ii][jj] == '1'){
							v[ii][jj] = '0';
							q.emplace(ii, jj);
						}
					}
				}
			}
		}
	}
	cout << cnt;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
