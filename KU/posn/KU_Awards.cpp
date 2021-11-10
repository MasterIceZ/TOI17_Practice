/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Awards
 * ALGO		: Dynamic Programming
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

int qs[3][333], qsz[3][333];
bitset<666> have;

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> qs[0][i];
		have[qs[0][i]] = true;
		qsz[0][i] = qsz[0][i - 1] + !(qs[0][i]);
		qs[0][i] += qs[0][i - 1];
	}
	for(int i=1; i<=n; ++i){
		cin >> qs[1][i];
		have[qs[1][i]] = true;
		qsz[1][i] = qsz[1][i - 1] + !(qs[1][i]);
		qs[1][i] += qs[1][i - 1];
	}
	vector<int> dp = {0};
	for(int i=2*n; i>=1; --i){
		if(!have[i]){
			dp.push_back(dp.back() + i);
		}
	}
	int res = 0;
	for(int i=1; i<=n; ++i){
		res = max(qs[0][i] + qs[1][n] - qs[1][i - 1] + dp[qsz[0][i] + qsz[1][n] - qsz[1][i - 1]], res);
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
		cout << endl;
	}
	return 0;
}
