/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Good
 * ALGO		: Range Maximum Query
 * DATE		: 22 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;
int rmq[22][MxN];

void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=0; i<n; ++i){
		cin >> rmq[0][i];
	}
	int lg = log2(n);
	for(int i=1; i<=lg; ++i){
		for(int j=0; j+(1 << i)-1<n; ++j){
			rmq[i][j] = max(rmq[i-1][j], rmq[i-1][j+(1 << (i - 1))]);
		}
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		int k = log2(r - l + 1);
		cout << max(rmq[k][l], rmq[k][r - (1 << k) + 1]) << "\n";
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
