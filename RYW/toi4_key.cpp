/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi4_key
 * ALGO		: Implementation
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

void solve(){
	int n, m;
	cin >> n >> m;
	string a, b, c, res = "";
	cin >> a >> b >> c;
	for(int i=0; i<m; ++i){
		string tmp = string(1, c[i]);
		for(int j=0; j<n; ++j){
			tmp += a[j];
			tmp += b[j];
			sort(tmp.begin(), tmp.end());
			tmp = string(1, tmp[1]);
		}
		res += tmp;
	}
	cout << res;
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
