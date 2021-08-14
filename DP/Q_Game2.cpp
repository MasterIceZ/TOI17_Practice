/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Q_Game2
 * ALGO		: Dynamic Programming
 * DATE		: 12 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[222][222];
int dpmn[222][222], dpmx[222][222];

void solve(){
	int r, c;
	cin >> r >> c;
	int score = 0;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> a[i][j];
		}
	}
	memset(dpmn, 0x3f, sizeof dpmn);
	dpmn[r][0] = 0;
	for(int i=r; i>=1; --i){
		for(int j=1; j<=c; ++j){
			dpmx[i][j] = a[i][j] + max(dpmx[i + 1][j], dpmx[i][j - 1]);
			dpmn[i][j] = a[i][j] + min(dpmn[i + 1][j], dpmn[i][j - 1]);
		}
	}
	cout << dpmx[1][c] - dpmn[1][c];
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
