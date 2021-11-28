/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi1_brick
 * ALGO		: Implementation
 * DATE		: 26 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int n, m, x;
char a[22][22];

void fall(int i, int j){
	if(i < 1 || x == 0){
		return;
	}
	x--;
	a[i][j] = '#';
	fall(i - 1, j);
}

void solve(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int j=1; j<=m; ++j){
		cin >> x;
		a[n + 1][j] = 'O';
		bool ok = false;
		for(int i=1; i<=n + 1 && !ok; ++i){
			if(a[i][j] == 'O'){
				fall(i - 1, j);
				ok = true;
			}
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cout << a[i][j];
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
