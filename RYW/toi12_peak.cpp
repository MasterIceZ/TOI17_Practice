/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_peak
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

const int MxN = 5000050;
int a[MxN];

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	vector<int> v, w;
	for(int i=1; i<=n; ++i){
		if(a[i - 1] < a[i] && a[i] > a[i + 1]){
			v.push_back(a[i]);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	int last = -1;
	for(auto x: v){
		if(x == last){
			continue;
		}
		w.push_back(x);
		if(w.size() == k){
			break;
		}
		last = x;
	}
	if(w.empty()){
		cout << -1 << "\n";
	}
	else{
		if(w.size() < k){
			reverse(w.begin(), w.end());
		}
		for(auto x: w){
			cout << x << "\n";
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
