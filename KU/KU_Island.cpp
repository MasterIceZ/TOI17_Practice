/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Island
 * ALGO		: Dynamic Programming
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

void solve(){
	int n, k, sum = 0;
	cin >> n >> k;
	bool ok = false;
	vector<int> dp;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		if(x < 0){
			sum += abs(x) + 1;
			ok = true;
		}
		if(x > 0 && ok){
			ok = false;
			dp.push_back(sum);
			sum = 0;
		}
	}
	dp.push_back(sum);
	sort(all(dp));
	int res = 0;
	dbg(dp);
	for(int i=0; 1+i<dp.size()-k; ++i){
		res += dp[i];
	}
	cout << res;
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
