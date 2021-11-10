/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Spacefood
 * ALGO		: Implementation
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
	int x, n, m, k, have = 0, cnt = 0;
	bool die = false;
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		cin >> x;
		have += x;
		if(have >= k){
			have -= k;
		}
		else if(have >= m){
			cnt++;
			have = 0;
		}
		else{
			die = true;
		}
	}
	cout << (die ? -1: cnt);
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
