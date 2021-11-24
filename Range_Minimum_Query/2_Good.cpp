/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Good
 * ALGO		: Range Minimum Query
 * DATE		: 23 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;
const int Lg = 22;

struct RMQ{
	int rmq[Lg][MxN];
	void precompute(vector<int> a){
		int n = a.size();
		for(int i=0; i<n; ++i){
			rmq[0][i] = a[i];
		}
		int lg = __lg(n);
		for(int k=1; k<=lg; ++k){
			for(int i=0; i+(1 << k)-1<n; ++i){
				rmq[k][i] = max(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
			}
		}
	}
	int read(int l, int r){
		int k = __lg(r - l + 1);
		return max(rmq[k][l], rmq[k][r - (1 << k) + 1]);
	}
} dp;

void solve(){
	int n, q, l, r;
	cin >> n >> q;
	vector<int> v(n);
	for(auto &x: v){
		cin >> x;
	}
	dp.precompute(v);
	while(q--){
		cin >> l >> r;
		cout << dp.read(l, r) << "\n";
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
