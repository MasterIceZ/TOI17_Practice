/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_GravityGame
 * ALGO		: Sorting
 * DATE		: 10 Nov 2021
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

int a[111][111], b[111];

void solve(){
	int n;
	char x;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> x;
			b[j] = (x == '#');
		}
		sort(b + 1, b + n + 1, greater<int> ());
		for(int j=1; j<=n; ++j){
			a[i][j] = b[j];
		}
	}
	for(int j=1; j<=n; ++j){
		for(int i=1; i<=n; ++i){
			b[i] = a[i][j];
		}
		sort(b + 1, b + n + 1);
		for(int i=1; i<=n; ++i){
			a[i][j] = b[i];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cout << (a[i][j] ? "#" : ".");
		}
		cout << "\n";
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
