/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Alien
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

int ok(int r, int a, int b, int c, int d){
	if((a - c) * (a - c) + (b - d) * (b - d) <= r * r){
		return 1;
	}
	return 0;
}

void solve(){
	int n, cnt = 0, a, b, c, r, d;
	cin >> n >> a >> b >> r;
	while(n--){
		cin >> c >> d;
		cnt += ok(r, a, b, c, d);
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
