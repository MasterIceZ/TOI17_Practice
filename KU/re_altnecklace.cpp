/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: altnecklace
 * ALGO		: Sweepline
 * DATE		: 27 Nov 2021
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
		return type < o.type;
	}
};

void solve(){
	ll n, x, cnt = 0;
	int m, k, c;
	cin >> n >> m >> k;
	vector<EVP> line;
	vector<ll> point;
	line.push_back({1, 1, 0});
	for(int i=1; i<=m; ++i){
		cin >> x;
		line.push_back({x, (i + 1) % 2, 0});
		point.push_back(x);
	}
	line.push_back({n, (int)(point.size() + 1) % 2, 0});
	for(int i=1; i<=k; ++i){
		cin >> x >> c;
		int idx = upper_bound(point.begin(), point.end(), x) - point.begin();
		int idx2 = upper_bound(point.begin(), point.end(), x + 1) - point.begin();
		line.push_back({x, !(idx % 2), 0});
		line.push_back({x, c, 1});
		if(x + 1 <= n){
			line.push_back({x + 1, !(idx2 % 2), -1}); 
		}
	}
	sort(line.begin(), line.end());
	int last = 1;
	for(auto x: line){
		dbg(x.idx, x.color, x.type);
		if(last != x.color){
			cnt++;
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
