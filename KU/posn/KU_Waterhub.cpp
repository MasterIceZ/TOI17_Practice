/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Waterhub
 * ALGO		: Brute Force
 * DATE		: 10 Nov 2021
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

int dist(pair<int, int> a, pair<int, int> b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(){
	int n, ans = 1e9 + 10;
	cin >> n;
	vector<pair<int, int>> v(n + 1);
	for(int i=1; i<=n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			int now = 0;
			for(int k=1; k<=n; ++k){
				if(i == k || j == k){
					continue;
				}
				now += min(dist(v[i], v[k]), dist(v[j], v[k]));
			}
			ans = min(now, ans);
		}
	}
	cout << ans;
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
