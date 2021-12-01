/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi9_wizards
 * ALGO		: Hash
 * DATE		: 30 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MOD = 5000011;

const int MxN = 1550;
int x[5][MxN], y[5][MxN];

struct HSH{
	int table[5000011];
	pair<int, int> keep[5000011];
	void insert(int val_x, int val_y, int i, int j){
		int k = (MOD + (val_x + (5 * val_y) % MOD) % MOD) % MOD;
		while(table[k] != 0){
			k++;
			k %= MOD;
		}
		table[k] = (1500 * i) + j + 1;
		keep[k] = make_pair(val_x, val_y);
	}
	void read(int val_x, int val_y, int i, int j){
		int k = (MOD + (val_x + (5 * val_y) % MOD) % MOD) % MOD;
		while(table[k] != 0){
			if(keep[k] == make_pair(val_x, val_y)){
				int p = table[k] - 1;
				cout << x[0][p / 1500] << " " << y[0][p / 1500] << "\n";
				cout << x[1][p % 1500] << " " << y[1][p % 1500] << "\n";
				cout << x[2][i] << " " << y[2][i] << "\n";
				cout << x[3][j] << " " << y[3][j] << "\n";
				exit(0);
			}
			k = (k + 1) % MOD;
		}
	}
} mp;

void solve(){
	int xt, yt, n;
	cin >> xt >> yt >> n;
	for(int k=0; k<4; ++k){
		for(int i=0; i<n; ++i){
			cin >> x[k][i] >> y[k][i];
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			int sum_x = x[0][i] + x[1][j];
			int sum_y = y[0][i] + y[1][j];
			mp.insert(sum_x, sum_y, i, j);	
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			int sum_x = xt - (x[2][i] + x[3][j]);
			int sum_y = yt - (y[2][i] + y[3][j]);
			mp.read(sum_x, sum_y, i, j);
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
	}
	return 0;
}
