/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: MinMax
 * ALGO		: Brute Force, Math
 * DATE		: 29 Oct 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

ll a[33][33];

void solve(){
	ll n, b;
	cin >> n >> b;
	ll nax = -1e9, nin = 1e9;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
			nin = min(nin, a[i][j]);
			nax = max(nax, a[i][j]);
		}
	}
	ll ans = nax - nin;
	for(int i=1; i<=n; ++i){ // Row Add
		for(int j=1; j<=n; ++j){ // Row Minus
			if(i == j){
				continue;
			}
			nax = -1e9, nin = 1e9;
			for(int k=1; k<=n; ++k){
				ll pl = a[i][k] + b;
				ll mi = a[j][k] - b;
				nin = min({mi, pl, nin});
				nax = max({mi, pl, nax});
			}
			ans = max(ans, nax - nin);
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
		cout << endl;
	}
	return 0;
}
