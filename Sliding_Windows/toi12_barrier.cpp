/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_barrier
 * ALGO		: Sliding Windows, Dynamic Programming
 * DATE		: 21 Nov 2021
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

struct Node{
	ll val;
	int idx;
};

const int MxN = 6000100;
ll qs[MxN], ans = 0;

void solve(){
	int n, k, sz = 1e9;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> qs[i];
		qs[i] += qs[i - 1];
	}
	deque<Node> dq;
	dq.push_back({0, 0});
	for(int i=1; i<=n; ++i){
		// delete first
		while(!dq.empty() && i - dq.front().idx > k){
			dq.pop_front();
		}
		// delete back which more than ``qs[i]``
		while(!dq.empty() && dq.back().val >= qs[i]){
			dq.pop_back();
		}
		dq.push_back({qs[i], i});
		if(qs[i] - dq.front().val > ans){
			ans = qs[i] - dq.front().val;
			sz = i - dq.front().idx;
		}
		else if(qs[i] - dq.front().val == ans){
			sz = min(sz, i - dq.front().idx);
		}
	}
	cout << ans << "\n" << (sz  == 1e9 ? 0: sz);
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
