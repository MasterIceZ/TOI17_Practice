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

struct Line{
	ll l, r;
	bool operator < (const Line& o) const{
		return r < o.r;
	}
};

void solve(){
	int n;
	ll L, l, r;
	cin >> n >> L;
	vector<Line> line;
	for(int i=1; i<=n; ++i){
		cin >> l >> r;
		line.push_back({l, r});
	}
	sort(line.begin(), line.end());
	ll curr = -1, cnt = 0;
	for(auto x: line){
		if(x.l > curr){
			cnt++;
			curr = x.r;
		}
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
