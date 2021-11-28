/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi1_pattern
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

char a[50050][77];

void solve(){
	int n, x, y, z, maxx = 0;
	cin >> n;
	memset(a, 'o', sizeof a);
	for(int i=1; i<=n; ++i){
		cin >> x >> y >> z;
		while(z-- && y <= 70){
			a[x][y] = 'x';
			y++;
		}
		maxx = max(maxx, x);
	}
	for(int i=1; i<=maxx; ++i){
		for(int j=1; j<=70; ++j){
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
