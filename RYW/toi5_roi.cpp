/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi5_roi
 * ALGO		: Brute Force
 * DATE		: 17 Nov 2021
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
	double n, ptf= 1e18;
	int books, price;
	cin >> n;
	for(int j=74; j<=144; ++j){
		for(int i=1000; i<=15000; i+=500){
			double cur_book = 100 - (i - 1000) /  500;
			double sold = ((100 - (0.8569 * exp(0.09 * (j - 100)))) * i) / 100;
			double cst = n + cur_book * i;
			double inc = sold * j;
			double prof = inc - cst;
			if(prof > 0 && ptf > prof){
				ptf = prof;
				books = i;
				price = j;
				dbg(i, j, ptf);
			}
		}
	}
	cout << books << "\n" << price << "\n" << fixed << setprecision(2) << ptf;
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
