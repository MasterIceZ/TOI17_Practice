/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int n;
	cin >> n;
	int res = 0;
	res += (n / 15) * 3000;
	n %= 15;
	for(; n>=9; n-=n){
		res += 3000;
	}
	for(; n>=5; n-=5){
		res += 1500;
	}
	for(; n>=4; n-=4){
		res += 1500;
	}
	for(; n>=2; n-=2){
		res += 800;
	}
	for(; n; n--){
		res += 500;
	}
	cout << res;
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
