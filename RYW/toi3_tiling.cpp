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

int a[22][22];
bool mark[22][22];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

void solve(){
	int n, ans = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	queue<pair<int, int>> q;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(!mark[i][j] && a[i][j]){
				q.emplace(i, j);
				int cou = 0, x = 0, y = 0;
				mark[i][j] = true;
				while(!q.empty()){
					pair<int, int> now = q.front();
					q.pop();
					cou++;
					for(int k=0; k<4; ++k){
						int ii = di[k] + now.first;
						int jj = dj[k] + now.second;
						if(ii < 1 || jj < 1 || ii > n || jj > n){
							continue;
						}
						if(a[ii][jj] != a[i][j] || mark[ii][jj]){
							continue;
						}
						mark[ii][jj] = 1;
						q.emplace(ii, jj);
						x = max(x, abs(ii - i));
						y = max(y, abs(jj - j));
					}
				}
				dbg(cou, x, y);
				ans += (cou == 3 && x == 1 && y == 1);
			}
		}
	}
	cout << ans;
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
