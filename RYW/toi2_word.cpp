/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi2_word
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

int n, m, len;
char a[33][33];
bool ok;
char s[22];

const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j, int k, int now){
	if(now == len - 1){
		ok = true;
		return ;
	}
	int ii = di[k] + i;
	int jj = dj[k] + j;
	if(ii < 1 || jj < 1 || ii > n || jj > m){
		return ;
	}
	if(a[ii][jj] != tolower(s[now + 1])){
		return ;
	}
	dfs(ii, jj, k, now + 1);
}

void solve(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			a[i][j] = tolower(a[i][j]);
		}
	}
	int q;
	cin >> q;
	while(q--){
		cin >> s;
		len = strlen(s);
		ok = false;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				if(a[i][j] != tolower(s[0])){
					continue;
				}
				dbg(i, j);
				for(int k=0; k<8; ++k){
					dfs(i, j, k, 0);
					if(ok){
						cout << i-1 << " " << j-1 << "\n";
						break;
					}
				}
				if(ok){
					break;
				}
			}
			if(ok){
				break;
			}
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
