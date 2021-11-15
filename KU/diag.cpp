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

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	vector<int> mx, my;
	for(int i=1, x, y; i<=n; ++i){
		cin >> x >> y;
		mx.push_back(x);
		my.push_back(y);
		v.emplace_back(x, y);
	}
	sort(all(mx));
	sort(all(my));
	int medx = mx[n / 2 - 1];
	int medy = my[n / 2 - 1];
	int ans = 0;
	for(auto x: v){
		ans += max(abs(medx - x.first), abs(medy - x.second));
	}
	cout << ans * 2;
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
