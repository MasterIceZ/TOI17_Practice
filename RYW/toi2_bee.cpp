/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi2_bee
 * ALGO		: Dynamic Programming
 * DATE		: 28 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

pair<int, int> rec(int state){
	if(state == 0){
		return {1, 0};
	}
	auto x = rec(state - 1);
	int curx = x.first + 1 + x.second;
	int cury = x.first;
	return {curx, cury};
}

void solve(){
	while(1){
		int x;
		cin >> x;
		if(x == -1){
			return ;
		}
		auto res = rec(x);
		cout << res.first << " " << res.first + res.second + 1 << "\n";
	}
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
