/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi1_chain
 * ALGO		: Implementation
 * DATE		: 26 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int n, m;
	cin >> n >> m;
	string tmp, x, ans;
	cin >> tmp;
	bool ok = false;
	for(int i=2, cnt=0; i<=m; ++i, cnt=0){
		cin >> x;
		for(int j=0; j<n; ++j){
			cnt += (x[j] == tmp[j]);
		}
		if(!ok && cnt < n - 2){
			ok = true;
			ans = tmp;
		}
		tmp = x;
	}
	cout << (ok ? ans : tmp);
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
