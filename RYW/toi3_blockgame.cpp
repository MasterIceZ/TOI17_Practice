/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi3_blockgame
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

int n, m, score = 0;
char a[10][10], opr, cur;

void fall(){
	for(int j=1; j<=m; ++j){
		for(int i=n-1; i>=1; --i){
			int x = i;
			while(x <= n && a[x + 1][j] == '-' && isalpha(a[x][j])){
				swap(a[x + 1][j], a[x][j]);
				x++;
			}
		}
	}
}

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

void bomb(int i, int j){
	score += 5;
	a[i][j] = '-';
	for(int k=0; k<4; ++k){
		int ii = di[k] + i;
		int jj = dj[k] + j;
		if(ii < 1 || jj < 1 || ii > n || jj > m){
			continue;
		}
		if(a[ii][jj] != cur){
			continue;
		}
		bomb(ii, jj);
	}
}

bool ch(int x, int y){
	return
		isalpha(a[x][y]) && 
		(a[x][y] == a[x + 1][y] ||
		a[x][y] == a[x][y + 1] || 
		a[x][y] == a[x - 1][y] ||
		a[x][y] == a[x][y - 1]);
}

void solve(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	int q, x, y;
	cin >> q;
	while(q--){
		cin >> x >> y >> opr;
		x++, y++;
		if(opr == 'L'){
			if(y-1 >=1 && isalpha(a[x][y]) && a[x][y - 1] == '-'){
				dbg("OK");
				swap(a[x][y], a[x][y - 1]);
				fall();
				for(int i=1; i<=n; ++i){
					for(int j=1; j<=m; ++j){
						if(ch(i, j)){
							cur = a[i][j];
							bomb(i, j);
							fall();
						}
					}
				}
			}
			else{
				score -= 5;
			}
		}
		else{
			if(y+1 <= m && isalpha(a[x][y]) && a[x][y + 1] == '-'){
				dbg("OK");
				swap(a[x][y + 1], a[x][y]);
				fall();
				for(int i=1; i<=n; ++i){
					for(int j=1; j<=m; ++j){
						if(ch(i, j)){
							cur = a[i][j];
							bomb(i, j);
							fall();
						}
					}
				}
			}
			else{
				score -= 5;
			}
		}
	}
	cout << score << "\n";
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cout << a[i][j] << " ";
		}
		cout << "\n";
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
