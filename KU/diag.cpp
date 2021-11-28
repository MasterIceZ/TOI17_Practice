/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: diag
 * ALGO		: Math
 * DATE		: 27 Nov 2021
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

const int MxN = 100100;
double x[MxN], y[MxN], Sx[MxN], Sy[MxN], xx, yy;

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> xx >> yy;
		x[i] = (xx - yy) / 2;
		y[i] = (xx + yy) / 2;
	}
	memcpy(Sx, x, sizeof x);
	memcpy(Sy, y, sizeof y);
	sort(Sx + 1, Sx + n + 1);
	sort(Sy + 1, Sy + n + 1);
	double medx, medy;
	if(n % 2){
		medx = Sx[(n + 1) / 2];
		medy = Sy[(n + 1) / 2];
	}
	else{
		medx = (Sx[n / 2] + Sx[(n + 1) / 2]) / 2;
		medy = (Sy[n / 2] + Sy[(n + 1) / 2]) / 2;
	}
	dbg(medx, medy);
	double sum = 0;
	for(int i=1; i<=n; ++i){
		sum += abs(x[i] - medx) + abs(y[i] - medy);
	}
	cout << fixed << setprecision(0) << (sum * 2);
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
