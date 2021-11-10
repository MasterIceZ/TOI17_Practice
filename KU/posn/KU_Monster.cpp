/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Monster
 * ALGO		: Binary Search
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

int v[111];

void solve(){
	int n, h;
	cin >> n >> h;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	sort(v + 1, v + n + 1);
	for(int i=1; i<=n; ++i){
		if(v[i] > h){
			cout << v[i - 1];
			return ;
		}
	}
	cout << v[n - 1];
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
