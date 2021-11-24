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

const int MxN = 100100;
const int LG = 400;

int a[MxN], cluster[LG];

void solve(){
	char o;
	int n, q, idx, x, l, r;
	cin >> n >> q;
	int sq = sqrt(n);
	while(q--){
		cin >> o;
		if(o == 'U'){
			cin >> idx >> x;
			
		}
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
