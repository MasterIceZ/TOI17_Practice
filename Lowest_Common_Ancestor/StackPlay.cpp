/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Stack Play
 * ALGO		: Lowest Common Ancestor
 * DATE		: 23 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

char opr;
const int MxN = 300100;
const int LG = 22;
int st[MxN], level[MxN];
int dp[LG][MxN];

void solve(){
	int q, x, y;
	cin >> q;
	for(int i=1; i<=q; ++i){
		cin >> opr;
		if(opr == 'a'){
			cin >> x;
			st[i] = i;
			dp[0][i] = st[x];
			level[i] = level[st[x]] + 1;
			for(int k=1; k<=20; ++k){
				dp[k][i] = dp[k - 1][dp[k - 1][i]];
			}
		}
		else if(opr == 'b'){
			cin >> x;
			st[i] = dp[0][st[x]];
			level[i] = level[dp[0][st[x]]];
			cout << (!st[x] ? -1: st[x]) << "\n"; 
		}
		else{
			cin >> x >> y;
			st[i] = st[x];
			x = st[x];
			y = st[y];
			if(level[x] > level[y]){
				swap(x, y);
			}
			for(int k=20; k>=0; --k){
				if(level[x] > level[dp[k][y]]){
					continue;
				}
				y = dp[k][y];
			}
			if(x == y){
				cout << level[x] << "\n";
				continue;
			}
			for(int k=20; k>=0; --k){
				if(dp[k][x] != dp[k][y]){
					x = dp[k][x];
					y = dp[k][y];
				}
			}
			cout << level[dp[0][x]] << "\n";
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
	}
	return 0;
}
