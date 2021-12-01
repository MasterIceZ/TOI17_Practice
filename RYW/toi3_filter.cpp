/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 3030;
int dp[MxN];

void solve(){
	int w, h, n;
	cin >> w >> h >> n;
	for(int i=1, l, r; i<=n; ++i){
		cin >> l >> r;
		dp[l]++;
		if(l + r < w){
			dp[l + r]--;
		}
	}
	for(int i=1; i<w; ++i){
		dp[i] += dp[i - 1];
	}
	int a, b;
	a = b = 0;
	for(int i=0; i<w; ++i){
		if(!dp[i]){
			a++;
		}
		else if(dp[i] == 1){
			b++;
		}
	}
	cout << a * h << " " << b * h;
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
