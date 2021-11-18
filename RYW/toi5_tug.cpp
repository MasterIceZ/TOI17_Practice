/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi5_tug
 * ALGO		: Greedy
 * DATE		: 17 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int n;
	cin >> n;
	vector<ll> v(n), w(n);
	for(auto& x: v){
		cin >> x;
	}
	for(auto& x: w){
		cin >> x;
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	ll sum = 0;
	for(int i=0; i<n; ++i){
		sum += abs(v[i] - w[i]);
	}
	cout << sum;
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
