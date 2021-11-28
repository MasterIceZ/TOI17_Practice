/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi11_labor
 * ALGO		: Binary Search
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

const int MxN = 1000100;
int a[MxN];

void solve(){
	int n;
	ll m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll l = 1, r = 1e18;
	while(l < r){
		ll mid = (l + r) >> 1;
		ll cur = 0;
		for(int i=1; i<=n; ++i){
			cur += mid / a[i];
		}
		if(cur >= m){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l ;
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
