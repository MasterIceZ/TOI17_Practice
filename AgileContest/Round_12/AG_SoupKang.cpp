/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Soup Kang
 * ALGO		: Constructive Algorithm
 * DATE		: 4 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

char a[505][505];
int n, m;

struct Con{
	int up[505][505], down[505][505];
	void update(int j){
		int last = -1;
		for(int i=0; i<n; ++i){
			if(a[i][j] == 'x'){
				last = i;
			}
			up[i][j] = last;
		}
		last = -1;
		for(int i=n-1; i>=0; --i){
			if(a[i][j] == 'x'){
				last = i;
			}
			down[i][j] = last;
		}
	}
} table;

int calc(int i, int j, int k, int l){
	return (i - k) * (i - k) + (j - l) * (j - l);
}

void solve(){
	int q;
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=0; i<m; ++i){
		table.update(i);
	}
	cin >> q;
	while(q--){
		int i, j;
		cin >> i >> j;
		i--, j--;
		int ans = 1e9 + 100;
		for(int k=0; k<m; ++k){
			if(table.up[i][k] != -1){
				ans = min(ans, calc(i, j, table.up[i][k], k));
			}
			if(table.down[i][k] != -1){
				ans = min(ans, calc(i, j, table.down[i][k], k));
			}
		}
		a[i][j] = 'x';
		table.update(j);
		cout << ans << "\n";
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
