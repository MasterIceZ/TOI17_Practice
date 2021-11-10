/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Battery
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

void solve(){
	int n, l, minn = 1e9 + 10;
	cin >> n >> l;
	while(n--){
		int maxx = -1e9, last = 0, x;
		for(int i=1; i<=l; ++i){
			cin >> x;
			maxx = max(maxx, x - last);
			last = x;
		}
		minn = min(maxx, minn);
	}
	cout << minn;
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
