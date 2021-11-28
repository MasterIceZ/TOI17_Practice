/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

struct EVP{
	ll idx;
	int color, type;
	bool operator < (const EVP& o) const{
		if(idx != o.idx){
			return idx < o.idx;
		}
		return type > o.type;
	}
};

ll x;

void solve(){
	ll n;
	int m, k;
	cin >> n >> m >> k;
	vector<EVP> line;
	line.push_back({1ll, 0, 0});
	vector<ll> v;
	v.push_back(1);
	for(int i=1; i<=m; ++i){
		cin >> x;
		line.push_back({x, i % 2, 0});
		dbg(x);
		v.push_back(x);
	}
	if(v.back() != n){
//		line.push_back({n, v.size() % 2, 0});
		v.push_back(n);
		line.push_back({n, v.size() % 2, 0});
//		line.push_back({n, v.size() % 2, 0});
	}
//	line.push_back({n, v.size() % 2, 0});
	for(int i=1, c; i<=k; ++i){
		cin >> x >> c;
		int idx = upper_bound(v.begin(), v.end(), x) - v.begin();
		dbg(!(idx % 2) ? "White": "Black");
		line.push_back({x, idx % 2, 0});
		line.push_back({x + 1, !c, 1});
		dbg(x + 1, (int)!c);
	}
	sort(line.begin(), line.end());
	ll last = 0, cnt = 0;
	for(auto x: line){
		dbg(x.idx, x.color, x.type);
		if(last != x.color){
			cnt += 1;
		}
		last = x.color;
	}
	cout << cnt;
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
