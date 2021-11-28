/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

void solve2(){
	int n;
	cin >> n;
	map<double, double> xxx, xx, yyy, yy;
	double x, y, X, Y;
	for(int i=1; i<=n; ++i){
		cin >> X >> Y;
		x = (X - Y) / 2;
		y = (X + Y) / 2;
		if(xxx[x] == 0){
			xxx[x] = y;
		}
		else{
			xxx[x] = min(xxx[x], y);
		}
		if(yyy[y] == 0){
			yyy[y] = x;
		}
		else{
			yyy[y] = min(yyy[y], x);
		}
		xx[x] = max(xx[x], y);
		yy[y] = max(yy[y], x);		
	}
	double ansx = 0, ansy = 0;
	for(auto a: xx){
		ansx = max(a.second - xxx[a.first], ansx);
	}
	for(auto a: yy){
		ansy = max(a.second - yyy[a.first], ansy);
	}
	cout << max(ansx, ansy) ;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
//		solve();
		solve2();
		cout << endl;
	}
	return 0;
}
