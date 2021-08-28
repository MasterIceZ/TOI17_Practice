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

int v[777][777], w[777][777];

int dp11[777][777];

void solve(){
	memset(v, 0, sizeof v);
	cin >> r >> c;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> v[i][j];
			w[i][j] = v[i][j];
		}
	}
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			dp[
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
