/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Num Play
 * ALGO		: Math
 * DATE		: 9 Sep 2021
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

ll minn, maxx, med, mean, diff_o, diff_e;

ll calc(ll diff, ll even){
	ll add;
	if(diff >= 0){
		add = mean * 2 - minn - med;
	}
	else{
		add = maxx + med - mean * 2;
		diff = -diff;
	}
	if(add <= 0){
		return 1e18;
	}
	return ((diff + add - 1) / add) * 2 + 3 + even;
}

void solve(){
	cin >> minn >> maxx >> mean >> med;
	if(maxx < minn || minn > mean || mean > maxx  || minn > med || med > maxx){
		cout << "IMPOSSIBLE";
		return ;
	}
	if(minn == maxx && minn == mean && mean == med){
		cout << 1;
		return ;
	}
	if(minn + maxx == 2 * mean && mean == med){
		cout << 2;
		return ;
	}
	diff_o = minn + maxx + med - 3 * mean;
	diff_e = minn + maxx + med * 2 - 4 * mean;
	ll ans = min(calc(diff_o, 0ll), calc(diff_e, 1ll));
	if(ans == 1e18){
		cout << "IMPOSSIBLE";
	}
	else{
		cout << (ans);
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
