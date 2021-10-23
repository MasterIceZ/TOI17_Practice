/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_SafeSquare
 * ALGO		: Data Structure
 * DATE		: 23 Oct 2021
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

const int MOD = 25621;

void solve(){
	unordered_map<int, int> x, y;
	int n, m, q;
	cin >> n >> m >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		x[a] = 1, y[b] = 1;
	}
	cout << ((n - x.size()) % MOD * (m - y.size()) % MOD) % MOD;
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
