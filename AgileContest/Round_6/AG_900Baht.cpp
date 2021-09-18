/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_900 Baht
 * ALGO		: Brute Force
 * DATE		: 18 Sep 2021
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

pair<ll, ll> point[100100];
int n;

void solve(){
	ll x, nin, nax;
	nin = INT_MAX, nax = 0;
	cin >> x;
	for(int i=1; i<=n; ++i){
		ll dx = abs(point[i].first - x) + abs(point[i].second);
		dbg(dx);
		nin = min(nin, dx);
		nax = max(nax, dx);
	}
	cout << nin << " " << nax;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		dbg(i);
		cin >> point[i].first >> point[i].second;
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
