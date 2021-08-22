/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Wizard of TOI
 * ALGO		: Hash Table
 * DATE		: 22 Aug 2021
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

const int Hash = 5000011;
int x[5][1555], y[5][1555];
int table[Hash], mem[5][Hash];

int get_key(int a, int b){
	dbg((a + 2 * b) % Hash);
	return ((a + 3 * b) % Hash + Hash) % Hash;
}

void solve(){
	int xt, yt, n;
	cin >> xt >> yt >> n;
	for(int i=0; i<4; ++i){
		for(int j=0; j<n; ++j){
			cin >> x[i][j] >> y[i][j];
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			int xx = x[0][i] + x[1][j];
			int yy = y[0][i] + y[1][j];
			
			int key = get_key(xx, yy);
			while(table[key]){
				key = (key + 1) % Hash;
				dbg(key);
			}
			table[key] = (i * 1500 + j) + 1;
			mem[0][key] = xx, mem[1][key] = yy;
		}
	}
	for(int lom=0; lom<n; ++lom){
		for(int fire=0; fire<n; ++fire){
			int rx = xt - (x[2][lom] + x[3][fire]);
			int ry = yt - (y[2][lom] + y[3][fire]);
			
			int key = get_key(rx, ry);
			while(table[key]){
				if(mem[0][key] == rx && mem[1][key] == ry){
					int din = (table[key] - 1) / 1500, nam = (table[key] - 1) % 1500;
					cout << x[0][din] << " " << y[0][din] << "\n";
					cout << x[1][nam] << " " << y[1][nam] << "\n";
					cout << x[2][lom] << " " << y[2][lom] << "\n";
					cout << x[3][fire] << " " << y[3][fire];
					return ;
				}
				key = (key + 1) % Hash;
				dbg(key);
			}
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
		cout << endl;
	}
	return 0;
}
