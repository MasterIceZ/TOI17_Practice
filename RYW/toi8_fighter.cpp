/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi8_fighter
 * ALGO		: Math
 * DATE		: 15 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int player[3], combo[3];

void solve(){
	int x, life, win, edp;
	bool ok = true;
	cin >> life;
	player[1] = player[0] = life;
	for(int i=1; i<=2 * life; ++i){
		cin >> x;
		if(!ok){
			continue;
		}
		int atk = x % 2;
		int def = !atk;
		combo[atk]++;
		combo[def] = 0;
		player[def] -= combo[atk] >= 3 ? 3 : 1;
		if(player[def] <= 0){
			win = atk;
			ok = false;
			edp = x;
		}
	}
	cout << win << "\n" << edp ;
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
