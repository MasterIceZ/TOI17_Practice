/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Electric TOI8
 * ALGO		: Sliding Windows
 * DATE		: 10 Sep 2021
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
	int n, k;
	cin >> n >> k;
	vector<int> v(1 + n), dp(1 + n);
	deque<pair<int, int>> deq;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	deq.emplace_back(v[1], 1);
	for(int i=2; i<=n; ++i){
		while(!deq.empty() && deq.front().second < i - k){
			deq.pop_front();
		}
		dp[i] = deq.front().first + v[i];
		while(!deq.empty() && deq.back().first >= dp[i]){
			deq.pop_back();
		}
		deq.emplace_back(dp[i], i);
	}
	cout << dp[n];
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
