/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi10_monkey
 * ALGO		: Brute Force
 * DATE		: 30 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct OPR{
	int idx, hei;
	bool operator < (const OPR& o) const{
		if(hei != o.hei){
			return hei > o.hei;
		}
		return idx < o.idx;
	}
};

int a[200200];
int edp[200200];

void solve(){
	int m, n, k, p;
	cin >> m >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		edp[i] = i;
	}
	vector<OPR> v;
	for(int i=1, x, y; i<=k; ++i){
		cin >> x >> y;
		v.push_back({x, y});	
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		swap(edp[x.idx], edp[x.idx + 1]);
	}
	cin >> p;
	cout << a[edp[p]] << "\nNO";
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
