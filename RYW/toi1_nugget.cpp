/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi1_nugget
 * ALGO		: Dynamic Programming
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

int dp[1010];

void solve(){
	int n;
	cin >> n;
	if(n < 6){
		cout << "no\n";
		return ;
	}
	dp[0] = 1;
	for(int i=6; i<=n; ++i){
		if(i - 6 >= 0 && dp[i - 6]){
			dp[i] = 1;
			cout << i << "\n";
		}
		else if(i - 9 >= 0 && dp[i - 9]){
			dp[i] = 1;
			cout << i << "\n";
		}
		else if(i - 20 >= 0 && dp[i - 20]){
			dp[i] = 1;
			cout << i << "\n";
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
