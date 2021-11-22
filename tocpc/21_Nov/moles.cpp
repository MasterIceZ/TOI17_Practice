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

struct Mole{
	int u, t;
	bool operator < (const Mole& o) const{
		if(u != o.u){
			return u < o.u;
		}
		return t < o.t;
	}
};

const int MxN = 100100;
//Mole a[MxN], b;
int dp[MxN];
int a[MxN];

void solve(){
	int n, s, x, y;
	cin >> n >> s;
	for(int i=1; i<=n; ++i){
		cin >> x >> y;
		a[i] = max(y, x-s);	
	}
	int sz = 0;
	for(int i=1; i<=n; ++i){
		int idx = upper_bound(dp, dp + sz, a[i]) - dp;
		sz += (idx == sz);
		dp[idx] = a[i];
	}
	cout << sz;
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
