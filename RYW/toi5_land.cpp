/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi5_land
 * ALGO		: Brute Force
 * DATE		: 25 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int n, m;
double minn = 1e9 + 10;

const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void rec(int i, int j, int cnt, double price, vector<vector<double>> a){
	if(cnt == n * m){
		minn = min(minn, price);
		return ;
	}
	auto nxt = a;
	for(int k=0; k<8; ++k){
		int ii = di[k] + i;
		int jj = dj[k] + j;
		if(ii < 1 || jj < 1 || ii > n || jj > m || !nxt[ii][jj]){
			continue;
		}
		nxt[ii][jj] += 0.1 * nxt[i][j];
	}
	nxt[i][j] = 0;
	for(int ii=1; ii<=n; ++ii){
		for(int jj=1; jj<=m; ++jj){
			if(nxt[ii][jj] != 0){
				rec(ii, jj, cnt + 1, price + nxt[ii][jj], nxt);
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	vector<vector<double>> a(n + 1, vector<double> (m + 1));
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			rec(i, j, 1, a[i][j], a);
		}
	}
	cout << fixed << setprecision(2) << minn ;
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
