/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pair TOI7
 * ALGO		: Fenwick Tree
 * DATE		: 17 Sep 2021
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

void solve(){
	int n;
	cin >> n;
	vector<pair<ll, ll>> x;
	for(int i=0; i<n; ++i){
		cin >> x[i].second >> x[i].first;
	}
	sort(all(x));
	vector<ll> a;
	for(auto it: x){
		a.push_back(it.second);
	}
	
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
