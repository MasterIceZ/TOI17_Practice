/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Durian Company
 * ALGO		: Sweepline
 * DATE		: 28 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n, l, r;
	cin >> n;
	vector<pair<int, int>> line;
	for(int i=1; i<=n; ++i){
		cin >> l >> r;
		line.emplace_back(l, 1);
		line.emplace_back(r, -1);
	}
	sort(all(line));
	int now = 0, nax = 0;
	for(auto x: line){
		now += x.second;
		nax = max(nax, now);
	}
	cout << nax;
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
