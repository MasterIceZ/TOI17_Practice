/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Minor Sequence
 * ALGO		: Fenwick Tree
 * DATE		: 2 Nov 2021
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

ll x;

const int MOD = 1e9 + 7;

struct BIT{
	ll tree[1000100];
	void clear(){
		memset(tree, 0, sizeof tree);
	}
	void update(ll idx, ll val){
		for(; idx<=1000000; idx+=idx&-idx){
			tree[idx] += val;
			tree[idx] %= MOD;
		}
	}
	ll read(ll idx){
		ll res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
			res %= MOD;
		}
		return res;
	}
};

BIT fw;

void solve(){
	fw.clear();
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> x;
		ll tmp = fw.read(x) * (x - 1) + x + fw.read(x - 1);
		tmp = (tmp + MOD) % MOD;
		fw.update(x, tmp);
	}
	cout << fw.read(1000000);
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
