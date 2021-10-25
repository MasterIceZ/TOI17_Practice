/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Ski
 * ALGO		: Loops
 * DATE		: 23 Oct 2021
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

int n, m;

void solve(){
	int opr, now = n;
	bool out = false;
	for(int i=1; i<=m; ++i){
		cin >> opr;
		if(out){
			continue;
		}
		now += (opr ? 1 : -1);
		if(now < 0 || now > 2 * n){
			out = true;
		}
	}
	cout << (out ? "0": "1");
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> n >> m >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
