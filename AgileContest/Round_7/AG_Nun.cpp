/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Nun
 * ALGO		: Dynamic Programming + Two-Pointers
 * DATE		: 9 Oct 2021
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

const int MxN = 1e5 + 10;
int dp[MxN];
ll qs[MxN];

void solve(){
	int l, r;
	cin >> l >> r;
	cout << (dp[r] >= l ? "Yes": "No");
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q = 1;
	ll m;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		ll val;
		cin >> val;
		qs[i] = qs[i - 1] + val;
	}
	int j = 1;
	for(int i=1; i<=n; ++i){
		while(j <= i && qs[i] - qs[j - 1] > m){
			j += 1;
		}
		while(j <= i && qs[i] - qs[j] == m){
			j += 1;
		}
		if(qs[i] - qs[j - 1] == m){
			dp[i] = j;
		}
		else{
			dp[i] = dp[i - 1];
		}
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
