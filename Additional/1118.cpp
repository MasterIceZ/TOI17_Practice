/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Switch
 * ALGO		: Brute Force
 * DATE		: 15 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[22][22], b[22][22];
int n;

bool check(){
	bool ok = true;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			ok &= a[i][j] == b[i][j];
		}
	}
	return ok;
}

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> b[i][j];
		}
	}
	if(check()){
		cout << 0;
		return ;
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
