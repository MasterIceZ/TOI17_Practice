/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi1_roman
 * ALGO		: Implementation
 * DATE		: 26 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

int ii, vv, xx, ll, cc;

void conv(int n){
	for(; n>=100; n-=100){
		cc++;
	}
	for(; n>=90; n-=90){
		cc++;
		xx++;
	}
	for(; n>=50; n-=50){
		ll++;
	}
	for(; n>=40; n-=40){
		ll++;
		xx++;
	}
	for(; n>=10; n-=10){
		xx++;
	}
	for(; n>=9; n-=9){
		xx++;
		ii++;
	}
	for(; n>=5; n-=5){
		vv++;
	}
	for(; n>=4; n-=4){
		vv++;
		ii++;
	}
	for(; n; n--){
		ii++;
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		conv(i);
	}
	cout << ii << " " << vv << " " << xx << " " << ll << " " << cc;
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
